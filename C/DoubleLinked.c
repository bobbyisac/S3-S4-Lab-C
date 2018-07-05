#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *flink;
    struct node *blink;
}node;

void fdisplay(node *rider)
{
    printf("\nForward traversal\n");
    if(rider==NULL)
        printf("\nList is empty !!!");
    while(rider!=NULL) //traversing through list until rider null
    {
        printf("%d-->",rider->num);
        rider=rider->flink;
    }
    printf("\n");
}

void bdisplay(node *rider)
{
    printf("\nBackward traversal\n");
    if(rider==NULL)
        printf("\nList is empty !!!");
    while(rider!=NULL) //traversing through list until rider null
    {
        printf("<--%d",rider->num);
        rider=rider->blink;
    }
    printf("\n");
}

void addatend(node **startptrptr,node **endptrptr,int elem)
{
    node *nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->num=elem;
    nnodeptr->flink=NULL;
    nnodeptr->blink=NULL;
    if(*endptrptr==NULL)//if list is empty
    {
        *startptrptr=*endptrptr=nnodeptr;
    }
    else//general case
    {
        (*endptrptr)->flink=nnodeptr;
        nnodeptr->blink=*endptrptr;
        *endptrptr=nnodeptr;
    }
}

void addatbeg(node **startptrptr,node **endptrptr,int elem)
{
    node *nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->num=elem;
    nnodeptr->flink=NULL;
    nnodeptr->blink=NULL;
    if(*startptrptr==NULL)//if list is empty
    {
        *startptrptr=*endptrptr=nnodeptr;
    }
    else//general case
    {
        (*startptrptr)->blink=nnodeptr;
        nnodeptr->flink=*startptrptr;
        *startptrptr=nnodeptr;
    }
}

void addbefore(node *rider,node **startptrptr,int item,int elem)
{
    node *nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->num=elem;
    nnodeptr->flink=NULL;
    nnodeptr->blink=NULL;
    if((*startptrptr)->num==item)//add before first element
    {
        (*startptrptr)->blink=nnodeptr;
        nnodeptr->flink=*startptrptr;
        *startptrptr=nnodeptr;
    }
    else//general case
    {
        while(rider->flink->num!=item)
        {
            rider=rider->flink;

        }
        nnodeptr->blink=rider;
        nnodeptr->flink=rider->flink;
        rider->flink->blink=nnodeptr;
        rider->flink=nnodeptr;
    }
}

void addafter(node *rider,node **endptrptr,int item,int elem)
{
    node *nnodeptr=(node *)malloc(sizeof(node));
    nnodeptr->num=elem;
    nnodeptr->flink=NULL;
    nnodeptr->blink=NULL;
    if((*endptrptr)->num==item)//add after last element
    {
        (*endptrptr)->flink=nnodeptr;
        nnodeptr->blink=*endptrptr;
        *endptrptr=nnodeptr;

    }
    else//general case
    {
        while(rider->num!=item)
        {
            rider=rider->flink;

        }
        nnodeptr->blink=rider;
        nnodeptr->flink=rider->flink;
        rider->flink->blink=nnodeptr;
        rider->flink=nnodeptr;
    }
}

int deletebeg(node **startptrptr,node **endptrptr)
{
    node *temp;
    int val;
    if((*startptrptr)->flink==NULL)//only one element
    {
        temp=*startptrptr;
        val=(*startptrptr)->num;
        *startptrptr=*endptrptr=NULL;
        free(temp);
    }
    else
    {
        temp=*startptrptr;
        val=(*startptrptr)->num;
        *startptrptr=(*startptrptr)->flink;
        (*startptrptr)->blink=NULL;
        free(temp);
    }
    return val;

}

int deleteend(node **startptrptr,node **endptrptr)
{
    node *temp;
    int val;
    if((*startptrptr)->flink==NULL)//only one element
    {
        temp=*startptrptr;
        val=(*startptrptr)->num;
        *startptrptr=*endptrptr=NULL;
        free(temp);
    }
    else
    {
        temp=*endptrptr;
        val=(*endptrptr)->num;
        (*endptrptr)->blink->flink=NULL;
        (*endptrptr)=(*endptrptr)->blink;
        free(temp);
    }
    return val;

}

void deleteany(node **startptrptr,node **endptrptr,node *rider,int item)//Finding the element to be deleted
{
    node *temp,*start,*end;
    start=*startptrptr;
    end=*endptrptr;
    int val;
    if((*startptrptr)->flink==NULL&&(*startptrptr)->num==item)//first element
    {
        temp=*startptrptr;
        *startptrptr=*endptrptr=NULL;
        free(temp);
    }
    else if((*endptrptr)->num==item)//last element
    {
        temp=*endptrptr;
        val=(*endptrptr)->num;
        (*endptrptr)->blink->flink=NULL;
        (*endptrptr)=(*endptrptr)->blink;
        free(temp);
    }
    else if((*startptrptr)->num==item)
    {
        temp=*startptrptr;
        val=(*startptrptr)->num;
        *startptrptr=(*startptrptr)->flink;
        (*startptrptr)->blink=NULL;
        free(temp);
    }
    else
    {
        while (rider->flink->num!=item)
        {
            rider=rider->flink;
        }
        temp=rider->flink;
        rider->flink=rider->flink->flink;
        rider->flink->blink=rider;
        free(temp);
    }
}

void search(node *rider,int elem)
{
    while(rider->num!=elem)
        {
            rider=rider->flink;
            if(rider==NULL)
                break;
        }
    if(rider!=NULL)
        printf("\nElement found at position:%u",rider);
    else
        printf("\nElement Not found");
}

void main()
{
    node *start=NULL,*end=NULL;
    int item,ch,ele,val;
    while(1)
    {
        printf("\n---MENU---\n1.Addition at beginning\n2.Addition at end\n3.Add before a node");
        printf("\n4.Add after a node\n5.Delete at beginning\n6.Delete at end");
        printf("\n7.Delete any element\n8.Search\n9.Display\n10.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the element to be added:");
            scanf("%d",&ele);
            addatbeg(&start,&end,ele);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 2:
            printf("\nEnter the element to be added:");
            scanf("%d",&ele);
            addatend(&start,&end,ele);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 3:
            if(start==NULL)
            {
                printf("\nList is empty");
            }
            printf("\nEnter the element before which to insert:");
            scanf("%d",&item);
            printf("\nEnter the element to be added:");
            scanf("%d",&ele);
            addbefore(start,&start,item,ele);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 4:
            if(start==NULL)
            {
                printf("\nList is empty");
            }
            printf("\nEnter the element after which to insert:");
            scanf("%d",&item);
            printf("\nEnter the element to be added:");
            scanf("%d",&ele);
            addafter(start,&end,item,ele);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 5:
            if(start==NULL)
            {
                printf("\nList is empty");
            }
            val=deletebeg(&start,&end);
            printf("\nDeleted element is %d\n",val);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 6:
            if(start==NULL)
            {
                printf("\nList is empty");
            }
            val=deleteend(&start,&end);
            printf("\nDeleted element is %d\n",val);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 7:
            if(start==NULL)
            {
                printf("\nList is empty");
            }
            printf("\nEnter the element to be deleted:");
            scanf("%d",&ele);
            deleteany(&start,&end,start,ele);
            fdisplay(start);
            printf("\n");
            bdisplay(end);
            break;

        case 8:
            printf("\nEnter the element to be searched:");
            scanf("%d",&ele);
            search(start,ele);
            break;

        case 9:
            if(start==NULL)
                    {
                        printf("list is empty");
                        break;
                    }
                    else
                    {
                        fdisplay(start);
                        bdisplay(start);
                        break;
                    }

        default:
            exit(0);
        }
    }

}
