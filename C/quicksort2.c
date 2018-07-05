#include<stdio.h>

void display(int *ar)
{
    int i;
    printf("\n The Sorted Array is : ");
    for(i=0;i<7;i++)
    {
        printf("%4d",ar[i]);
    }
}

void quicksort(int *ar, int left, int right)
{
    int pivot=ar[left], l=left, r=right;
    while(l<r)
    {
        while(ar[r]>pivot)
            r--;
        swap(ar,l,r);
        while(ar[l]<pivot)
            l++;
        swap(ar,l,r);
        if(l-left>=2)
            quicksort(ar,left,l-1);
        if(right-r>=2)
            quicksort(ar,r+1,right);
    }
}

void swap(int *ar, int l, int r)
{
    int temp=ar[l];
    ar[l]=ar[r];
    ar[r]=temp;
}

int main()
{
    int ar[7]={12,5,23,24,14,55,34};
    quicksort(ar,0,6);
    display(ar);
    return 0;
}
