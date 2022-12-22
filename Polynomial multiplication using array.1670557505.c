#include <stdio.h>
#include <stdlib.h>

struct value {
	int coeff;
	int x;
};

struct poly{
	int n;
	struct value *a;
};

struct poly * create(struct poly *p, int n)
{
	p = (struct poly *)malloc(sizeof(struct poly));
	if(p==NULL)
	{
		printf("Memory allocation failed\n");
		exit(0);
	}
	p->n = n;
	p->a = (struct value *)malloc(p->n * sizeof(struct value));
	if(p->a==NULL)
	{
		printf("Memory allocation of array failed");
		exit(0);
	}
	return p;
}

struct poly * insert (struct poly * p)
{
	printf("Enter the coefficient and exponent of the polynomial :- \n");
	int i;
	for(i=0;i<p->n;i++)
	{
		scanf("%d %d",&p->a[i].coeff,&p->a[i].x);
	}
	return p;
}

void display (struct poly * p)
{
	int i;
	for(i=0;i<p->n;i++)
	{
		printf("%dx^%d ",p->a[i].coeff,p->a[i].x);
	}
}

/*void swap(int * a , int * b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void sort (struct poly * p)
{
	int i,j;
	for(i=0;i<p->n-1;i++)
	{
		for(j=0;j<p->n-i-1;j++)
		{
			if(p->a[j].x>p->a[j+1].x)
			{
				swap(&p->a[j].coeff,&p->a[j+1].coeff);
				swap(&p->a[j].x,&p->a[j+1].x);
			}
		}
	}
}*/

void remove_duplicates(struct poly * p)
{
	int i;
	int j;
	for(i=0;i<p->n-1;i++)
	{
		for(j=i+1;j<p->n;j++)
		{
			if(p->a[j].x==p->a[i].x)
			{
				p->a[i].coeff=+p->a[j].coeff;
				p->a[j]=p->a[p->n-1];
				j=-1;
				p->n--;
			}
		}
	}
}

void multiply(struct poly * p1, struct poly * p2, struct poly * p3)
{
	int i , j , k=0;
	for(i=0 ; i<p1->n ; i++)
	{
		for(j=0;j<p2->n;j++)
		{
			p3->a[k].coeff=p1->a[i].coeff * p2->a[j].coeff;
			p3->a[k++].x = p1->a[i].x + p2->a[j].x;
		}
		
	}
}

int main()
{
	 struct poly * p1;
	 struct poly * p2;
	 struct poly * p3;
	 printf("Enter the size of the first polynomial : ");
	 int n ; int m;
	 scanf("%d",&n);
	 p1 = create(p1,n);
	 p1 = insert(p1);
	 //remove_duplicates(p1);
	 //sort(p1);
	 printf("Enter the size of the second polynomial : ");
	 scanf("%d",&m);
	 p2 = create(p2,m);
	 p2 = insert(p2);
	 //remove_duplicates(p2);
	 //sort(p2);
	 p3 = create(p3,p1->n*p2->n);
	  multiply(p1,p2,p3);
	  remove_duplicates(p3);
	 printf("The polynomial after multiplying is :");
	 display(p3);
	return 0;
}
