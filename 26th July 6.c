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
   char s[1000],t[1000],a,b; 
   int i;
   printf("Enter the first chracter array\n");
   scanf("%[^\n]s",s);
   fflush(stdin);
   printf("Enter the second character array\n");
   scanf("%[^\n]s",t);
   int u=length(s);
   int v = length(t);
   a=(u>v)?u:v;
   printf("The altered word is \n");
   for(i=0;i<a;i++)
   {
   	if(u>=v)
   	{
   		if(i<v)
   		printf("%c%c",s[i],t[i]);
   		else
   		printf("%c",s[i]);
	   }
	else
	{
		if(i<u)
		printf("%c%c",s[i],t[i]);
		else
		printf("%c",t[i]);
	}
   }
	return 0;
}
