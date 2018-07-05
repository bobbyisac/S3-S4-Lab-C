//WAP to find the sum of all the elements in a matrix

#include <stdio.h>

void main()
{
    int mat[3][3]={1,2,3,4,5,6,7,8,9},r,c,s=0;
    for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
            printf("%4d",mat[r][c]);
		}
		printf("\n");
	}
	printf("\n");

    for (r=0;r<3;r++)
    {
        for (c=0;c<3;c++)
            s+=mat[r][c];
    }
    printf("Sum of all elements in the matrix =%d\n",s);
}
