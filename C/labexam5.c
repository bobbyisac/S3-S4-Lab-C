#include<stdio.h>

typedef struct node
{
    char info;
    struct node *next,*prev;
}node;

void addatbeg(node **start, node **end, char c)
{
    node *nnodeptr;
    nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->prev=NULL;
    nnodeptr->info=c;
    nnodeptr->next=*start;
    if (*start==NULL)
    {
        (*start)=(*end)=nnodeptr;
    }
    else
    {
        (*start)->prev=nnodeptr;
        (*start)=nnodeptr;
    }
}

void addatend(node **start, node **end, char c)
{
    node *nnodeptr;
    nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->info=c;
    nnodeptr->next=NULL;
    nnodeptr->prev=*end;
    if (*start==NULL)
    {
        (*start)=(*end)=nnodeptr;
    }
    else
    {
        (*end)->next=nnodeptr;
        (*end)=nnodeptr;
    }
}

void display(struct node *rider)
{
    printf("\nThe List: \n");
    while (rider!=NULL)
    {
        printf("%5c", rider->info);
        rider=rider->next;
    }
}

int isvowel(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return 1;
    return 0;
}

void main()
{
    node *start=NULL, *end=NULL;
    char name[10]="bobbyisac";
    int i;
    for(i=0;i<9;i++)
    {
        if(isvowel(name[i]))
            addatend(&start,&end,name[i]);
        else
            addatbeg(&start,&end,name[i]);
    }
    display(start);
}
