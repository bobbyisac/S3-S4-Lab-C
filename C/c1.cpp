#include<iostream>

using namespace std;

int prime(int num)
{
    int i;
    for(i=2;i<=(num/2);i++)
    {
        if (num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int sump=0,N,i,count=0,j;
    cout<<"Enter N : ";
    cin>>N;
    for (j=2;j<=N;j++)
    {
        count=0;
        for (i=2;i<=N;i++)
        {
            if (prime(i))
            {
                sump=sump+i;
            }
            if (prime(sump))
            {
                count=count+1;
            }
        }
    }
    cout<<count;
    return 0;
}
