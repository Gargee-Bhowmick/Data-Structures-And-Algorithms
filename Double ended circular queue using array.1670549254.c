#include <stdio.h>
#include <stdlib.h>

struct cdq{
	int front;
	int rear;
	int capacity;
	int * a;
};

struct cdq * create (struct cdq * q)
{
	q = (struct cdq *)malloc(sizeof(struct cdq));
	q->front = 0;
	q->rear = 0;
	printf("\nEnter the capacity of the double ended circular queue : ");
	scanf("%d",&q->capacity);
	q->a = (int *)malloc(sizeof(int));
}


int isFull(struct cdq * q)
{
	return (q->front == (q->rear + 1)%q->capacity);
}


int isEmpty(struct cdq *q)
{
	return (q->front == q->rear);
}


void insert_front(struct cdq * q)
{
     if(isFull(q))
     {
     	printf("\nQueue overflow.");
     	return;
	 }
	 printf("\nEnter the number to insert at front : ");
	 int x;
	 scanf("%d",&x);
	 if(q->front==0)
	 {
	 	q->front = q->capacity-1;
	 }
	 else 
	 {
	 	q->front  = q->front -1;
	 }
	 q->a[q->front] = x;
	 printf("\nThe insert at front operation has been performed");
}


void insert_rear(struct cdq * q)
{
	if(isFull(q))
	{
		printf("\nQueue overflow");
		return;
	}
	printf("\nEnter the number you want to insert at back : ");
	int x;
	scanf("%d",&x);
	q->rear = (q->rear+1)%q->capacity;
	q->a[q->rear] = x;
	printf("\nThe insertion operation at rear has been performed");
}


int delete_front(struct cdq * q)
{
	if(isEmpty(q))
	{
		printf("\nQueue underflow.");
		return -1;
	}
	int c;
	c = q->a[q->front];
	q->front = (q->front+1)%q->capacity;
	printf("\nThe delete at front operation has been performed");
	return c;
}


int delete_rear(struct cdq * q)
{
	if(isEmpty(q))
	{
	printf("\nQueue underflow.");
	return -1;
	}
	int c;
	c = q->a[q->rear];
	if(q->rear==0)
	{
		q->rear = q->capacity-1;
	}
	else
	{
		q->rear = q->rear-1;
	}
	printf("\nThe delete at rear operation has been performed");
	return c;
}

void display(struct cdq * q)
{
	int i;
	i = (q->front+1)%q->capacity;
	do{
		printf("%d ",q->a[i]);
		if(((i<q->rear)&&(q->front<q->rear)))
		{
			printf("<-");
		}
		else if (q->front>q->rear)
		{
			if(i<q->rear)
			{
				printf("<-");
			}
	 		else if(i>q->rear)
			{
				printf("->");
			}
		}
		i = (i+1)%q->capacity;
	}while(i<=q->rear);
}

int peek(struct cdq * q)
{
	if(isEmpty(q))
	{
		printf("\nQueue Underflow");
		return -1;
	}
	return q->a[(q->front+1)%q->capacity];
}


int main()
{
	struct cdq * d;
	d = create(d);
	int c , x;
	while(1)
	{
	printf("\nEnter 1 for front insertion , 2 for rear insertion , 3 for front deletion , 4 for rear deletion , 5 for peeking , 6 for displaying deque and any other number to end the menu driven program : ");
	printf("Enter your choice : ");
	scanf("%d",&c);
	switch (c)
	{
		case 1: 
		insert_front(d);
		break;
		
		case 2:
		insert_rear(d);
		break;
			
		case 3:
			delete_front(d);
			break;
			
		case 4:
			delete_rear(d);
			break;
			
		case 5:
			printf("\nThe element at the front is : %d",peek(d));
			break;
			
		case 6:
			printf("\nThe deque is as follows : ");
			display(d);
			break;
			
		default:
			printf("\nThe menu driven program has ended!");
			exit(0);
	}
    }
    return 0;
}
