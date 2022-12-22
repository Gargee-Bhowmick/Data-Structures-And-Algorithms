#include <stdio.h>
struct distance{
	float a;
	float b;
};
void add(struct distance d,char c,char e)
{
	printf("The total distance is ");
	if(c==e)
	{
		if(c=='k')
		printf("%dkm",d.a+d.b);
		else 
		printf("%dm",d.a+d.b);
	}
	else 
	{
		if (c=='k')
		printf("%fm",(d.a/1000.00)+d.b);
		else
		printf("%fm",d.a+(d.b/1000.00));
	}
}
int main()
{
	struct distance d;
	char c,e;
	printf("Enter the first distance\n");
	scanf("%f",&d.a);
	printf("Enter m for metre or k for kilometre\n");
	fflush(stdin);
	scanf("%c",&c);
	fflush(stdin);
	printf("Enter the second distance\n");
	scanf("%f",&d.b);
	printf("Enter m for metre or k for kilometre\n");
	fflush(stdin);
	scanf("%c",&d);
	add(d,c,e);
	return 0;
	}
