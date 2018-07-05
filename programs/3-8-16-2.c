#include<stdio.h>

int main()
{
    int ar[7]={5,3,1,4,2,7,6},p,bp=0,big=ar[0],temp;
    for(p=0;p<7;p++) // print array before swap
       {
           printf("%4d",ar[p]);
       }
    for (p=1;p<7;p++) //for checking against small
    {
        if(ar[p]>big) //if elem is small
        {
            big=ar[p];
            bp=p; //pos
        }
    }
    printf("\nbig = %d @ pos %d\n",big,bp); //printing small and sp
    temp=ar[bp];
    ar[bp]=ar[0];
    ar[0]=temp;
    for(p=0;p<7;p++) // print array after swap
       {
           printf("%4d",ar[p]);
       }
    return 0;
}
