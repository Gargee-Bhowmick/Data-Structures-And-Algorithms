#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n;
	printf("Enter the number of rows and columns in the matrix : ");
	scanf("%d%d",&m,&n);
	int a[m][n],i,j, c=0;
	printf("Enter the elements in the matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			c++;
		}
	}
	(c>((m*n)/2))? printf("It is a sparse matrix") : printf("It is not a sparse matrix");
}
