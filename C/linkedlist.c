#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void addatbeg(struct node **startptrptr, struct node **endptrptr, int elem)
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    nnodeptr->num=elem;
    nnodeptr->next=*startptrptr;
    if(*startptrptr==NULL)//List is initially empty
        (*startptrptr)=(*endptrptr)=nnodeptr;
    else
        *startptrptr=nnodeptr;
}

void addatend(struct node **startptrptr, struct node **endptrptr, int elem)
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    nnodeptr->num=elem;
    nnodeptr->next=NULL;
    if(*startptrptr==NULL)//List is initially empty
        (*startptrptr)=(*endptrptr)=nnodeptr;
    else
    {
        (*endptrptr)->next=nnodeptr;
        *endptrptr=nnodeptr;
    }
}

void addbefore(struct node *rider,struct node **startptrptr, int item, int elem)
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    if (item==(*startptrptr)->num)
    {
        nnodeptr->num=elem;
        nnodeptr->next=*startptrptr;
        *startptrptr=nnodeptr;
    }
    else
    {
        while (rider->next->num!=item)
            rider=rider->next;
        nnodeptr->num=elem;
        nnodeptr->next=rider->next;
        rider->next=nnodeptr;
    }
}

void addafter(struct node *rider, int item, int elem)
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    while (rider->num!=item)
        rider=rider->next;
    nnodeptr->num=elem;
    nnodeptr->next=rider->next;
    rider->next=nnodeptr;
}

void deletebeg(struct node **startptrptr)
{
    struct node * temp = startptrptr;
    *startptrptr=(*startptrptr)->next;
    free(temp);
}

void deleteend(struct node **endptrptr, struct node *rider)
{
    struct node *temp;
    while (rider->next->next!=NULL)
    {
        rider=rider->next;
    }
    temp=rider->next;
    rider->next=NULL;
    *endptrptr=rider;
    free (temp);
}

void deletebetween(struct node *rider, int item)
{
    struct node *temp;
    while (rider->next->num!=item)
    {
        rider=rider->next;
    }
    temp=rider->next;
    rider->next=temp->next;
    free(temp);
}

void search(struct node *rider, int item)
{
    int pos=1;
    while(rider!=NULL)
    {
        if (rider->num==item)
        {
            printf("Element %d found at position %d\n",item,pos);
            return;
        }
        rider=rider->next;
        pos++;
    }
    printf("Element not found in the list\n");
}
void traverse(struct node *rider)
{
    printf("\nThe List is:\n");
    while(rider!=NULL)
    {
        printf("%5d", rider->num);
        rider=rider->next;
    }
    printf("\n");
}

void main()
{
    struct node *start=NULL, *end=NULL, *nnodeptr=NULL, *rider=NULL;
    int choice, elem, item;
    while (1)

    {
        printf("       ---MENU---\n");
        printf(" 1.Add at the beginning\n");
        printf(" 2.Add at the end\n");
        printf(" 3.Add before node\n");
        printf(" 4.Add after node\n");
        printf(" 5.Delete node at the beginning\n");
        printf(" 6.Delete node at the end\n");
        printf(" 7.Delete any element\n");
        printf(" 8.Search\n");
        printf(" 9.Display\n");
        printf("10.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&elem);
            addatbeg(&start,&end,elem);
            traverse(start);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&elem);
            addatend(&start,&end,elem);
            traverse(start);
            break;
        case 3:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                printf("Enter the element to be inserted: ");
                scanf("%d",&elem);
                printf("Enter the element before which to insert: ");
                scanf("%d",&item);
                addbefore(start,&start,item,elem);
                traverse(start);
                break;
            }
        case 4:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                printf("Enter the element to be inserted: ");
                scanf("%d",&elem);
                printf("Enter the element after which to insert: ");
                scanf("%d",&item);
                addafter(start,item,elem);
                traverse(start);
                break;
            }
        case 5:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                printf("First element %d is deleted\n",start->num);
                deletebeg(&start);
                traverse(start);
                break;
            }
        case 6:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                printf("Last element %d is deleted\n",end->next->num);
                deleteend(&end,start);
                traverse(start);
                break;
            }
        case 7:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                printf("Enter the element to be deleted:");
                scanf("%d",&item);
                deletebetween(start,item);
                traverse(start);
                break;
            }
        case 8:
            printf("Enter the element to be found:");
            scanf("%d",&item);
            search(start,item);
            break;
        case 9:
            if (start==NULL)
            {
                printf("List is Empty\n");
                break;
            }
            else
            {
                traverse(start);
                break;
            }
        default:
            exit(0);
        }
    }
}

