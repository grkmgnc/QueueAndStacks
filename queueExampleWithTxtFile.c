#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

int flag1 = 0;
int flag2 = 0;
int dizi[20];
int front1, front2, rear1, rear2;
front1 = -1;
front2 = 9;
rear1 = -1;
rear2 = 9;
typedef struct
{
    char string[MAX_SIZE];
} input;

int deque1()
{
    if (front1 > -1) // If an element has been added to FIRST Queue already, this condition runs.
    {
        if (front1 == rear1 + 1)
            isEmpty("FIRST");
        else
        {
            if (rear1 - front1 == 0) // If this condition runs; it means that after that delete, Queue FIRST will be empty.
            {
                printf("%d is deleted from queue FIRST\n", dizi[front1]);
                flag1 = 1;
                int temp;
                temp = front1;
                front1 = (front1 + 1) % 20;
                return dizi[temp];
            }
            else
            {
                printf("%d is deleted from queue FIRST\n", dizi[front1]);
                int temp;
                temp = front1;
                front1 = (front1 + 1) % 20;
                return dizi[temp];
            }
        }
    }
    else // If the FIRST Queue is empty, this condition runs.
        isEmpty("FIRST");
}
int deque2()
{
    if (front2 > -1) // If an element has been added to SECOND Queue already, this condition runs.
    {
        if (front2 == rear2 + 1)
        {
            isEmpty("SECOND");
        }

        else
        {
            if (rear2 - front2 == 0) // If this condition runs; it means that after that delete, Queue SECOND will be empty.
            {
                printf("%d is deleted from queue SECOND\n", dizi[front2]);
                flag2 = 1;
                int temp;
                temp = front2;
                front2 = (front2 + 1) % 20;
                return dizi[temp];
            }

            else
            {
                printf("%d is deleted from queue SECOND\n", dizi[front2]);
                // there won't be " flag2 = 1 " equation in this condition

                int temp;
                temp = front2;
                front2 = (front2 + 1) % 20;
                return dizi[temp];
            }
        }
    }
    else
        isEmpty("SECOND"); // If the SECOND Queue is empty, this condition runs.
}

void enque1(int deger)
{
    if (flag1 == 1) // If flag1=1, Queue FIRST is empty before this enque function.
    {
        rear1 = (rear1 + 1) % 20;
        flag1 = 0;
        dizi[rear1] = deger;
        printf("%d is inserted to queue FIRST\n", deger);
    }
    else
    {
        rear1 = (rear1 + 1) % 20;
        if (front1 == rear1 || rear1 == front2 - 1) // Second condition of this if block supply to not reach SECOND Queue.
        {
            isFull("FIRST");
            rear1 = (rear1 - 1) % 20; // rear1 takes its old value because we couldn't added an item to our queue.
        }
        else
        {
            dizi[rear1] = deger;
            printf("%d is inserted to queue FIRST\n", deger);
            if (front1 == -1)
                ++front1;
        }
    }
}
void enque2(int deger)
{
    if (flag2 == 1) // If flag2=1, Queue SECOND is empty before this enque function.
    {
        rear2 = (rear2 + 1) % 20;
        flag2 = 0;
        dizi[rear2] = deger;
        printf("%d is inserted to queue SECOND\n", deger);
    }
    else
    {
        rear2 = (rear2 + 1) % 20;
        if (front2 == rear2 || rear2 == front1 - 1) // Second condition of this if block supply to not reach FIRST Queue.
        {
            isFull("SECOND");
            rear2 = (rear2 - 1) % 20; // rear2 takes its old value because we couldn't added an item to our queue.
        }
        else
        {
            dizi[rear2] = deger;
            printf("%d is inserted to queue SECOND\n", deger);
            if (front2 == 9)
                ++front2;
        }
    }
}
void print1()
{
    if ((rear1 + 1) % 20 < front1) // This if block controls if the FIRST Queue has gone back to the beginning.
    {
        int size = 20 - front1 + ((rear1 + 1) % 20);
        printf("QUEUE: FIRST   FRONT:%d  REAR:%d  SIZE:%d\n", front1, (rear1 + 1) % 20, size);

        if (size == 0)
            printf("NO_CONTENT");
        else
        {
            for (int i = front1; i < 20; i++)
            {
                printf("%d ", dizi[i]);
            }
            for (int i = 0; i < (rear1 + 1) % 20; i++)
            {
                printf("%d ", dizi[i]);
            }
        }
        printf("\n");
    }
    else
    {
        if (front1 > -1) // If a value has been added to FIRST Queue any time, this condition runs.
        {
            printf("QUEUE: FIRST    FRONT:%d  REAR:%d  SIZE:%d\n", front1, rear1 + 1, rear1 + 1 - front1);
            if (front1 == rear1 + 1)
                printf("NO_CONTENT");
            else
            {
                for (int i = front1; i < rear1 + 1; i++)
                {
                    printf("%d ", dizi[i]);
                }
            }
        }
        else
        {
            printf("QUEUE: FIRST    FRONT:%d  REAR:%d  SIZE:%d\n", front1 + 1, rear1 + 1, rear1 - front1);
            printf("NO_CONTENT");
        }

        printf("\n");
    }
}
void print2()
{
    if ((rear2 + 1) % 20 < front2) // This if block controls if the rear2 has reached to index 0;
    {
        int size = 20 - front2 + (rear2 + 1) % 20;
        printf("QUEUE: SECOND   FRONT:%d  REAR:%d  SIZE:%d\n", front2, (rear2 + 1) % 20, size);
        if (size == 0)
            printf("NO_CONTENT");
        else
        {
            for (int i = front2; i < 20; i++)
            {
                printf("%d ", dizi[i]);
            }
            for (int i = 0; i < (rear2 + 1) % 20; i++)
            {
                printf("%d ", dizi[i]);
            }
        }
        printf("\n");
    }

    else
    {
        if (front2 > 9) // If a value has been added to SECOND Queue any time, this condition runs.
        {
            printf("QUEUE: SECOND    FRONT:%d  REAR:%d  SIZE:%d\n", front2, rear2 + 1, rear2 + 1 - front2);
            if (front2 == rear2 + 1)
                printf("NO_CONTENT");
            else
            {
                for (int i = front2; i < rear2 + 1; i++)
                {
                    printf("%d ", dizi[i]);
                }
            }
        }
        else
        {
            printf("QUEUE: SECOND    FRONT:%d  REAR:%d  SIZE:%d\n", front2 + 1, rear2 + 1, rear2 - front2);
            if (rear2 - front2 == 0)
                printf("NO_CONTENT");
        }
        printf("\n");
    }
}
void isFull(char a[])
{
    printf("Queue %s is full.\n", a);
}
void isEmpty(char b[])
{
    printf("Queue %s is empty.\n", b);
}
int main()
{
    FILE *fp = fopen("input.txt", "r");
    int i = 0;
    input inputStr[MAX_SIZE];
    while (!feof(fp))
    {
        fscanf(fp, "%s", inputStr[i].string);

        if (strcmp(inputStr[i].string, "DEQUEUE") == 0)
        {
            // printf("%s ",inputStr[i].string);
            i++;
            fscanf(fp, "%s", inputStr[i].string);
            if (strcmp(inputStr[i].string, "FIRST") == 0)
            {
                // printf("%s ",inputStr[i].string);
                deque1();
            }
            else if (strcmp(inputStr[i].string, "SECOND") == 0)
            {
                // printf("%s ",inputStr[i].string);
                deque2();
            }
            i++;
        }
        else if (strcmp(inputStr[i].string, "ENQUEUE") == 0) // I'm going to use atoi() function to convert our value of the "Enqueue" command to integer value.
        {
            // printf("%s ",inputStr[i].string);
            i++;
            fscanf(fp, "%s", inputStr[i].string);
            if (strcmp(inputStr[i].string, "FIRST") == 0)
            {
                // printf("%s ",inputStr[i].string);
                i++;
                input charSayi[1];
                fscanf(fp, "%s", inputStr[i].string);
                charSayi[0] = inputStr[i];
                int sayi = atoi(charSayi->string);
                // printf("%s ",inputStr[i].string);
                // printf("%d ", sayi);
                enque1(sayi);
            }
            else if (strcmp(inputStr[i].string, "SECOND") == 0)
            {
                // printf("%s ",inputStr[i].string);
                i++;
                input charSayi[1];
                fscanf(fp, "%s", inputStr[i].string);
                charSayi[0] = inputStr[i];
                int sayi = atoi(charSayi->string);
                // printf("%s ",inputStr[i].string);
                enque2(sayi);
            }
            i++;
        }
        else if (strcmp(inputStr[i].string, "PRINT") == 0)
        {
            // printf("%s ",inputStr[i].string);
            i++;
            fscanf(fp, "%s", inputStr[i].string);
            if (strcmp(inputStr[i].string, "FIRST") == 0)
            {
                // printf("%s ",inputStr[i].string);
                print1();
            }
            else if (strcmp(inputStr[i].string, "SECOND") == 0)
            {
                // printf("%s ",inputStr[i].string);
                print2();
            }
            i++;
        }
    }

    return 0;
}