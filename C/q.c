#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 4

int display(int q[], int f, int r)
{
    int p;
    clrscr();
    printf("\nRear=%d\n",r);
    for(p=0;p<size;p++)
        printf("%8d",q[p]);
    printf("\nFront=%d\n",f);
    return 0;
}

int isfull(int r)
{
    if (r==size-1)
        return 1;
    else
        return 0;
}

int isempty(int f)
{

    if (f==-1)
        return 1;
    else
        return 0;
}

int enq(int q[], int *f, int *r)
{
    int elem;
    printf("Enter element to be inserted: ");
    scanf("%d",&elem);
    if(*r==-1)
    {
        *r=0;
        *f=0;
    }
    else
        (*r)++;
    q[*r]=elem;
    return 0;
}

int deq(int q[], int *f, int *r)
{
    int elem;
    elem=q[*f];
    if(*f==*r)
    {
        *r=*f=-1;
    }
    else
        (*f)++;
    return elem;
}

int main()
{
    int r=-1,f=-1,q[size],in,elem,ch;
    display(q,f,r);
    for(;;)
    {
        printf("\n1. Add  2. Delete  3. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            if(isfull(r))
            {
                printf("\nQ Full!");
            }
            else
            {
                enq(q,&f,&r);
                display(q,f,r);
            }
        }
        else if(ch==2)
        {
            if(isempty(f))
            {
                printf("\nQ Empty!");
            }
            else
            {
                elem=deq(q,&f,&r);
                printf("\nDeleted Element is %d",elem);
                display(q,f,r);
            }
        }
        else if(ch==3)
            break;
        else
            printf("Wrong Option!!!");
    }
    return 0;
}
