#include<stdio.h>

int main()
{
    int i,j;
    printf("I\n");
    for(i=1;i<9;i++)
    {
        printf("I");
        for(j=0;j<i;j++)
        {
            printf(" ");
        }
        printf("I\n");
    }
    for(i=0;i<=10;i++)
        printf("I");
    return 0;
}
