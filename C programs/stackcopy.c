#include <stdio.h>

void push(int stack[5],int *top)
{
    int elem,cap=5;
    if (*top<cap)
    {
        (*top)++;
        printf("Enter the element:");
        scanf("%d",&elem);
        stack[*top]=elem;
        printf("\n");
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void display(int stack[5],int *top)
{
    int n;
    printf("Display contents of stack after modification:\n\n");
    for (n=0;n<(*top)+1;n++)
    {
        printf("%4d",stack[n]);
    }
}

void main()
{
    int stack[5],n,elem,top=-1,cap=5;
    printf("Display contents of stack:\n");
    for (n=0;n<top;n++)
    {
        printf("%4d",stack[n]);
    }
    printf("\n");
    push(stack,&top);
    display(stack,&top);
}

