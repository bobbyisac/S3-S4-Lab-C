#include <stdio.h>

void main()
{
    int a=0,b=1,n=100,c;
    printf("%d ",a);
    for (;b<=(n-2);)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d ",a);
    }

}
