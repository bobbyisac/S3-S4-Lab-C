#include <stdio.h>

int isfull(int *front, int *rear)
{
    int cap=5;
    if (*rear==cap-1)
        return 1;
    else
        return 0;

}

int isempty(int *front,int *rear)
{
    if (*front == *rear)
    {
        *front=-1;
        *rear=-1;
    }

    if (*front==-1)
        return 1;
    else
        return 0;
}
void add(int queue[5],int *rear,int *front)
{
    int elem, cap=5;
    printf("\nElement:");
    scanf("%d",&elem);
    if (*rear==-1)
    {
        *front=0;
        *rear=0;
        queue[*rear]=elem;
    }
    else
    {
       (*rear)++;
        queue[*rear]=elem;
    }

}
void del(int queue[5],int *front,int *rear)
{
    printf("\nElement deleted is %d",queue[*front]);
    (*front)++;
    printf("\n");
}

void display(int queue[5],int front, int rear)
{
    int p=0;
    for (p=front;p<=rear;p++)
    {
        printf("%5d",queue[p]);
    }
    printf("\n");
    for (p=0;p<5;p++)
    {
        if (p==front)
            printf("front");
        if (p==rear)
            printf("rear");
        else
            printf("   ");
    }
    printf("\n");

    for (p=0;p<5;p++)
    {
        if (p==front)
            printf("%d",front);
        if (p==rear)
            printf("%5d",rear);
        else
            printf("      ");
    }
    printf("\n");
}

void main()
{
    int queue[5],front=-1,rear=-1,elem=67,cap=5,i,c,full,empty;

    for (i=0;i<20;i++)
    {
        printf("\nEnter choice 1.Add 2.Delete 3.Exit");
        scanf("%d",&c);
        if (c==1)
        {
            full=isfull(&front,&rear);
            if (!full)
            {
                add(queue,&rear,&front);
                display(queue,front,rear);
            }
            else
            {
                 printf("\nQueue full\n");
            }

        }
        else if (c==2)
        {
            empty=isempty(&front,&rear);
            if (empty)
                printf("\nQueue empty\n");
            else
            {
                del(queue,&front,&rear);
                display(queue,front,rear);
            }
        }
        else
            exit(0);
    }

}
