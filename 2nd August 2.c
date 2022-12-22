#include <stdio.h>
int main()
{
	int n,i,j,m,c=0;
	printf("Enter the number of elements you want in an array\n");
	scanf("%d",&n);
	int arr[n];
	m=arr[0];
	printf("Enter the elements in the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		if(arr[i]>m)
		{
			m = arr[i];
			c=0;
		}
	    if(arr[i]==m)
	   	c++;
	}
	printf("The largest element in the array is %d\n%d occurs %d times in the array",m,m,c);
}
