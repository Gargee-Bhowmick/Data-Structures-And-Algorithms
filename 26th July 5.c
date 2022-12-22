#include <stdio.h>
int main()
{
	int i,t=2;
	char s[]="India stands for Unity";
	for(i=0;i<23;i++)
	{
		if(t%2==0)
		{
			printf("%c",s[i]);
	    }
	    		if(s[i]==' ')
		{
		    t++;
		    printf(" ");
		}
	}
	return 0;
}
