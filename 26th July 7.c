#include <stdio.h>
int main()
{
	int i,t=0;
	char s[1000],c;
	printf("Enter the string\n");
   scanf("%[^\n]s",s);
   fflush(stdin);
   printf("Enter the character whose occurrence is to be found out\n");
   scanf("%c",&c);
	for(i=0;s[i]!='\0';i++)
	{
	if(s[i]==c)
	{
		t++;
	}
	}
	printf("The character %c occurs %d times in the string",c,t);
	return 0;
}
