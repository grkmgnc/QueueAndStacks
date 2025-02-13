#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE_QUEUE 20
#define MAX_SIZE_STACK 10
int arrayQueue[MAX_SIZE_QUEUE];
int rear = -1;
int front = -1;

void enqueue(int val)
{
    if (rear == MAX_SIZE_QUEUE - 1)
    {
        printf("queue is full");
        return;
    }
    if (front == -1) // empty
        front = 0;

    arrayQueue[++rear] = val;
    printf("%d kuyruga eklendi.\n", val);
}
int dequeue()
{
    if (front == -1)
    {
        printf("queue is empty");
        return -1;
    }
    int val = arrayQueue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
        ++front;

    return val;
}
void printQueue()
{
    int i = rear + 1;
    int j = 0;

    while (i > 0)
    {
        printf("%d ", arrayQueue[j]);
        j++;
        i--;
    }
}
void isEmpty()
{
    if (front == -1)
    {
        printf("Kuyruk bos.\n");
        return;
    }
    else
    {
        printf("Kuyruk bos degil.\n");
        return;
    }
}
int peakQueue()
{
    if (front == -1)
    {
        printf("Kuyruk bos\n");
        return -1;
    }
    return arrayQueue[front];
}
int stack[MAX_SIZE_STACK];
int top1 = -1;             // İlk stack'in top değeri (Stack soldan sağa)
int top2 = MAX_SIZE_STACK; // İkinci stack'in top değeri (Stack sağdan sola)
void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow (1)\n");
        return;
    }
    stack[++top1] = value;
    printf("%d, birinci stack'e eklendi.\n", value);
}
void push2(int value)
{
    if (top2 - 1 == top1)
    {
        printf("Stack Overflow (2)\n");
        return;
    }
    stack[--top2] = value;
    printf("%d, ikinci stack'e eklendi.\n", value);
}
int pop1()
{
    if (top1 == -1)
    {
        printf("Stack Underflow (1)\n");
        return -1;
    }
    return stack[top1--];
}
int pop2()
{
    if (top2 == MAX_SIZE_STACK)
    {
        printf("Stack Underflow (2)\n");
        return -1;
    }
    return stack[top2++];
}
int peek1()
{
    if (top1 == -1)
    {
        printf("Stack (1) is empty\n");
        return -1;
    }
    return stack[top1];
}
int peek2()
{
    if (top2 == MAX_SIZE_STACK)
    {
        printf("Stack (2) is empty\n");
        return -1;
    }
    return stack[top2];
}
bool isEmpty1()
{
    return top1 == -1;
}
bool isEmpty2()
{
    return top2 == MAX_SIZE_STACK;
}

int main()
{
    enqueue(15);
    enqueue(25);
    enqueue(35);
    printf("%d kuyruktan cikarildi\n", dequeue());
    printf("Kuyrugun onundeki eleman : %d\n", peakQueue());
    isEmpty();
    push1(12);
    push1(22);
    push2(45);
    push2(55);
    printf("%d, birinci stack'ten cikarildi.\n", pop1());
    printf("Ikinci stack'in en ustundeki eleman: %d\n", peek2());
    printf("Ilk stack bos mu?  : %s\n", isEmpty1() ? "Evet" : "Hayir");
    printf("Ikinci stack bos mu?  : %s\n", isEmpty2() ? "Evet" : "Hayir");
    return 0;
}