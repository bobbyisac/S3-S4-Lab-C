#include<stdio.h>

void main()
{
    int a,b;
    a=10;
    b=20;
    printf("Before swapping swap1=%d and swap2=%d",a,b);
    printf("\n");
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After swapping swap1=%d and swap2=%d",a,b);
    printf("\n");

}
