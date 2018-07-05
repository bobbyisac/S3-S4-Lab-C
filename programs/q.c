#include<stdio.h>
#define size 4

void display(int q[], int f, int r)
{
    int p;
    printf("\nRear=%d\n",r);
    for(p=0;p<size;p++)
        printf("%8d",q[p]);
    printf("\nFront=%8d\n",f);
    return 0;
}

int isfull(int r)
{
    if(r==size-1)
        return 1;
    return 0;
}

int isempty(int f)
{
    if (f==-1)
        return 1;
    return 0;
}

void enq(int q[], int *f, int *r)
{
    int elem;
    printf("Enter Element: ");
    scanf("%d",&elem);
    if(*r==-1)
    {
        *f=*r=0;
        q[*r]=elem;
    }
    else
    {
        (*r)++;
        q[*r]=elem;
    }
}

void deq(int q[], int *f, int *r)
{
    if (*f==*r)
    {
        *f=*r=-1;
    }
    else
    {
        printf("Element deleted is %d\n",q[*f]);
        (*f)++;
    }
}

int main()
{
    int r=-1,f=-1,q[size],in,ch,elem;
    display(q,f,r);
    for(;;)
    {
        printf("Enter Choice\n1.Enter 2.Delete 3.Exit : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            if (isfull(r))
            {
                printf("\nQ Full!!!\n");
            }
            else
            {
                enq(q,&f,&r);
                display(q,f,r);
            }
        }
        else if (ch==2)
        {
            if(isempty(f))
            {
                printf("\nQ Empty!!!\n");
            }
            else
            {
                deq(q,&f,&r);
                display(q,f,r);
            }
        }
        else
            break;
    }
    return 0;
}
