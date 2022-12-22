//This is queue representation using array. It is not that realistic as array is static and we cannot utilise memory to the fullest
//CIRCULAR QUEUE
//Circular queue in array representation is basically a normal array with filling from both sides when required.
//Circular queue in linked list is different. It is easier and more ergonomical to implement a circular queue using linked list as insertion and deletion are quite easier and there is hardly any space bounds!! 
//This is because linked list is a dynamic data structure.
#include <stdio.h>
#include <stdlib.h>



struct queue {
	int *a;
	int front;
	int rear;
	int capacity;
};



struct queue * create();//creates the circular queue
void enqueue(struct queue * , int);//enqqueues the element in the queue
void dequeue(struct queue *);//returns the element that has been dequeued
int isFull(struct queue *);//returns 1 if the queue is full
int isEmpty(struct queue *);//returns 1 if the queue is empty
int peek(struct queue *);//Returns element with the index of front



struct queue * create ()
{
	struct queue * q;
	q = (struct queue *)malloc(sizeof(struct queue));
	printf("Enter the capacity of the queue : ");
	scanf("%d",&q->capacity);
	q->front = 0;
	q->rear = 0;
	q->a = (int *)malloc(q->capacity * sizeof(int));
	return q;
}



int isFull(struct queue * q)
{
	if((q->front == q->rear + 1)||((q->front ==0)&&(q->rear==q->capacity-1)))//condition for circular queue to be full
	{
		 return 1;
	}
	return 0;
}



int isEmpty(struct queue * q)
{
	if(q->front == q->rear)//condition for circular queue to be empty
	{
		return 1;
	}
	return 0;
}



void enqueue (struct queue * q, int x)
{
	if(!isFull(q))
	{
		q->rear = (q->rear + 1)%q->capacity;
		q->a[q->rear]=x;
	}
	else 
	{
		printf("Queue overflow");
	}
}



void dequeue (struct queue * q)
{
	if(!isEmpty(q))
	{
			q->front = (q->front + 1)%q->capacity;
			q->a[q->front] = -1;
	}
	else
	{
		printf("\nQueue Underflow");
		q->front = 0;
		q->rear = 0;
	}
}
 

 
int peek(struct queue * q)
{
	if(!isEmpty)
	{
		return q->a[(q->front + 1)/q->capacity];
	}
	else
	{
		printf("\nQueue underflow");
	}
}



void display(struct queue * q)
{
	int i;
	for(i=0;i<q->capacity;i++)
	{
		printf("%d ",q->a[i]);
	}
}



int main()
 {
 	struct queue * q;
 	q = create();
 	int i;
 	for(i=0;i<q->capacity;i++)
 	{
 		q->a[i] = -1;
	 }
	 int c = 1;
	 while((c>=0)&&(c<=4))
	 {
 	printf("\nEnter 1 for enqueue , 2 for dequeue , 3 for peek , 4 for traverse , and any other number to end the menu-driven program: ");
 	printf("\nEnter your choice : ");
 	scanf("%d",&c);
 	switch(c)
 	{
 		case 1:
 			printf("\nEnter the number to enqueue : ");
 			int x;
 			scanf("%d",&x);
 			enqueue(q , x);
 			printf("\nThe enqueue operation has been performed.");
 			break;
 		case 2:
 			dequeue(q);
 			printf("\nThe dequeue operation has been performed.");
 			break;
 		case 3:
 			printf("\nThe element in the front is : ",peek(q));
 		    break;
 		case 4:
 			display(q);
 			break;
 		default: 
 		    printf("\nThe menu driven program has ended!");
 		    break;
 		
	 }
 }
 return 0;	
 }
