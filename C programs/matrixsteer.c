#include <stdio.h>

void main()
{
	int mat[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},r,c,new,old;
	
	for (r=0;r<4;r++)
	{	
		for (c=0;c<4;c++)
			printf("%4d",mat[r][c]);
		printf("\n");
	}
	
	//moving top row
	
	old=mat[1][0];
	for (r=0;r<3;r++)
	{
		new=mat[0][r];
		mat[0][r]=old;
		old=new;
	}

	//moving right column

	for (c=0;c<3;c++)
	{
		new=mat[c][3];
		mat[c][3]=old;
		old=new;
	}

	//moving bottom row

	for (r=3;r>0;r--)
	{
		new=mat[3][r];
		mat[3][r]=old;
		old=new;
	}

	//moving left column

	for (c=3; c>0;c--)
	{
		new=mat[c][0];
		mat[c][0]=old;
		old=new;
	}

	printf("\n");
	
	for (r=0;r<4;r++)
	{	
		for (c=0;c<4;c++)
			printf("%4d",mat[r][c]);
		printf("\n");
	}
}
