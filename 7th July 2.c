#include <stdio.h>
int main()
{
	int arr[10];
	int i,temp;
	printf("Enter 10 numbers\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<=4;i++)
	{
		temp=arr[i];
		arr[i]=arr[9-i];
		arr[9-i]=temp;
	}
	printf("The reversed array is as follows\n");
	for(i=0;i<=9;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
