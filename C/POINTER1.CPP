#include<stdio.h>
#include<conio.h>

int main()
{
    clrscr();
    int a=1,b=2,c=3,*ip;
    int i;
    for (i=0;i<3;i++) //print junk values
    {
	printf("%d\n",*ip);
        ip--;
    }
    return 0;
}
