#include <stdio.h>
#include <stdlib.h>

int isEmpty(int front)
{
    if (front==-1)
        return 1;
    else
        return 0;
}

int isFull(int rear, int cap, int front)
{
    if ((rear+1)%cap==front)
        return 1;
    else
        return 0;
}

void insert(int elem, int *queue, int *front, int *rear, int cap)
{
    if (*rear == -1)
    {
        *front =0;
        *rear =0;
    }

    else
        *rear=((*rear)+1)%cap;
    queue[*rear]=elem;
}

int del(int *queue,int *front, int *rear, int cap)
{
    int elem;
    if (*front==*rear)
    {
        elem=queue[*front];
        *front=-1;
        *rear=-1;
        return elem;
    }
    else
    {
        elem=queue[*front];
        *front=((*front)+1)%cap;
        return elem;
    }
}

void display(int front, int rear, int *queue)
{
    int p, cap=5;
    printf("\nQueue is:\n");
    if(front<=rear)
    {
        for(p=front;p<=rear;p++)
        {
            printf("%5d",queue[p]);
        }
    }
    else
    {
        for(p=0;p<=rear;p++)
        {
            printf("%5d",queue[p]);
        }
        for(p=front;p<cap;p++)
        {
            printf("%5d",queue[p]);
        }
    }
    printf("\n\n");

}

void main()
{
    int front=-1, rear=-1,choice,elem,queue[5],cap=5;
    printf("1.Insert 2.Delete 3.Display 4.Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if (isFull(rear,cap,front))
            {
                printf("Queue Overflow\n");
                break;
            }
            else
            {
                printf("Enter element to be inserted: ");
                scanf("%d",&elem);
                insert(elem,queue,&front, &rear, cap);
                printf("\nFront=%2d Rear=%2d\n",front,rear);
                display(front, rear, queue);
                break;
            }
        case 2:
            if (isEmpty(front))
            {
                printf("Queue Underflow\n\n");
                break;
            }
            else
            {
                elem=del(queue,&front,&rear, cap);
                printf("\nFront=%2d Rear=%2d\n",front,rear);
                printf("Deleted element is %d\n\n",elem);
                display(front, rear, queue);
                break;
            }
        case 3:
            if (isEmpty(front))
            {
                printf("Queue Underflow\n\n");
                break;
            }
            else
            {
                display(front, rear, queue);
                break;
            }
        case 4:
            exit(0);
        }

    }
}


