#include<stdio.h>

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return (n*(fact(n-1)));
}

int main()
{
    int f=1,n=3;
    f=fact(n);
    printf("The factorial of %d is %d",n,f);
    return 0;
}
