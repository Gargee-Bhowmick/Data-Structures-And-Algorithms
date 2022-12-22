#include<stdio.h>
int main()
{
	int i,n,c=0,d=0,t,b;
	printf("\n\nEnter the number of elements you want in an array\n");
	scanf("%d",&n);
	d=n-1;
	int arr[n];
	printf("Enter the 0s and 1s in a random oder in the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if((arr[i]!=0)&&(arr[i]!=1))
		{
			printf("\nThe array can only consist of 0s and 1s");
			main();
		}
	}
	for(i=0;i<n;i++)
	{
	 if(arr[i]==0)
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
	printf("The desired array of 0s followed by 1s are as follows\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
	
}
