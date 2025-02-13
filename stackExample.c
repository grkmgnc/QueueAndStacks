#include <stdio.h>
#define MAX_SIZE 101
typedef struct
{
    int VALUE;
} element;
element stack[MAX_SIZE];
int top = -1;
void push(element num)
{
    if (top == MAX_SIZE - 1)
        printf("Stack dolu.\n");
    else
    {

        stack[++top] = num;
    }
}
element pop()
{
    if (top == -1)
        printf("Stack bos.\n");
    else
    {
        return stack[top--];
    }
}

element getTop()
{

    return stack[top];
}
int main()
{
    int a = 0;

    element v;
    while (a != 9)
    {
        printf("1- POP()\n2- PUSH() \n 3-TOP() \n 9- EXIT\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            pop();
            break;
        case 2:
            printf("Eklemek istedigin sayi: ");
            scanf("%d", &v.VALUE);
            push(v);
            break;
        case 3:
            if (top == -1)
            {
                printf("Stack bos.\n");
                break;
            }
            printf("%d\n", getTop().VALUE);
            break;
        case 9:
            break;
        }
    }

    return 0;
}