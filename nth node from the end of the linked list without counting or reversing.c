#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
    struct node * next;
}* head;
int n;
int create()
{
	printf("Enter the data : \n");
	struct node * temp;
	head = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->data);
	head->next = NULL;
	struct node * tail;
	int i;
	tail = head;
	for(i=1;i<n;i++)
	{
	temp = (struct node *)malloc(sizeof(struct node));	
	scanf("%d",&temp->data);
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	}
	return head->data;
}
int main()
{
	printf("Enter the value of n : \n");
	scanf("%d",&n);
	int c = create ();
	printf("Nth node from the end of the linked list is : ",c);
	return 0;
}
