#include<stdio.h>

void main()
{
    int r,c ;
    for(r=0;r<3;r++)
    {
        for(c=0;c<=r;c++)
        {
           printf("X");
        }
        printf("\n");
    }
}
