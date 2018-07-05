#include<stdio.h>
#include<stdlib.h>

typedef struct tnode
{
    int num;
    struct tnode *lchild, *rchild;
} tnode;

void displayin(tnode *root)
{
    if(root==NULL)
    {
        return;
    }
    displayin(root->lchild);
    printf("%4d",root->num);
    displayin(root->rchild);
}

void displaypre(tnode *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%4d",root->num);
    displaypre(root->lchild);
    displaypre(root->rchild);
}

void displaypost(tnode *root)
{
    if(root==NULL)
    {
        return;
    }
    displaypost(root->lchild);
    displaypost(root->rchild);
    printf("%4d",root->num);
}

void findpar(tnode **rootptrptr,int val,tnode **parptrptr)
{
    tnode *par, *child;
    if(*rootptrptr==NULL)
        *parptrptr=*rootptrptr;
    else
    {
        par=*rootptrptr;
        if(val<par->num)
            child=par->lchild;
        else
            child=par->rchild;
        while(child!=NULL)
        {
            par=child;
            if(val<child->num)
                child=child->lchild;
            else
                child=child->rchild;
        }
        *parptrptr=par;

    }
}

void add(tnode **rootptrptr, int val)
{
    tnode *par;
    findpar(rootptrptr,val,&par);
    tnode *nnodeptr=(tnode *)malloc(sizeof(tnode));
    nnodeptr->lchild=nnodeptr->rchild=NULL;
    nnodeptr->num=val;
    if(par==NULL)
    {
        *rootptrptr=nnodeptr;
    }
    else
    {
        if(val<par->num)
        {
            par->lchild=nnodeptr;
        }
        else
        {
            par->rchild=nnodeptr;
        }
    }
}

void display(tnode *root)
{
    printf("\nThe Tree in order is:\n");
    displayin(root);
    printf("\nThe Tree pre order is:\n");
    displaypre(root);
    printf("\nThe Tree post order is:\n");
    displaypost(root);
}

void main()
{
    tnode *root=NULL, *nnodeptr;
    int ch,val;
    while(1)
    {
        printf("\n---MENU---");
        printf("\n1.Add Node");
        printf("\n2.Display");
        printf("\n3.Delete");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter Element to add: ");
            scanf("%d",&val);
            add(&root,val);
            display(root);
            break;
        case 2:
            display(root);
            break;
        case 3:
            printf("\nEnter element to delete: ");
            scanf("%d",&val);
            delete(&root,val);
        default:
            exit(0);
        }
    }
}
