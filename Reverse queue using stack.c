#include <stdio.h>
#include <stdlib.h>
	struct stack{
	int top;
	int capacity;
	int * s;
	int a[100];
	};
	struct queue{
		int front;
		int rear;
		int capacity;
		int * q;
	};
 //create(struct stack *s, struct queue *q)
struct stack * create ( int n)
{
	struct stack * s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = -1;
	s->capacity = n;
	s->s = (int *)malloc(s->capacity * sizeof(int));
	return s;
}
struct queue * create1 (int n)
{
	struct queue * q;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	q->capacity = n;
	q->q = (int *)malloc(q->capacity * sizeof(int));
	return q;
}
void push(struct stack * s , int n)
{
	s->s[++s->top] = n;
}
int pop(struct stack * s)
{
	return s->s[s->top--];
 } 
 void push1(struct queue * q , int n)
{
	if(q->front = -1)
	{
		q->front = 0;
	}
	q->q[++q->rear] = n;
}
int pop1(struct queue * q )
{
	return q->q[q->front++];
}
void display( struct stack * s)
{
	int i;
	for(i=s->capacity-1;i>=0;i--)
	{
		printf("%d ",s->s[i]);
	}
}
int main()
{
	int n;
	struct stack * s;
	struct queue * q;
	int i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	s = create (n);
	q = create1(n);
	printf("Enter the elements : \n");
	int a;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a);
		push(s , a);
	}
	printf("Before reversing : ");
	display(s);
	for(i=0 ; i<n ; i++)
	{
		push1(q , pop(s));
	}
	for(i=0;i<n;i++)
	{
		push(s , pop1(q));
	}
	printf("\nAfter reversing : ");
	display(s);
	return 0;
}
