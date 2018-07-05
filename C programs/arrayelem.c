#include <stdio.h>

void main()
{
    int arr[5]={1,2,3,4,5},sum=0,i,small,large;
    for (i=0;i<5;i++)
    {
        sum+=arr[i];
    }
    printf("Sum of all elements in the array is %d",sum);
    printf("\n");
    large=arr[0];
    for (i=1;i<5;i++)
    {
        if (large>arr[i])
            small=arr[i];
        else
            large=arr[i];
    }
    for(i=0;i<5;i++)
    {
        if (small>arr[i])
            small=arr[i];
    }

    printf("The largest element is %d",large);
    printf("\n");
    printf("The smallest element is %d",small);
    printf("\n");

}
