#include <stdio.h>
#include <stdlib.h>
struct stack{
	int top;
	int capacity;
	int * c;
} * s;
struct stack * create ()
{
	struct stack * s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = -1;
	s->capacity = 100;
	s->c = (int *)malloc(s->capacity * sizeof(int));
	return s;
}
int isEmpty()
{
	return (s->top == -1);
}
void push(char p)
{
	s->c[++s->top] = p;
}
char pop ()
{
	if(isEmpty())
	{
	   return '#';
	}
	return s->c[s->top--];
}
int isOperand(char p)
{
	return (((p>=65)&&(p<=90))||((p>=97)&&(p<=122)));
}
int peek()
{
	return s->c[s->top];
}
int priority (char c)
{
	switch (c)
	{
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
			return 2;
		case '^': 
		    return 3;
	}
		return -1;
}
int convert (char * c)
{
	int i , k=-1; 
	for(i=0;c[i]!='\0';++i)
	{
		if(isOperand(c[i]))
		{
			c[++k]=c[i];
		}
		else if(c[i]=='(')
		push(c[i]);
		else if(c[i]==')')
		{
			while((!isEmpty())&&(peek()!='('))
			{
				c[++k] = pop();
			}
			if(!isEmpty()&&(peek()!='('))
			{
			    return -1;
			}
			else
			pop();
		}
        else 
        {
        	while((!isEmpty()) && (priority(c[i])<=priority(peek())))
        	{
        		c[++k] = pop();
			}
			push(c[i]);
		}
	}
	c[++k]='\0';
}
int main(){
	char * c;
	c = (char *)malloc(100 * sizeof(char));
	s = create();
	printf("Enter the expression : ");
	fflush(stdin);
	scanf("%s",c);
	int k;
	k = convert(c);
	printf("The scanned expression is : ");
    int i;
     printf("%s",c);
	free(c);
	free(s);
	return 0;
}
