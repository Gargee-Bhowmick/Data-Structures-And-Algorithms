 #include<stdio.h>
int main()
{
	int arr[10];
	int i,n,t=0;
	printf("Enter 10 numbers\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched ");
	scanf("%d",&n);
	for (i=0;i<=9;i++)
	{
		if(arr[i]==n)
		{
			if(t==0)
			{
				printf("The element is there in index ");
			}
			printf("%d ",i);
			t++;
		}
	}
	if(t==0)
	{
		printf("The element is not present in the array");
	}
	return 0;
}
