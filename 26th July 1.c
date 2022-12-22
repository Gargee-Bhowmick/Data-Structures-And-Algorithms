#include <stdio.h>
struct employee{
	int employee_id;
	char name[50];
	char designation[30];
	float salary;
};
void change (float arr[5],float t)
{
	int i;
	float m;
	for(i=0;i<5;i++)
	{
		if(arr[i]!=t)
		{
		m=arr[i];
		break;
	    }
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]==t)
		arr[i]=m;
	}
}
	
float largest( float arr[5])
{
	int i;
	float m=arr[0];
	for(i=0;i<5;i++)
	{
		if(arr[i]>m)
		m=arr[i];
	}
	return m;
}
float highest_salary(int k,struct employee e[5])
{
	float arr[5],t;
	int i;
	for(i=0;i<5;i++)
	{
		arr[i]=e[i].salary;
	}
	t=largest(arr);
		for(i=2;i<=k;i++)
	{
		   change (arr,t);
 		    t=largest(arr);
	}
	return t;
}

int main()
{
	struct employee e[5];
	int i,k,t=0;
	float j;
	for(i=0;i<5;i++)
	{
		printf("\nEnter the employee id of employee %d\n",i+1);
		scanf("%d",&e[i].employee_id);
		fflush(stdin);
		printf("Enter the name\n");
		scanf("%[^\n]s",e[i].name);
		fflush(stdin);
		printf("Enter the designation\n");
		scanf("%[^\n]s",e[i].designation);
		fflush(stdin);
		printf("Enter the salary\n");
		scanf("%f",&e[i].salary);
	}
	printf("\nEnter the value of k for kth highest salary\n");
	scanf("%d",&k);
	j=highest_salary(k,e);
	printf("The employees with the highest salary are as follows\n");
	for(i=0;i<5;i++)
	{
		if(e[i].salary==j)
		{
			t++;
			printf("%d) Employee_id\t\t%d\n Name\t\t\t%s \n Designation\t\t%s\n Salary\t\tRs.%f\n\n",t,e[i].employee_id,e[i].name,e[i].designation,e[i].salary);
		}
	}
	return 0;
}
