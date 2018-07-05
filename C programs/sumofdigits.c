#include <stdio.h>

void main()

{
    int lower=100, upper=120,dig,sum=0,temp,fsum=0;
    for (;lower<=upper;lower++)
    {
        sum=0;
        temp=lower;
        for(;temp>0;temp/=10)
        {
            dig=temp%10;
            sum+=dig;
            fsum+=sum;
        }
        printf("Sum of digits of %d is %d\n",lower,sum);
    }
    printf("The final sum is %d",fsum);
}
