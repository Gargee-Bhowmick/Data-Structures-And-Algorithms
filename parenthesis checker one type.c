 #include <stdio.h>
 #include <stdlib.h>
 struct stack
 {
 	int top;
 	int capacity;
 	char * arr;
 };
 struct stack * create(int c)
 {
 	struct stack * s = (struct stack *)malloc(sizeof(struct stack));
 	s->capacity = c;
 	s->top = -1;
 	s->arr = (char *)malloc(s->capacity*sizeof(char));
 	return s;
 }
  int isFull(struct stack * s)
 {
 	return (s->top==s->capacity-1);
 }
 int isEmpty(struct stack * s)
 {
 	return (s->top==-1);
 }
 void push(struct stack * s, char x)
 {
 	if(isFull(s))
 	{
 		printf("Stack overflow!!\n");
 		exit(0) ;
	 }
 	s->arr[++s->top]=x;
 }
 void pop(struct stack * s)
 {
 	if(isEmpty(s))
 	{
 		printf("Stack underflow\n");
 		exit(0);
	 }
	 --s->top;
 }
 int peek(struct stack * s)
 {
 	if(isEmpty(s))
 	{
 		printf("Stack underflow\n");
 		return INT_MIN;
	 }
	 return (s->arr[s->top]);
 }
 int traverse (struct stack * s)
 {
 	int i;
 	for(i=0;i<=s->top;i++)
 	{
 		printf("%d ",s->arr[i]);
	 }
 }
 int parenthesis_checker(char * st , struct stack * s)
 {
 	int i = 0;
 	for(i=0;st[i]!='\0';i++)
 	{
 		if(st[i]=='(')
 		{
 			push(s , '(');
		 }
		 if(st[i]==')')
		 {
		 	pop(s);
		 }
	 }
	 if(isEmpty(s))
	 {
	 	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
 }
 int main()
 {
 	int n,a;
 	struct stack *s = create(100);
	char st[100];
    printf("Enter the expression : ");
    fflush(stdin);
    scanf("%s",st);
    a = parenthesis_checker(st , s);
    if(a==1)
    printf("Parenthesis matched ! ");
    else
    printf("Parenthesis not matched ! ");
	 return 0;
 }
