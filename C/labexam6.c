#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char info;
    struct node *next;
}node;

void add(node **start, char c)
{
    node *rider, *nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->info=c;
    if((*start)==NULL || c<((*start)->info))
    {
        nnodeptr->next=*start;
        *start=nnodeptr;
    }
    else
    {
        rider=*start;
        while((rider->next)!=NULL && (rider->next->info)<c)
        {
            rider=rider->next;
        }
        nnodeptr->next=rider->next;
        rider->next=nnodeptr;
    }
}

void display(struct node *rider)
{
    printf("The List is : \n");
    while (rider!=NULL)
    {
        printf("%5c", rider->info);
        rider=rider->next;
    }
}

void main()
{
    node *start=NULL;
    char name[10]="bobbyisac";
    int i;
    for(i=0;i<9;i++)
    {
        add(&start,name[i]);
    }
    display(start);
}
