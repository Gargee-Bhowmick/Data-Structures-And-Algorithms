#include <stdio.h>
#include <stdlib.h>
struct ele{
	int i;//row
	int j;//column
	int x;//values
};
struct sparse{
	int m;//total number of rows
	int n;//Total number of columns
	int num;//Total number of non zero elements
	struct ele * e;//sparse matrix array
};
void create (struct sparse * s)
{
	printf("Enter the number of rows : ");
	scanf("%d",&s->m);
	printf("\nEnter the total number of columns : ");
	scanf("%d",&s->n);
	printf("\nEnter the total number of non zero elements : ");
	scanf("%d",&s->num);
	s->e = (struct ele *)malloc(s->num * sizeof(struct ele));
	int i;
	for(i=0;i<s->num;i++)
	{
		printf("ENTER THE ROW NUMBER : ");
		scanf("%d",&s->e[i].i);
		if(s->e[i].i>s->n)
		s->m = s->e[i].i;
		printf("\nENTER THE COLUMN NUMBER : ");
		scanf("%d",&s->e[i].j);
		if(s->e[i].j>s->n)
		s->n = s->e[i].j;
		printf("\nENTER THE ELEMENT : ");
		scanf("%d",&s->e[i].x);
	}
}
void swap(int *a , int *b)
{
    int temp;
	temp = *a;
	*a = *b ;
	*b = temp;
}
void sort(struct sparse *s)
{
	int i , j;
	int temp;
	for(i=0;i<s->m;i++)
	{
		for(j=i+1;j<s->n;j++)
		{
			if((s->e[j].i<s->e[i].i))
			{
				swap(&s->e[j].i,&s->e[i].i);
				//temp = s->e[j].i;
				s->e[j].i = s->e[i].i;
				s->e[i].i = temp;
				//swap(&s->e[j].j,&s->e[i].j);
				temp = s->e[j].j;
				s->e[j].j = s->e[i].j;
				s->e[i].j = temp;
				//swap(&s->e[j].x,&s->e[i].x);
				temp = s->e[j].x;
				s->e[j].x = s->e[i].x;
				s->e[i].x = temp;
			}
			else if((s->e[j].i == s->e[i].i))
			{
				if(s->e[j].j < s->e[i].j)
				{
				//swap(&s->e[j].j,&s->e[i].j);
				//swap(&s->e[j].x,&s->e[i].x);
				//swap(&s->e[j].j,&s->e[i].j);
				temp = s->e[j].j;
				s->e[j].j = s->e[i].j;
				s->e[i].j = temp;
				//swap(&s->e[j].x,&s->e[i].x);
				temp = s->e[j].x;
				s->e[j].x = s->e[i].x;
				s->e[i].x = temp;
			}
			}
		}
	}
}
void display(struct sparse *s)
{
	int i , j , k=0;
	printf("The sparse matrix is as follows : \n");
	for(i=0;i<s->m;i++)
	{
		for(j=0;j<s->n;j++)
		{
			if((i == s->e[k].i-1)&&(j == s->e[k].j-1))
			printf("%d ",s->e[k++].x);
			else
			printf("0 ");
		}
		printf("\n");
	}
}
int main()
{
	struct sparse s;
	create(&s);
	//sort(&s);
	display(&s);
}
