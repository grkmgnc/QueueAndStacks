// removing the maximum value of the stack
#include <stdio.h>
#define MAX_SIZE 20
int stack[MAX_SIZE];
int top = -1;
int pop()
{
    if (top == -1) // stack is empty
        return -1;

    else
        return stack[top--];
}
void push(int value)
{
    if (top == MAX_SIZE - 1) // stack is full
        return;
    else
        stack[++top] = value;
}
void doldur(int *stack)
{

    int j = 25;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        push(j);
        j--;
    }
}
void print_stack(int *stack)
{
    int i = 0;
    while (i <= top)
    {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");
}
int remove_Max(int *stack)
{
    int max, maxIndex;
    int temp[MAX_SIZE];
    max = stack[0];
    maxIndex = 0;

    for (int i = 1; i <= top; i++)
    {
        if (max < stack[i])
        {
            max = stack[i];
            maxIndex = i;
        }
    }
    int j = 0;
    for (int i = top; i >= maxIndex; i--)
    {

        if (i > maxIndex)
        {
            temp[j] = pop();
            j++;
        }
        else
            pop();
    }
    if (top != maxIndex)
    {
        for (int i = j - 1; i >= 0; i--)
        {

            push(temp[i]);
        }
    }
    return max;
}
int main()
{
    doldur(stack);
    print_stack(stack);
    remove_Max(stack);
    printf("%d\n", top);
    print_stack(stack);
    return 0;
}