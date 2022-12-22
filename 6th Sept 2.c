#include <stdio.h>
#include<stdlib.h>
struct node 
{
	struct node * prev;
	int data;
	struct node * next;
}*head=NULL,*tail = NULL;
void create(int n)
{
	head = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data for %d nodes /n",n);
	int b;
	scanf("%d",&b);
	head->data=b;
	head->prev= NULL;
	head->next = NULL;
	tail = head;
	int i;
	for(i=1;i<n;i++)
	{
		struct node * temp;
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&b);
		temp->data = b;
		temp->prev = tail;
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
}
void display()
{
	struct node * temp;
	temp = head;
	printf("The linked list is as follows : NULL->");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}
void reverse()
{
	struct node * temp;
	temp = tail;
	printf("\nThe linked list in reverse order is as follows : NULL->");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp = temp->prev;
	}
	printf("NULL");
}
int main()
{
	int n;
	printf("Enter the number of nodes in the DLL: ");
	scanf("%d",&n);
	create(n);
	display();
	reverse();
	return 0;
}
