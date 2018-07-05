#include<stdio.h>

int main ()
{
    int ar[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},r,c;
    for (r=0;r<4;r++)
    {
        for (c=0;c<4;c++)
        {
            if ((r==0||r==3||c==0||c==3))
            {
                printf("%4d",ar[r][c]);
            }
            else
                printf("%4d",ar[r][c]);
        }
        printf("\n");
    }
    return 0;
}
