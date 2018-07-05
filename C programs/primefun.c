#include <stdio.h>

int prime(int num);

void main()
{
    int num=19,b;
    b=prime(num);
    if (b==1)
        printf("Prime");
    else
        printf("Not Prime");
}

int prime(int num)
{
    int i,flag=1;
    for (i=2;i<=num/2;i++)
    {
        if (num%i==0)
            flag=0;
    }
    if (flag==1)
        return 1;
    else
        return 0;

}
