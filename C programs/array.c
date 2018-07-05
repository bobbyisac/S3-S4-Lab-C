#include <stdio.h>

void main()
{
    int arr[5]={40,7,9,87,56},p,temp;
    for (p=0;p<5;p++)
    {
        printf("%5d",arr[p]);
    }
    printf("\n");
    for (p=0;p<5;p++)
    {
        if (arr[p]%2==1)
            printf("%5d", arr[p]);
        else
            printf("     ");
    }
    printf("\n");
    for (p=0;p<5;p++)
    {
        if (p%2==1)
            printf("%5d", arr[p]);
        else
            printf("     ");
    }
    printf("\n");
    for (p=0;p<5;p++)
    {
        if (arr[p]<20)
            printf("%5d", arr[p]);
        else
            printf("     ");
    }

}

