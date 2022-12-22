#include <stdio.h>
int length(char w[])
{
	int i,c=0;
	for(i=0;;i++)
	{
		if(w[i]=='\0')
		break;
		else 
		c++;
	}
	return c;
}
int main()
{
	int i,t=0;
	char s[1000],c;
	printf("Enter the string\n");
   scanf("%[^\n]s",s);
   int m = length(s);
   printf("The string in reverse order is as follows\n");
	for(i=m-1;i>=0;i--)
	{
		printf("%c",s[i]);
	}
	return 0;
}
