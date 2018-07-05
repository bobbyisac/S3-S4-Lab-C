#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void addatbeg(struct node **startptrptr, struct node **endptrptr)
{
    struct node *nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter val at beg: ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=*startptrptr;
    if (*startptrptr==NULL)
    {
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else
    {
        (*startptrptr)=nnodeptr;
    }
}

void addatend(struct node **startptrptr, struct node **endptrptr)
{
    struct node *nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter val at end: ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=NULL;
    if (*startptrptr==NULL)
    {
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else
    {
        (*endptrptr)->next=nnodeptr;
        (*endptrptr)=nnodeptr;
    }
}

void addafter (struct node *rider, int val)
{
    struct node *nnodeptr;
    while (rider->num!=val)
    {
        rider=rider->next;
    }
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the val after 30: ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=rider->next;
    rider->next=nnodeptr;
}

void display(struct node *rider)
{
    printf("\nThe List: \n");
    while (rider!=NULL)
    {
        printf("%5d", rider->num);
        rider=rider->next;
    }
}

void main()
{
    struct node *start=NULL, *end=NULL, *nnodeptr=NULL;
    addatend(&start, &end);
    display(start);
    addatend(&start, &end);
    display(start);
    addatbeg(&start, &end);
    display(start);
    addatend(&start, &end);
    display(start);
    addafter(start,30);
    display(start);
}


