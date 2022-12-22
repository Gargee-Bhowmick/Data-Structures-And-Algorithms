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
	printf("Enter the data for %d nodes \n",n);
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
void insertBeg()
{
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data you want to insert : ");
	int b;
	scanf("%d",&b);
	temp->data = b;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
}
void insertEnd()
{
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data you want to insert : ");
	int b;
	scanf("%d",&b);
	temp->data = b;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	temp->next = NULL;	
}
void insertMid(int n , int c)
{
	if(head == NULL)
	{
		printf("\nEmpty list");
		return;
	}
	if((c==0)||(c==1))
	{
		insertBeg();
		return;
	}
	else if(c>n)
	{
		insertEnd();
		return;
	}
	c = c-2;
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data you want to insert : ");
	int b;
	scanf("%d",&b);
	temp->data = b;
	struct node * temp2;
	temp2 = head;
	while(c--)
	{
	temp2 = temp2->next;
    }
    struct node * temp3;
    temp3 = temp2->next;
    temp2->next = temp;
    temp->prev  = temp2;
    temp3->prev = temp;
    temp->next = temp3;
}
void deleteBeg()
{
	struct node * temp;
	temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}
void deleteEnd()
{
	struct node * temp = tail;
	tail->prev->next = NULL;
	free(temp);
}
void deleteMid(int n , int c)
{
	if(head == NULL)
	{
		printf("\nEmpty list");
		return;
	}
	if((c==0)||(c==1))
	{
		deleteBeg();
		return;
	}
	else if(c>n)
	{
		deleteEnd();
		return;
	}
	c = c-2;
	struct node * temp;
	temp = head;
	while(c--)
	{
	temp = temp->next;
    }
    if(temp->next->next!=NULL)
    {
    temp->next = temp->next->next;
    temp->next->prev = temp;
    }
    else
    {
    	temp->next = NULL;
	}
}
void deleteKey(int x)
{
    if (!head)
    {
    printf("\nList is empty");
    return;
    }
    while (head && head->data == x)
    {   
	    struct node * temp;
        temp = head;
        head = head->next;
        free(temp);
    }
    struct node *curr = head, *prev = NULL;
    while (curr!=NULL) {
        if (curr->data == x)
        {
            prev->next = curr->next;
            curr->prev = prev;
        }
        else
            prev = curr;
        curr = curr->next;
    }
}
void empty()
{
    if(head == NULL)
    {
        printf("\nThe linked list is empty");
    }
    else
    {
        printf("\nThe linked list is not empty");
    }
}
void count() 
 {
     int i = 0;
     struct node * temp4;
     temp4=head;
     while(temp4!=NULL)
     {
         i++;
         temp4 = temp4->next;
     }
     printf("\nThere are %d number of nodes",i);
 }
void search(int s)//g)search of a particular data is present
 {
     struct node * temp;
     temp = head;
     while(temp!=NULL)
     {
         if(temp->data==s)
         {
             printf("\nRESULT FOUND!!");
             return;
         }
         temp=temp->next;
     }
     printf("\nResult not found!");
 }
int main()
{
	int n;
	printf("Enter the number of nodes in the DLL: ");
	scanf("%d",&n);
	create(n);
	display();
	reverse();
	empty();
	printf("\nEnter where you want to insert the data : ");
	int i;
	scanf("%d",&i);
	insertMid(n,i);
	display();
	printf("\nEnter where you want to delete the node : ");
	scanf("%d",&i);
	deleteMid(n,i);
	display();
	printf("\nEnter the data to be deleted : ");
	scanf("%d",&i);
	deleteKey(i);
	display();
	printf("\nEnter the data you want to be searched : ");
	int s;
	scanf("%d",&s);
	count();
	search(s);
	return 0;
}
