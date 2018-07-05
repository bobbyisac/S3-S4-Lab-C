#include <stdio.h>

void main()
{
	int mat[3][3]={1,2,3,4,5,6,7,8,9},r,c;
	
	// upper triangle 
	
	for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			if (r<=c)
				printf("%4d",mat[r][c]);
			else
				printf("    ");
		}
		printf("\n");
	}
	printf("\n");

	// lower triangle 
	
	for (r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			if (r>=c)
				printf("%4d",mat[r][c]);
			else
				printf("    ");
		}
		printf("\n");
	}
	printf("\n");


}
