#include <stdio.h>
#include <stdlib.h>

struct ele
{
int r;
int c;
int x;	
};

struct sparse 
{
	int m;
	int n;
	int num;
	struct ele * e;  
};

void create(struct sparse * s)
{
	printf("Enter the total number of rows and columns in a sparse matrix: ");
	scanf("%d%d",&s->m,&s->n);
	printf("Enter the number of non - zero elements in the sparse matrix: ");
	scanf("%d",&s->num);
	s->e = (struct ele *)malloc(s->num*sizeof(struct ele));
	int i;
	printf("Enter the row number, column number and value respectively for each element in format - r c v: \n");
	for(i=0;i<s->num;i++)
	{
		scanf("%d %d %d",&s->e[i].r,&s->e[i].c,&s->e[i].x);
	}
}

struct sparse transpose(struct sparse *s)
{
	struct sparse t;
	t.m = s->n;
	t.n = s->m;
	t.num = s->num;
	t.e = (struct ele *)malloc(s->num * sizeof(struct ele));
	int i;
	for (i=0;i<s->num;i++)
	{
		t.e[i].r = s->e[i].c;
		t.e[i].c = s->e[i].r;
		t.e[i].x = s->e[i].x;
	}
	return t;
}

void swap(int * a, int * b)
{
	int t;
	t = *a; 
	*a = *b;
	*b = t;
}

void sort (struct sparse * s)
{
    int i, j;
    for (i = 0; i < s->num - 1; i++)
     {
	 
        for (j = 0; j < s->num - i - 1; j++)
        { 
            if (s->e[i].r > s->e[j].r)
            {
                swap(&s->e[i].r, &s->e[j].r);
                swap(&s->e[i].c, &s->e[j].c);
                swap(&s->e[i].x, &s->e[j].x);
            }
            else if(s->e[i].r == s->e[j].r)
            {
            	if(s->e[i].c > s->e[j].c)
            	{
            	swap(&s->e[i].c, &s->e[j].c);
                swap(&s->e[i].x, &s->e[j].x);
				}
			}
        }
      }
}

void display(struct sparse *s)
{
	int i,j,k=0;
	for(i=0;i<s->m;i++)
	{
		for(j=0;j<s->n;j++)
		{
			if((s->e[k].r==i)&&(s->e[k].c==j))
			{
				printf("%d ",s->e[k++].x);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main()
{
	struct sparse m;
	create(&m);
	//sort(&m);
	printf("The sparse matrix is as follows : \n");
	display(&m);
	struct sparse t;
	t = transpose(&m);
	sort(&t);
	printf("The transpose of the spaese matrix is as follows : \n");
	display(&t);
	return 0;
}
