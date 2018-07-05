void main()
{
    int arr[7]={66,60,23,78,90,100,34},p,big,temp,bp=0;
    printf("Array:\n");
    for (p=0;p<7;p++) //to print the original array
        printf("%5d",arr[p]);
    printf("\n");
    big=arr[0];
    for (p=1;p<6;p++)
    {
        if (arr[p]>big)//to find smallest elem
        {
           big=arr[p];
           bp=p;
        }
    }
    temp=arr[bp];
    arr[bp]=arr[0];
    arr[0]=temp;
    for (p=0;p<7;p++) //to print the original array
        printf("%5d",arr[p]);
    printf("\n");

}
