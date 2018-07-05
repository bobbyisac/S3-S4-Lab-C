#include <stdio.h>

void main()
{
    int c,col=25,l,lt=10,sp,a,b;//initialization
    for (c=1;c<=col;c++)//for horizontal limb
    {
        printf("T");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=4500;b++);
    }
    printf("\n");//to go to next line
    for (l=1;l<=lt;l++)//for vertical limb
    {
        for (sp=1;sp<=col/2;sp++)//for space
        {
            printf(" ");
        }
        printf("T\n");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=40000;b++);
    }
}
