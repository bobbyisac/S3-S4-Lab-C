#include <stdio.h>

int prime(int num);

void main()
{
    int n=54,a,b,c,i;
    for (i=2;i<=n;i++)
    {
        a=n-i;
        b=prime(a);
        c=prime(i);
        if (b==1&&c==1)
            break;
    }
    if (b==1&&c==1)
    {
        printf("%d+%d=%d\n",a,i,n);
        printf("yes");
    }
    else
        printf("No");

}

int prime(int num)
{
    int j,flag=1;
    for (j=2;j<=num/2;j++)
    {
        if (num%j==0)
            flag=0;
    }
    if (flag==1)
        return 1;
    else
        return 0;

}
