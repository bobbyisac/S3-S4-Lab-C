#include<stdio.h>
#define size 4

int push (int stk[], int *top)
{
    int elem;
    printf("Enter Element to be inserted: ");
    scanf("%d",&elem);
    (*top)++;
    stk[*top]=elem;
    return 0;
}

int pop(int stk[], int *top)
{
    int elem=stk[*top];
    (*top)--;
    return elem;
}

int isfull(int top)
{
    if (top==size-1)
        return 1;
    else
        return 0;
}

int isempty(int top)
{
    if (top==-1)
        return 1;
    else
        return 0;
}

int display(int stk[], int top)
{
    int p;
    printf("\nThe Stack is ");
    printf("\nTOP        VALUE");
    for(p=size-1;p>=0;p--)
    {
        if (p==top)
            printf("\n%d        %d",top,stk[p]);
        else
            printf("\n        %d",stk[p]);
        if (top==-1)
            printf("\n%d",top);
    }
}

int main()
{
    int stk[size],top=-1,ch,elem;
    for(;;)
    {
        printf("\nEnter your choice\n1.Push 2.Pop 3.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            if(isfull(top))
            {
                 printf("\n Stack Overflow!!!");
            }
            else
            {
                push(stk,&top);
                display(stk,top);
            }
        }
        else if(ch==2)
        {
            if(isempty(top))
            {
                printf("\n Stack Underflow!!!");
            }
            else
            {
                elem=pop(stk,&top);
                printf("Popped element is %d",elem);
                display(stk,top);
            }
        }
        else if(ch==3)
            break;
        else
            printf("\nWrong Option Selected");
    }
    return 0;
}
