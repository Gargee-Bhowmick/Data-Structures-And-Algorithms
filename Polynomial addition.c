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
}

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
				p->a[p->n-1]=p->a[j];
				p->n--;
			}
		}
	}
}*/

int add(struct poly * p1, struct poly * p2, struct poly * p3)
{
	int i=0, j=0 , k=0,t1,t2;
	t1 = p1->n;
	t2 = p2->n;
	while((i!=t1) && (j!=t2))
	{
		 if(p1->a[i].x>p2->a[j].x)
		 {
		 	p3->a[k++]=p1->a[i++];
		 }
		 else if(p2->a[j].x>p1->a[i].x)
		 {
		 	p3->a[k++]=p2->a[i++];
		 }
		 else if(p1->a[i].x==p2->a[j].x)
		 {
		 	p3->a[k]=p1->a[i];
		 	p3->a[k++].coeff=p1->a[i++].coeff + p2->a[j++].coeff;
		 }
	 } 
	 while(i!=t1)
	 {
	 	p3->a[k++] = p1->a[i++];
	 }
	 while(j!=t2)
	 {
	 	p3->a[k++]= p2->a[j++];
	 }
	 return k;
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
	 p3 = create(p3,p1->n+p2->n);
	 int k = add(p1,p2,p3);
	 p3->n = k;
	 printf("The polynomial after adding is :");
	 display(p3);
	return 0;
}
