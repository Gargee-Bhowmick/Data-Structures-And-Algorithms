#include <stdio.h>
void swap(int a[],int b[],int n)//for swapping the rows as mentioned in the question
{
	int i , temp;
	for(i=0;i<n;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
int main()
{
	int i,j,m,n;
	printf("Enter the number of rows and columns of the 2D matrix\n");
	scanf("%d%d",&m,&n);
	int arr[m][n];
	printf("Enter the array elements\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&arr[i][j]);
	}
	for(i=0;i<=(m/2)-1;i++)
	{
		swap(arr[i],arr[n-i],n);
	}
	printf("The desired array is as follows\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
