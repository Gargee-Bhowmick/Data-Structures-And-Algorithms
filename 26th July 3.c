#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
	
	char name [40];
	char gender [15];
	char designation [30];
	char department [30];
	float basic_pay;
	
} emp ;

//To calculte the gross pay
inline float grossPay( float basic_pay )
{
	
	float HR , DA , gross_pay ;
	HR = 0.25 * basic_pay ;
	DA = 0.75 * basic_pay ;
	gross_pay = basic_pay + HR + DA ;//calculates the gross salary
	return gross_pay ;
	
}
//To display all the information about employee(s)
void display ( int n , emp em[] )
{
	
	int i;
	
	printf ( "\n\n\nThe details of the employee(s) is(are) as follows:\n\n" ) ;
    printf ( "Name\t\tGender\t\tDesignation\t\tDepartment\t\tBasic Pay\t\tGross Pay\n" ) ;
    
    for( i = 0 ; i < n ; i++ )
    {
    	printf ( "%s\t\t%s\t\t%s\t\t\t%s\t\t\tRs.%0.2f\t\tRs.%0.2f\n" , em[i].name , em[i].gender , em[i].designation , em[i].department , em[i].basic_pay , grossPay ( em[i].basic_pay ) );
	}
	
}
//To input information about employee(s)
void input( int n, emp em[] )
{
	
	int i;
	for(i = 0 ; i < n ; i++)
	{  
	    //Name
		printf ( "\n\nEnter the name of employee %d\n" , i + 1 ) ;
		fflush (stdin) ;
		scanf ("%[^\n]s",em[i].name) ;
		//Gender
		printf ( "\nEnter gender\n" ) ;
		fflush (stdin) ;
		scanf ("%s" , em[i].gender ) ;
		//Designation
		printf ( "\nEnter the designation\n" ) ;
		fflush (stdin) ;
		scanf("%s",em[i].designation) ;
		//Department
		printf("\nEnter the department\n");
		fflush(stdin);
		scanf("%s",em[i].department);
		//Basic Pay
		printf("\nEnter the basic pay\n");
		fflush(stdin);
		scanf("%f",&em[i].basic_pay);
		
	}
	
	display (n , em); //To display all the information
	
}


int main( )
{
	
	int n , i ;
	printf ( "Enter the number of employees whose information is to be displayed\n" ) ;
	scanf ("%d",&n) ;
	emp em[n];
	input (n,em) ;
	return 0;
	
} 
