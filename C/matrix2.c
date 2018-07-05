#include<stdio.h>

int main ()
{
    int ar[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},r,c,temp;
    for(c=3;c>0;c--)
    {
        temp=ar[0][c];
        ar[0][c]=ar[0][c-1];
    }
    //ar[1][3]=temp;
    for(r=2;c<4;c++)
    {
        temp=ar[r][3];
        ar[r][3]=ar[r-1][3];
    }
    for (r=0;r<4;r++)
    {
        for (c=0;c<4;c++)
        {
            printf("%4d",ar[r][c]);
        }
        printf("\n");
    }
    return 0;
}

