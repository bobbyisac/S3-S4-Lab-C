#include <stdio.h>

void main()
{
    int arr[7]={100,66,34,78,90,68,23},p,sp,small,temp;
    printf("Array:\n");
    for (p=0;p<7;p++) //to print the original array
        printf("%5d",arr[p]);
    printf("\n");
    small=arr[0];
    for (p=1;p<7-2;p++)
    {
        if (small>arr[p])
        {
            small=arr[p];
            sp=p;
        }
    }
    temp=arr[0];
    arr[0]=arr[0];
    arr[sp]=temp;
    for (p=0;p<7;p++) //to print the sorted array
        printf("%5d",arr[p]);
}
