#include<stdio.h>
int main()
{
	int i,n,c=0,d=0,t,b;
	printf("Enter the number of elements you want in an array\n");
	scanf("%d",&n);
	d=n-1;
	int arr[n];
	printf("Enter the elements in the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
	 if(arr[i]%2==0)
	 {
	   if(i>=c+1)
	   {
	   t = arr[c];
	   arr[c]=arr[i];
	   arr[i]=t;
       }
       c++;
	}	
	}
	printf("The desired array of even elements followed by odd elements are as follows");
	for(i=0;i<n;i++)
	printf("\n%d",arr[i]);
	return 0;
	
}
