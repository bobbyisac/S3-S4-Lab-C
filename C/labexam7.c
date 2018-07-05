#include<stdio.h>

int delheap(int heap[],int *size)
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
            return max;
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
    return max;
}

void main()
{
    int heap[8]={0,10,20,30,50,40,60,70},p=0,list[8],size=7;
    while(size>0)
    {
        list[p++]=delheap(heap, &size);
    }
    printf("\nThe Sorted List is:\n");
    for(p=0;p<7;p++)
        printf("%5d",list[p]);
}
