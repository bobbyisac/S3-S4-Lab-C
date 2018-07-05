#include <stdio.h>
#include <math.h>

void main()
{
    int bin=10101,dec=0,i=0,j=0,ar[20],k;

    for(;bin>0;bin/=10)
    {
        ar[i]=bin%10;
        i++;
    }
    for (k=0;k<i;k++)
    {
        if (ar[k]==1)
            dec+=pow(2,j);
        j++;
    }
    printf("%d",dec);
}
