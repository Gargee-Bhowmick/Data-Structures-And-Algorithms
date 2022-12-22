#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * prev;
	struct node * next;
};



struct deque{
	struct node *  front;
	struct node * rear;
	int size;
};

struct deque * create1(struct deque * d)
{
	d = (struct deque *)malloc(sizeof(struct deque));
	d->size = 0;
	d->front = d->rear = NULL;
	return d;
}

struct node * create(struct node * t)
{
	t = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	int x;
	scanf("%d",&x);
	t->data = x;
	t->prev = NULL;
	t->next = NULL;
	return t;
}



void insert_front(struct deque * d)//Have to check whether front is null or not. If yes , then assign the value of new node to both front and rear
{
     	struct node * newnode = create(newnode);
     	if(newnode == NULL)
     	{
     		printf("\nOverflow.");
     		return;
		 }
     	else if (d->front == NULL)
     	{
     		d->front = d->rear = newnode;
		 }
		 else 
		 {
		 	newnode->next = d->front;
		 	d->front->prev = newnode;
		 	d->front = newnode;
		 }
		 d->size++;
		 printf("\nThe insert front operation has been performed.");
}



void insert_rear(struct deque * d)
{
	struct node * newnode = create(newnode);
	if(newnode == NULL)
	{
		printf("\nOverflow");
	}
	else if(d->rear == NULL)
	{
		d->front = d->rear = newnode;
	}
	else
	{
		newnode->prev = d->rear;
		d->rear->next = newnode;
		d->rear = newnode;
	}
	d->size++;
	printf("\nThe insert rear operation has been performed.");
}



int delete_front(struct deque * d)
{
	int c;
	if(d->front==NULL)
	{
		printf("\nUnderflow");
		return -1;
	}
	else
	{
		struct node * e;
		e = d->front;
		 c = d->front->data;
		d->front = d->front->next;
		free(e);
		if(d->front == NULL)//if front is null , then we need to update the rear as well and make it null because this is linked list and not an array
		{
			d->rear = NULL;
		}
		else
		{
			d->front->prev = NULL;
		}
		d->size--;
	}
	printf("\nThe delete front operation has been performed");
	return c;
}



int delete_rear(struct deque * d)
{
	int c;
	if(d->rear==NULL)
	{
		printf("\nUnderflow");
		return -1;
	}
	else
	{
		struct node * t = d->rear;
		c = d->rear->data;
		d->rear = d->rear->prev;
		if(d->rear==NULL)
		{
			d->front = NULL;
		}
		else
		{
			d->rear->next=NULL;
		}
		free(t);
		d->size--;
	}
	printf("\nThe delete rear operation has been performed.");
	return c;
}



int peek(struct deque * d)
{
	if(d->front==NULL)
	{
	printf("\nUnderflow.");
	return -1;
    }
    else
    {
    	return d->front->data;
	}
}



void display(struct deque * d)
{
	if(d->front==NULL)
	{
		printf("\nUnderflow");
		return;
	}
	printf("\nThe deque is as follows : ");
	struct node * t;
	t = d->front;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t = t->next;
	}
}



int main()
{
	struct deque * d;
	d = create1(d);
	int c , x;
	while(1)
	{
	printf("\nEnter 1 for front insertion , 2 for rear insertion , 3 for front deletion , 4 for rear deletion , 5 for peeking , 6 for displaying deque , 7 for displaying the size of the deque and any other number to end the menu driven program : ");
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
			display(d);
			break;
			
		case 7:
			printf("\nThe size of the deque is %d",d->size);
			break;
			
		default:
			printf("\nThe menu driven program has ended!");
			exit(0);
	}
	printf("\n");
    }
    return 0;
}
