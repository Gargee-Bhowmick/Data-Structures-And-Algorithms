#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
}*head=NULL;

void create(int n)
{
	if(n==0)
	return;
	printf("Enter the data for the first node: ");
	int b;
	head = (struct node *)malloc(sizeof(struct node));
	struct node * tail;
	tail = head;
	scanf("%d",&b);
	head->data = b;
	head->next = NULL;
	int i;
	struct node * temp;
	printf("Enter the data for the next nodes :\n");
	for(i=1;i<n;i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&b);
		temp->data = b;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

void display()
{
	printf("\nThe linked list is as follows : ");
	struct node * temp;
	temp= head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

void removeDuplicates()
{
	struct node * temp , * next;
	temp = head;
	next = head->next;
	int a = head->data;
	if(head==NULL)
	{
		printf("\nEmpty list");
		return;
	}
	while(head->next->data == a)
	{
		head = head->next;
	}
	temp = head;
	next = head->next;
	while(temp->next!=NULL)
	{
		if(temp->data == next->data)
		{
			temp->next = next->next;
		}
		if(temp->next!=NULL)
		{
		temp = temp->next;
		next = temp->next;
	}
}

}

int main()
{
	int n;
	printf("Enter the number of elements you want in a linked list (in a sorted way in asceding order) : ");
	scanf("%d",&n);
	create(n);
	display();
	removeDuplicates();
	display();
	return 0;
