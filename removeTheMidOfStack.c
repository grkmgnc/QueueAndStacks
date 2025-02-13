// removing the mid item of the stack
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int value;
} stype;

int size_belirle()
{
    printf("Tek sayili stack boyutunu girin: \n");
    int n;
    scanf("%d", &n);
    while (n % 2 == 0)
    {
        printf("Tek sayi girin: \n");
        scanf("%d", &n);
    }
    return n;
}
int pop(int *top, stype *stack)
{
    if (*top == -1) // stack is empty
        return -1;

    else
        return stack[(*top)--].value;
}
void push(int value, int *top, stype *stack, int size)
{
    if (*top == size - 1) // stack is full
        return;
    else
        stack[++(*top)].value = value;
}
void doldur(int *top, stype *stack, int size)
{

    for (int i = 0; i < size; i++)
    {
        push(i, top, stack, size);
    }
}
int ortadakini_cikar(int *top, stype *stack, int size)
{
    int mid;
    mid = size / 2;
    int *stack2 = (int *)malloc(sizeof(int) * (mid + 1));
    int i = 0;

    while (*top >= mid)
    {
        stack2[i] = pop(top, stack);
        i++;
    }
    for (int j = i - 2; j >= 0; j--)
    {
        push(stack2[j], top, stack, size);
    }
    return stack2[i - 1];
}
void print_stack(int *top, stype *stack)
{
    int i = 0;
    while (i <= *top)
    {
        printf("%d ", stack[i].value);
        i++;
    }
    printf("\n");
}
int main()
{
    int size;
    size = size_belirle();
    stype *stack = (stype *)malloc(sizeof(stype) * size);
    int top = -1;
    doldur(&top, stack, size);
    print_stack(&top, stack);
    printf("Ortada olan %d elemani stackten cikarildi\n", ortadakini_cikar(&top, stack, size));
    print_stack(&top, stack);
    return 0;
}