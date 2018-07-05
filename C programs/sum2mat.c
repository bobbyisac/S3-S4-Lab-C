#include <stdio.h>

void main()
{
    int mat1[3][3]={10,20,30,40,50,60,70,80,90}, mat2[3][3]={9,8,7,6,5,4,3,2,1},r,c,s[3][3];
    printf("Matrix 1\n");
    for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
            printf("%4d",mat1[r][c]);

		}
		printf("\n");
	}
	printf("\nMatrix 2\n");
	for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
            printf("%4d",mat2[r][c]);

		}
		printf("\n");
	}
	printf("\nSum of Matrix 1 & Matrix 2\n");
    for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
            s[r][c]=mat1[r][c]+mat2[r][c];

		}
	}
	for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
            printf("%4d",s[r][c]);

		}
		printf("\n");
	}
}
