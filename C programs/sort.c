#include <stdio.h>

void main()
{
    int arr[5]={25,76,43,40,4},temp,i,j;
    for (j=1;j<=5;j++)
    {
        for (i=0;i<5;i++)
        {
            if (arr[i]>arr[i+1])
            {
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for (i=0;i<5;i++)
    {
        printf("%5d",arr[i]);
    }
}
