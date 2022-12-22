#include <stdio.h>
#include <stdlib.h>
struct sparse
{
	struct sparse * prev;
	int r;
	int c;
	int v;
	struct sparse * next;
}*head,*tail;
void create(int *m, int *n)
{
	int i;
	head = NULL;
	tail = NULL;
	struct sparse * temp;
	printf("Enter -1 to stop giving input\n ");
	for(i=0;;i++)
	{
	temp = (struct sparse *)malloc(sizeof(struct sparse));
	printf("Enter the row column and value of element %d : \n",i+1);
	scanf("%d%d%d",&temp->r,&temp->c,&temp->v);
	if(temp->r>*m)
	*m = temp->r;
	if(temp->c>*n)
	*n = temp->c;
	if((temp->r == -1)||(temp->c==-1))
	break;
	if(i==0)
	{
	head = tail = temp;
	head->prev = NULL;
	head->next = NULL;
    }
    else
    {
    	tail->next = temp;
    	temp->prev = tail;
    	tail = tail->next;
    	tail->next = NULL;
	}
	}
}
void display()
{
   	struct sparse * temp;
   	temp = head;
   	while(temp!=NULL)
   	{
   	printf("%d\t%d\t%d\n",temp->r,temp->c,temp->v);
	   temp=temp->next;	
    }
}
int main()
{
   int m=0,n=0;
   create(&m,&n);
   display();
   return 0;	
}
