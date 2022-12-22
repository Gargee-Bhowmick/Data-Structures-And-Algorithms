#include <stdio.h>
void nonZero(int n, int arr[][n])
{
	int m=0,i,j;
		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]!=0)
			m++;
		}
	}
	printf("\n\nThere are %d non zero elements in the array",m);
}
void sumAboveLD(int n,int arr[][n])
{
	int i,j,sum=0;
		for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			sum=sum+arr[i][j];
		}
	}
	printf("\n\nThe sum of elements above the leading diagonal is %d",sum);
}
void displayAboveMD(int n,int arr[][n])
{
	int i,j;
	printf("\n");
		for(i=1;i<n;i++)
	{
		for(j=n-i;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void productD(int n,int arr[][n])
{
	int i,j,p=1;
		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j==i)||((i+j)==(n-1)))
			{
				p=p*arr[i][j];
			}
		}
	}
		printf("\nThe product of elements on the diagonal is %d",p);
}
int main()
{
	int n,i,j;
	printf("Enter the order of a square matrix\n");
	scanf("%d",&n);  
	printf("Enter the %d elements in the 2-D matrix\n",n*n);
	int arr[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&arr[i][j]);
	}
	nonZero(n,arr);
	sumAboveLD(n,arr);
	displayAboveMD(n,arr);
	productD(n,arr);
	return 0;
}
