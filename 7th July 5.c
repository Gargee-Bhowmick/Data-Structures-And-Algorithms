#include<stdio.h>
int main()
{
	int i,n,a,b,t=0,m=0,c,d=0;
	printf("Enter the number of elements in the array and the two numbers which are to be taken as limits");
	scanf("%d%d%d",&n,&a,&b);
	printf("Enter %d numbers\n",n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if((arr[i]==a)&&(t==0))
		t=i;
		if((arr[i]==b)&&(m==0))
		m=i;
	}
	if((t==0)||(m==0)){
		printf("0");
		return 0;
	}
	c=(t>m)?t:m;
	t=(t<m)?t:m;
	printf("The number of elements between %d and %d are ",arr[t],arr[c]);
    for(i=0;i<n;i++)
    {
    	if((i>=t)&&(i<=c))
    	{
    		d++;
		}
    }
	printf("%d",d);
	return 0;
}
