#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,t=0,m=0,x,y,*ptr_x,*ptr_y,s=-1,d;
	printf("Enter the number of elements you want in the array\n");
	scanf("%d",&n);
	int arr[n];
	ptr_x= (int *)malloc(n * sizeof(int));
	ptr_y= (int *)malloc(n * sizeof(int));
	if((ptr_x == NULL)||(ptr_y == NULL))  
	{
    printf("Error! memory not allocated.");
    exit(0);
    }
	printf("Enter the %d elements in the array\n",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
    }
	printf("Enter the two elements between which the minimum distance is to be found\n");
	scanf("%d%d",&x,&y);
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			*(ptr_x+t)=i;
			t++;
		}
		else if(arr[i]==y)
		{
			*(ptr_y+m)=i;
			m++; 
		}
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<m;j++)
		{   
		    d = ((*(ptr_x + i) - *(ptr_y + j)) >= 0)?(*(ptr_x + i) - *(ptr_y + j)) : (*(ptr_y + j) - *(ptr_x + i)) ;
		    if(s==-1)
			s = d;
			else if(d<s)
			s = d;
		}
	}
	printf("\nThe minimum distance between %d and %d is %d",x,y,s);
	free(ptr_x);
	free(ptr_y);
	return 0;
} 
