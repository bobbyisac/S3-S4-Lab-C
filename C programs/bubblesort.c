#include <stdio.h>

void main()
{
    int arr[7]={100,66,34,78,90,68,23},p,pass,temp;
    printf("Array:\n");
    for (p=0;p<7;p++) //to print the original array
        printf("%5d",arr[p]);
    for (pass=0;pass<7-1;pass++) //bubble sorting
    {
        for (p=0;p<7-1;p++)
        {
            if (arr[p]>arr[p+1]) //to swap 2 elements
            {
                temp=arr[p];
                arr[p]=arr[p+1];
                arr[p+1]=temp;
            }
        }//swapping
        printf("\n\nArray bubble sort after pass %d\n",pass);
        for (p=0;p<7;p++)
            printf("%5d",arr[p]);
    }// pass completed

}


