#include<stdio.h>

int main()
{
    int a,b,c,*ip,i,*io,d;
    ip=&a;
    printf("Print Junk Values\n");
    for (i=0;i<3;i++) //print junk values
    {
        printf("%d\n",*ip);
        ip--;
    }
    ip=&a;
    for (i=1;i<4;i++) //assign values
    {
        *ip=i;
        ip--;
    }
    printf("Print Assigned values\n");
    ip=&a;
    for (i=0;i<3;i++) //print values
    {
	printf("%d\n",*ip);
        ip--;
    }
    ip=&a;
    for (i=0;i<3;i++)//scan values
    {
        printf("Enter Value for Var %d: ",i);
        scanf("%d",ip);
        ip--;
    }
    ip=&a;
    io=&b;
    d=*ip;
    *ip=*io;
    *io=d;
    printf("After Swap a is %d and b is %d\n",*ip,*io);
    d=*ip;
    *ip=*io;
    *io=c;
    c=d;
    printf("After rotation a is %d , b is %d and c is %d",*ip,*io,c);
    return 0;
}
