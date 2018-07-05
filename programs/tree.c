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

void findpar(tnode **rootptrptr,int val,tnode **parptrptr)   //find parent to add node
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

void add(tnode **rootptrptr, int val)    // function to add a node
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

void findparloc(tnode **root, int val, tnode **par, tnode**loc, tnode **child)
{
    tnode *parloc=*root,*childloc,*gchild;
    if(val==(*root)->num)
    {
        *par=*root;
        *loc=*root;
        *child=gchild;
        return;
    }
    else if(val<(*root)->num)
        childloc=(*root)->lchild;
    else
        childloc=(*root)->rchild;
    while(childloc->num!=val)
    {
        parloc=childloc;
        if (val<(childloc->num))
            childloc=childloc->lchild;
        else
            childloc=childloc->rchild;
    }
    if(childloc->lchild!=NULL)
        gchild=childloc->lchild;
    else
        gchild=childloc->rchild;
    *par=parloc;
    *loc=childloc;
    *child=gchild;
}

void delete1(tnode **root, int val)
{
    tnode *par, *child, *loc;
    findparloc(root,val,&par,&loc,&child);
    if (par==loc)
    {
        if((*root)->lchild==NULL)
            *root=(*root)->rchild;
        else
            *root=(*root)->lchild;

    }
    else if((child->num)<(par->num))
        par->lchild=child;
    else
        par->rchild=child;
    free(loc);
}

void delete0(tnode **root, int val)
{
    struct tnode *parloc, *childloc=*root;
    if(val==(*root)->num)
    {
        *root=NULL;
        return;
    }
    else if (val<(*root)->num)
    {
        childloc=(*root)->lchild;
    }
    else
        childloc=(*root)->rchild;
    parloc=*root;
    while(childloc->num!=val)
    {
        parloc=childloc;
        if(val<childloc->num)
            childloc=childloc->lchild;
        else
            childloc=childloc->rchild;
    }
    if (val<parloc->num)
        parloc->lchild=NULL;
    else
        parloc->rchild=NULL;
}

void findloc(tnode **root, int val, tnode **loc)
{
    *loc=*root;
    while((*loc)->num!=val)
    {
        if(val<(*loc)->num)
        {
            *loc=(*loc)->lchild;
        }
        else
        {
            *loc=(*loc)->rchild;
        }
    }
}

void findnext(tnode *loc, tnode **parnext, tnode **next)
{
    *parnext=loc;
    *next=loc->rchild;
    while((*next)->lchild!=NULL)
    {
        *parnext=*next;
        *next=(*next)->lchild;
    }
}

void delete2(tnode **root, int val)
{
    tnode *loc, *parnext, *next;
    findloc(root,val,&loc);
    findnext(loc,&parnext,&next);
    parnext->rchild=next;
    int temp=next->num;
    del(root,next->num);
    loc->num=temp;
}

void del(tnode **root, int val)
{
    tnode *loc;
    int count=0;
    findloc(root,val,&loc);
    if(loc->lchild!=NULL)
        count++;
    if(loc->rchild!=NULL)
        count++;
    if(count==0)
        delete0(root,val);
    else if(count==1)
        delete1(root,val);
    else if(count==2)
        delete2(root,val);
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
            del(&root,val);
            display(root);
            break;
        default:
            exit(0);
        }
    }
}
