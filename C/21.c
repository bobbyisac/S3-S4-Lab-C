#include<stdio.h>

int main()
{
    int i,count=0;
    for (i=0;i<10;i++)
    {
        printf("\ni");
        if(i==0&&count<10)
        {
            count++;
            i--;
            printf("i");
        }
    }
    return 0;
}
