#include<stdio.h>
#define cap 4

int isfull(int *top)
{
    if (*top>=cap)
        return 0;
    }
    else
    {
        return 1;
    }
}

int isempty(int *top)
{
    if (*top>-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int display(int stack[5],int top)
{
    int p;
    printf("\nThe stack is now : ");
    for(p=cap;p>-1;p--)
    {
        if(p==top)
        {
            printf("\n%4d",top+1);
        }
        else
        {
            printf("\n    ");
        }
        printf("%4d",stack[p]);
    }
    return 0;
}

int push(int stack[5],int *top)
{
    int elem;
    printf("\nEnter element to insert : ");
    scanf("%d",&elem);
    (*top)++;
    stack[*top]=elem;
    return 0;
}

int pop(int stack[5],int *top)
{
    int elem;
    printf("\nPOP!!!!");
    elem=stack[(*top)];
    (*top)--;
    return elem;
}

int main()
{
    int stack[5]={22,5,48,31},top=3,elem,p,ch;
    display(stack,top);
    printf("\n 1.Push 2.Pop 0.Exit");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);
    while(ch==1||ch==2)
    {
        if(ch==1)
        {
            if(isfull(&top))
            {
                push(stack,&top);
                display(stack,top);
            }
            else
            {
                printf("Stack is full, can't push!!!");
            }
        }
        if(ch==2)
        {
            if(isempty(&top))
            {
                elem=pop(stack,&top);
                printf("\nPopped element is %d",elem);
                display(stack,top);
            }
            else
            {
                printf("\nStack is empty, can't pop!!!");
            }
        }
        printf("\n 1.Push 2.Pop 0.Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);
    }
    return 0;
}
