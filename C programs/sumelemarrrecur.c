#include <stdio.h>

int sumarr(int arr[5],int i);

void main()
{
    int arr[5]={1,2,3,4,5},sum=0;
    sum=sumarr(arr,0);
    printf("Sum=%d",sum);
}

int sumarr(int arr[5],int i)
{
    static int s=0;

    s+=arr[i]+sumarr(arr,i+1);
    if (i==5);
        return s;
}
