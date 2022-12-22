#include<stdio.h>
#include <stdlib.h>
void change (int n, int b[],int t)
{
	int i,m;
	for(i=0;i<n;i++)
	{
		if(b[i]!=t)
		{
		m=b[i];
		break;
	    }
	}
	for(i=0;i<n;i++)
	{
		if(b[i]==t)
		b[i]=m;
	}
}
	
int largest(int n, int arr[n])
{
	int i,m=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>m)
		m=arr[i];
	}
	return m;
}
int smallest(int n, int a[])
{
	int i,m = a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<m)
		m = a[i];
	}
	return m;
}
int main()
{
	int n,k,i,t,s;
	printf("Enter the number of elements you want in the array\n");
	scanf("%d",&n);
	int *arr, *a;
	arr = (int *)malloc( n * sizeof(int));
	a = (int *)malloc( n * sizeof(int));
	if(arr==NULL)
	{
	printf("Error! Memory not allocated");
	exit (0);
    }
	printf("Enter the elements in the dynamic array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	a[i]=arr[i];
	printf("Enter the kth largest you want to find in the array\n");
	scanf("%d",&k);
	t = largest (n,arr);
	s = smallest (n,a);
	for(i=2;i<=k;i++)
	{
		   change (n,arr,t);
		   t=largest(n,arr);
		   change (n , a , s);
		   s = smallest(n , a);
	}
	printf("The kth (%d) largest and smallest numbers in the array is %d and %d respectively",k,t,s);
	free (arr);
	free (a);
	return 0;
}
