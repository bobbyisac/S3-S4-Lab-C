#include<stdio.h>
#define size 4

void display(int q[], int f, int r)
{
    int p;
    printf("\nRear=%d\n",r);
    if(f<=r)
    {
        for(p=f;p<=r;p++)
            printf("%8d",q[p]);
    }
    else
    {
        for(p=0;p<=r;p++)
            printf("%8d",q[p]);
        for(p=f;p<size;p++)
            printf("%8d",q[p]);
    }
    printf("\nFront=%d",f);
}

int isfull(int r, int f)
{
    if((r+1)%size==f)
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
    }
    else
    {
        (*r)=((*r+1)%size);
    }
    q[*r]=elem;
}

int deq(int q[], int *f, int *r)
{
    int elem;
    if (*f==*r)
    {
        *f=*r=-1;
    }
    else
    {
        elem=q[*f];
        *f=(*f+1)%size;
    }
    return elem;
}

int main()
{
    int r=-1,f=-1,q[size],in,ch,elem;
    display(q,f,r);
    for(;;)
    {
        printf("\nEnter Choice\n1.Enter 2.Delete 3.Exit : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            if (isfull(r,f))
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
                elem=deq(q,&f,&r);
                printf("\nDeleted Element is %d\n",elem);
                display(q,f,r);
            }
        }
        else
            break;
    }
    return 0;
}
