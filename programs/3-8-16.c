#include<stdio.h>

int main()
{
    int ar[7]={45,23,88,7,39,21,36},n=7,p,temp,pass,sc;
    printf("The array before pass ");
    for(p=0;p<n;p++) //print intial array
    {
        printf("%4d",ar[p]);
    }
    for(pass=0;pass<(n-1);pass++) // for multiple passes
    {
        sc=0;
        for(p=0; p<(n-1-pass); p++) // for a pass
        {
            if (ar[p]>ar[p+1]) // if right element is smaller
            {
                temp=ar[p];
                ar[p]=ar[p+1];
                ar[p+1]=temp;
                sc++;
            }
        }
        printf("\nArray after pass %d",pass);
        for(p=0;p<n;p++) // print array after a pass
        {
            printf("%4d",ar[p]);
        }
        if(sc==0)
            break;
    }
    return 0;
}
