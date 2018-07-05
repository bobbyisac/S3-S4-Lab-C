#include<stdio.h>

int tower(int n, char beg, char mid, char end)
{
    static float count=1;
    if (n==1)
    {
        printf("\n%f.%c-->%c",count++,beg,end);
        return 0;
    }
    tower(n-1,beg,end,mid);
    printf("\n%f.%c-->%c",count++,beg,end);
    tower(n-1,mid,beg,end);
}

int main()
{
    int num=3;
    tower(num,'A','B','C');
    return 0;
}
