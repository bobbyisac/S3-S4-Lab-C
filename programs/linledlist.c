#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void display(struct node *rider)
{
    printf("\nThe List is\n");
    while(rider!=NULL)
    {
        printf("%4d",rider->num);
        rider=rider->next;
    }
}

void addatbeg(struct node **endptrptr, struct node **startptrptr)
{
    struct node *nnodeptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter Value to Insert: ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=(*startptrptr);
    if(*startptrptr==NULL)
        (*startptrptr)=(*endptrptr)=nnodeptr;
    else
    {
        (*startptrptr)=nnodeptr;
    }
}

void addatend(struct node **endptrptr, struct node **startptrptr)
{
    struct node *nnodeptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter Value to Insert: ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=NULL;
    if(*startptrptr==NULL)
        (*startptrptr)=(*endptrptr)=nnodeptr;
    else
    {
        (*endptrptr)->next=nnodeptr;
        (*endptrptr)=nnodeptr;
    }
}

void addafter(struct node *rider, int val)
{
    struct node *nnodeptr = (struct node *) malloc(sizeof(struct node));
    while(rider->num!=val)
    {
        rider=rider->next;
    }
    printf("\nEnter the Element to be inserted");
    scanf("%d",&nnodeptr->num);
    nnodeptr->next=rider->next;
    rider->next=nnodeptr;
}

int main()
{
    struct node *start=NULL, *end=NULL;
    struct node *nnodeptr = (struct node *) malloc(sizeof(struct node));
    addatend(&end,&start);
    display(start);
    addatend(&end,&start);
    display(start);
    addatend(&end,&start);
    display(start);
    addatbeg(&end,&start);
    display(start);
    addatbeg(&end,&start);
    display(start);
    addatbeg(&end,&start);
    display(start);
    addafter(start,4);
    display(start);
    return 0;
}
