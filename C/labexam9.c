#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}node;

void addatend(node **start,node **end,int elem)
{
    node *nnodeptr = (node *)malloc(sizeof(node));
    nnodeptr->next=NULL;
    nnodeptr->info=elem;
    if(*start==NULL)
        (*start)=(*end)=nnodeptr;
    else
    {
        (*end)->next=nnodeptr;
        (*end)=nnodeptr;
    }
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

void ssort(node *start)
{
	node *rider, *min;
	while(start->next)
	{
		min = start;
		rider = start->next;
		while(rider)
		{
			if( min->info > rider->info )
			{
				min = rider;
			}
			rider = rider->next;
		}
		if(min!=start)
            swap(start,min);
		start = start->next;
	}
}

void swap(node *p1, node *p2)
{
	int temp = p1->info;
	p1->info = p2->info;
	p2->info = temp;
}

void main()
{
    node *start=NULL, *end=NULL;
    int ar[10]={11,8,17,6,14,5,13,19,9,16}, i;
    for(i=0;i<10;i++)
    {
        addatend(&start,&end,ar[i]);
    }
    printf("\nBefore Sorting,");
    display(start);
    ssort(start);
    printf("\nAfter Sorting,");
    display(start);
}
