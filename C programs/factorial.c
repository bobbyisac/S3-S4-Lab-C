#include <stdio.h>

void main()
{
    int fact=1,num=33,temp;
    temp=num;
    for(;temp>0;temp--)
    {
        fact=fact*temp;
    }
    printf("Factorial of %d is %d ",num,fact);
}

