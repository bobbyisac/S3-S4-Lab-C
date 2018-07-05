#include <stdio.h>

int isfull(int front, int rear, int cap)
{
    if ((rear+1)%cap==front)
        return 1;
    else
        return 0;

}

int isempty(int front)
{
    if (front==-1)
        return 1;
    else
        return 0;
}

void insert(int *queue,int *rear,int *front, int cap, int elem)
{
    if (*rear==-1)
    {
        *front=0;
        *rear=0;
    }
    else
        *rear=((*rear+1)%cap);
    queue[*rear]=elem;
}

int del(int *queue,int *front,int *rear, int cap)
{
    int elem;
    if (*front == *rear)
    {
        elem=queue[*front];
        *front=-1;
        *rear=-1;
        return elem;
    }
    else
    {
        elem=queue[*front];
        *front=((*front+1)%cap);
        return elem;
    }

}

void display(int *queue,int front, int rear)
{
    int p, cap=5;
    printf("Queue is:\n");
    if (front<=rear)
    {
        for (p=front;p<=rear;p++)
            printf("%5d",queue[p]);
    }
    else
    {
        for (p=0;p<=rear;p++)
            printf("%5d",queue[p]);
        for (p=front;p<cap;p++)
            printf("%5d",queue[p]);
    }

}

void main()
{
    int queue[5],front=-1,rear=-1,cap=5,c,elem,i;

    for (i=0;i<20;i++)
    {
        printf("\nEnter choice 1.Add 2.Delete 3.Display 4.Exit ");
        scanf("%d",&c);
        if (c==1)
        {
            if (isfull(front,rear,cap))
            {
                printf("\nQueue full\n");
            }
            else
            {
                printf("\nElement:");
                scanf("%d",&elem);
                insert(queue,&rear,&front,cap,elem);
                printf("Front=%d Rear=%d",front,rear);
                printf("\n");
            }

        }
        else if (c==2)
        {

            if (isempty(front))
                printf("\nQueue empty\n");
            else
            {
                elem=del(queue,&front,&rear,cap);
                printf("Front=%d Rear=%d",front,rear);
                printf("Deleted element is %d",elem);
            }
        }
        else if (c==3)
            display(queue,front,rear);
        else
            exit(0);
    }

}
