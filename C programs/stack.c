#include <stdio.h>
int isfull(int *top, int cap)
{

    if (*top>=cap)
    {
        return 0;
    }
    else
        return 1;
}

int isempty(int *top)
{
    if (*top>-1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int stack[5],int *top)
{
    int elem;
    (*top)++;
    printf("Enter the element:");
    scanf("%d",&elem);
    stack[*top]=elem;
    printf("\n");

}

void pop (int stack[5], int *top)
{
    printf("\nElement to be popped is=%d",stack[*top]);
    (*top)--;
    printf("\n");
}

void display(int stack[5],int top)
{
    int p,cap=5;
    printf("Display contents of stack\n\n");
    for (p=cap-1;p>=0;p--)
    {
        printf("\n%4d",stack[p]);
        if (p==top)
            printf("%10d",top);
    }
}

void main()
{
    int stack[5]={45,67,84},n,elem,c,top=2,cap=5,empty,full;
    display(stack,top);
    printf("\n");
    printf("\nEnter choice: 1.Push 2.Pop 3.Exit: ");
    scanf("%d",&c);
    while (c==1||c==2)
    {
        if (c==1)
        {
            if (isfull(&top,cap))
            {
                push(stack,&top);
                display(stack,top);
            }
            else
            {
                printf("Stack Full");
            }

        }
        else if (c==2)
        {
            if (isempty(&top))
            {
                pop(stack,&top);
                display(stack,top);
            }
            else
                printf("Stack Empty");
        }

        printf("\nEnter choice: 1.Push 2.Pop 3.Exit: ");
        scanf("%d",&c);
    }

}

