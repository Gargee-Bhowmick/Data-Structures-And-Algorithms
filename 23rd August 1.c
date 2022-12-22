#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node * next;
} * head, *tail;
struct node * create (int b)
{
	struct node * temp1;
	temp1 = (struct node *)malloc(sizeof(struct node));
	temp1->data=b;
	temp1->next = NULL;
	return temp1;
}
struct node * insertion (struct node * head , struct node * tail)
{
	int b;
	scanf("%d",&b);
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp =  create (b);
	if(head == tail)
	head = temp;
	tail->next = temp;
	tail = temp;
	return tail;
}
int main()
{
	int i,n,b;
	printf("Enter thr number of elements you want in your linked list ");
	scanf("%d",&n);
	struct node * temp2;
    head = (struct node *)malloc(sizeof(struct node));
	tail = (struct node *)malloc(sizeof(struct node));
	temp2 = (struct node *)malloc(sizeof(struct node));
	head = tail;
	head->next = tail->next = NULL;
	for(i=0;i<n;i++)
	{
		tail = insertion (head , tail);
	}
    temp2 = head->next;   
	while(temp2!=NULL)
	{
		printf("%d ",temp2->data);
		temp2 = temp2->next;
	}
	return 0;
}
