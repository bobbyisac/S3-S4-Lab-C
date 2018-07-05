//to convert a decimal to binary and count the no. of ones

void main()
{
    int num=21,count=0,n[10],i=0;
    for(;num>0;)
    {
        n[i]=num%2;
        num/=2;
        if (n[i]==1)
            count+=1;
        i++;
    }
    i--;
    for (;i>=0;i--)
        printf("%d",n[i]);

    printf("\nNo. of 1's = %d",count);
}
