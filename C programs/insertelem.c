#include <stdio.h>

void main()
{
    int arr[5]={1,2,3,5,6},arr1[6],i,j,temp,num;
    num=4;
    j=3;
    for (i=0;i<6;i++)
    {
        arr1[i]=arr[i];
        if (i==j)
            arr1[i]=num;
    }
    for (i=0;i<5;i++)
    {
        printf("%5d",arr1[i]);
    }

}
