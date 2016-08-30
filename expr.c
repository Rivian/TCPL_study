#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "rpolish.h"

main( int argc, char *argv[] )
{
	int i, type, iop1, iop2;
	double op2;
	char s[MAXOP];

	if( argc < 2 )
	{
		printf("Usage : expr operand operator ...\n");
		return 0;
	}

	while( --argc > 0 )
	{
		// viewstack();
		ungets(" ");
		ungets( *++argv );

		switch( type = getop(s) )
		{
			case NUMBER :
				push( atof(*argv) );
				break;
			case MNUMBER :
				push( atof(*argv) * -1.0 );
				break;
			case '+' :
				push( pop() + pop() );
				break;
			case '*' :
				push( pop() * pop() );
				break;
			case '-' :
				op2 = pop();
				push( pop() - op2 );
				break;
			case '/' :
				op2 = pop();
				if ( op2 != 0.0 )
					push( pop() / op2 );
				else
					printf("error : divided by zero.\n" );
				break;
			case '%' :
				iop2 = pop();
				iop1 = pop();
				if ( op2 != 0.0 )
					push( iop1 % iop2 );
				else
					printf("error : divided by zero.\n" );
				break;
			default :
				printf("error : invalid argument %s\n", *argv);
				break;
		}
	}
	printf("\t%.8g\n", pop() );
	return 0;
}	

int gettype( char a[] )
{
	int i, c, next, ret;

	ret = NUMBER;
	if( !isdigit(a[0]) && a[0]!='-' )
	{
		printf("return = %c\n", a[0] );
		return a[0];
	}

	i = 0;

	if( a[0] == '-' )
	{
		if( isdigit(a[1]) )
			ret = MNUMBER;
		else
			return a[0];
	}

	return ret;
}
