#include<stdio.h>

int main()
{
    int ar[7]={45,23,88,7,39,21,36},n=7,p,temp,sp=0;
    int small=ar[0],pass=0;
    printf("The array before pass ");
    for(p=0;p<n;p++) //print intial array
    {
        printf("%4d",ar[p]);
    }
    for (p=1;p<7;p++) //for checking against small
    {
        if(ar[p]<small) //if elem is small
        {
            small=ar[p];
            sp=p; //pos
        }
    }
    temp=ar[0];
    ar[0]=ar[sp];
    ar[sp]=temp;
    printf("\nArray after pass %d ",pass);
    for(p=0;p<7;p++) // print array after swap
       {
           printf("%4d",ar[p]);
       }
    return 0;
}
