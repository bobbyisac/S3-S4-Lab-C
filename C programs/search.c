#include <stdio.h>

void main()
{
    int arr[5]={1,2,3,4,5},i,num=2;
    for (i=0;i<5;i++)
    {
        if (arr[i]==num)
        {
            printf("Element is found at the position %d",i);
            break;
        }
    }


}
