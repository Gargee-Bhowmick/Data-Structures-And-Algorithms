#include <stdio.h>//circular deque using double liked list
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};
struct cdq {
	struct node * front;
	struct node * rear;
	int size;
};
struct cdq * create1(struct cdq * q)
{
	q = (struct cdq *)malloc(sizeof(struct cdq));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}
struct node * create(struct node * t ,struct cdq * q)
{
	t = (struct node *)malloc(sizeof(struct node));
	t->next = q->front;
	printf("Enter the data in the linked list : ");
	scanf("%d",&t->data);
	return t;
}
void insert_front(struct cdq * q)
{
	struct node * newnode = create(newnode , q);
	if(newnode == NULL)
	{
		printf("\nQueue overflow");
		return;
	}
	else if(q->front == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		newnode->next = q->front;
		q->front = newnode;
	}
	q->size++;
}
void insert_rear(struct cdq * q)
{
	struct node * newnode = create(newnode , q);
	if(newnode == NULL)
	{
		printf("\nQueue Overflow");
	}
	else if(q->rear == NULL)
	{
		q->front = q->rear = newnode;
	}
	else 
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

int delete_front(struct cdq * q)
{
	int c;
	if(q->front==NULL)
	{
		printf("\nUnderflow.");
		return -1;
	}
    else if(q->front==q->rear)
    {
    	c = q->front->data;
    	q->front = q->rear = NULL;
	}
	else
	{
		c = q->front->data;
		struct node * t = q->front;
		q->front = q->front->next;
		q->rear->next = q->front;
		free(t);
		t = NULL;
	}
	q->size--;
	return c;
}

int delete_rear(struct cdq * q)
{
	int c;
	if(q->rear == NULL)
	{
		printf("\nUnderflow");
		return -1;
	}
    else if(q->front==q->rear)
    {
    	c = q->rear->data;
    	q->front = q->rear = NULL;
	}
	else
	{
		c = q->rear->data;
		struct node * t = q->front;
		do{
			t=t->next;
		}while(t->next!=q->rear);
		struct node * s = q->rear;
		q->rear = t;
		t->next = q->front;
		free(s);
		s = NULL;
	}
	q->size--;
	return c;
}

int peek(struct cdq* q)
{
	if(q->front == NULL)
	{
		printf("\nUnderflow");
		return -1;
	}
	return q->front->data;
}

void display (struct cdq * q)
{
	if(q->front==NULL)
	{
	printf("\nUnderflow");
	return;
}
	struct node * t = q->front;
	do{
		printf("%d -> ",t->data);
		t = t->next;
	}while(t->next!=q->front);
	printf("%d",t->data);
}

int main()
{
	struct cdq * d;
	d = create1(d);
	int c , x;
	while(1)
	{
	printf("\nEnter 1 for front insertion , 2 for rear insertion , 3 for front deletion , 4 for rear deletion , 5 for peeking , 6 for displaying deque , 7 for size and any other number to end the menu driven program : ");
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
			
		case 7:
			printf("Size = %d",d->size);
			break;
			
		default:
			printf("\nThe menu driven program has ended!");
			exit(0);
	}
    }
    return 0;
}
