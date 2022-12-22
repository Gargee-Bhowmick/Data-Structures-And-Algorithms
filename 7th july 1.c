 #include<stdio.h>
int main()
{
	int arr[10];
	int i,max,min;
	printf("Enter 10 numbers\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&arr[i]);
	}
	min=max=arr[0];
	for(i=0;i<=9;i++)
	{
		if(arr[i]<=min)
		min=arr[i];
		if(arr[i]>=max)
		max=arr[i];
	}
	printf("The largest number in the array is %d and the smallest number in the array is %d",max,min);
	return 0;
}
