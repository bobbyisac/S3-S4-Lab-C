#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}node;

void addatbeg(node **start,int elem)
{
    node *nnodeptr;
    nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->info=elem;
    nnodeptr->next=*start;
    (*start)=nnodeptr;
}

void display(struct node *rider)
{
    printf(" the List is : \n");
    while (rider!=NULL)
    {
        printf("%5d", rider->info);
        rider=rider->next;
    }
}

void bsort(node *start)
{
    int swapped=1, i;
    node *ptr1;

    while(swapped)
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != NULL)
        {
            if (ptr1->info > ptr1->next->info)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    }
}

void swap(node *a, node *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void main()
{
    node *start=NULL;
    int ar[10]={11,8,17,6,14,5,13,19,9,16}, i;
    for(i=0;i<10;i++)
    {
        addatbeg(&start,ar[i]);
    }
    printf("\nBefore Sorting,");
    display(start);
    bsort(start);
    printf("\nAfter Sorting,");
    display(start);
}
