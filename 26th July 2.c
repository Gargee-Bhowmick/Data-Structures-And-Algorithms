#include <stdio.h>
typedef short int si;
typedef unsigned short int usi;
typedef struct time
{
	si hour;
	si minute;
	si second;
} tm;
tm t[2];
//To find the absolute value 
si abst( si a )
{
	return ( (a > 0) ? a : -a ) ;
}
//To find the difference in time in 24 hour clock format
void difference(tm t[])
{
	printf("The difference in time is %hi hours, %hi minutes and %hi seconds" , abst (t[0].hour - t[1].hour ) , abst ( t[0].minute - t[1].minute ) , abst ( t[0].second - t[1].second ) );
	
}
//To find the difference in the 12 hour format
void convert ( tm t[] , char c , char d)
{
	if(( c == 'p' ) && ( t[0].hour != 12 ))
		t[0].hour = t[0].hour + 12 ;
    if (( d == 'p' ) && ( t[1].hour != 12 ))
	    t[1].hour = t[1].hour + 12 ;
    if (( c == 'a' ) && ( t[0].hour == 12 ))
    	t[0].hour = 24;
    if (( d == 'a' ) && ( t[1].hour == 12 ))
        t[1].hour  = 24;
    difference (t);
}
//Main function
int main()
{
	usi i ; si f[2];
	char c[2];
	for( i = 0 ; i < 2 ; i++ )
	{
		printf("Enter 12 for 12-hour format or 24 for 24-hour format for time %hi\n" , i + 1) ;
		scanf("%hu" , &f[i]) ;
		printf("Enter time %d in hh:mm:ss format\n" , i + 1) ;
		scanf("%hi:%hi:%hi" , &t[i].hour , &t[i].minute , &t[i].second) ;
		if((t[i].hour>f[i]) || (t[i].minute >= 60) || (t[i].second >= 60))
		{
			printf("Please enter in the valid format\n\n");
			main();
		}
		if(f[i]==12)
		{
			printf("Enter a for am or p for pm\n") ;
			fflush(stdin);
			scanf("%c" , &c[i]) ;
		}
	 } 
	 if((f[0] == 24) && (f[1] == 24))
        difference(t) ;
     else if ((f[0] == 12) && (f[1] == 12))
        convert(t , c[0] , c[1]);
	 else if(f[0] == 12)
	    convert(t , c[0], '0') ;
	 else if(f[1] == 12)
	    convert(t , '0' , c[1]) ;
	 return 0 ;
}
