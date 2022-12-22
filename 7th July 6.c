#include<stdio.h>
int main()
{
    int i,j,n,t=0,m;
    printf("Enter the number of elements you want in an array ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements in the array\n",n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }
	printf("The next largest element for every element (on the right hand side of it)are as follows\n Element\tNGE\n");
	for(i=0;i<n;i++)
	{
		t=0;
	 for(j=i+1;j<n;j++)
	 {
	 	if(arr[j]>arr[i])
	 	{
	 	printf("  %d\t\t%d\n",arr[i],arr[j]);
	 	t++;
	 	break;
	    }
	 }
	if(t==0)
	 printf("  %d\t\t-1\n",arr[i]);
	}
	return 0;
}
