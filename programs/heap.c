#include<stdio.h>
#include<stdlib.h>

void printheap(int heap[],int size)
{
    printf("\n size now is %d ",size);
    int p;
    for(p=1;p<=size;p++)
    {
        printf("\n%5d",heap[p]);
    }
}

void addheap(int heap[],int elem,int size)
{
    if(size==1)
    {
        heap[1]=elem;
        return;
    }
    else
    {
        int par=size/2,pos=size;
        while(par>=1)
        {
            if(heap[par]>elem)
            {
                heap[pos]=heap[par];
                pos=par;
                par=par/2;
            }
            else
                break;
        }
        heap[pos]=elem;
    }
}

void delete(int heap[],int *size)
{
    int i=1,lchild=2*i,rchild=lchild+1,num;
    int max=heap[i];
    heap[i]=heap[*size];
    (*size)--;
    num=heap[i];
    while(rchild<=(*size))
    {
        if(num<=heap[lchild] && num<=heap[rchild])
        {
            heap[i]=num;
            break;
        }
        else if(heap[lchild]<heap[rchild])
        {
            heap[i]=heap[lchild];
            i=lchild;
        }
        else
        {
            heap[i]=heap[rchild];
            i=rchild;
        }
        lchild=2*i;
        rchild=lchild+1;
    }
    if(lchild==(*size) && num>heap[lchild])
    {
        heap[i]=heap[lchild];
        i=lchild;
    }
    heap[i]=num;
}

void main()
{
    int ar[7]={0,22,14,69,41,75,33},p,size,heap[7];
    for(size=1;size<7;size++)
    {
        addheap(heap,ar[size],size);
    }
    printheap(heap,size);
}
