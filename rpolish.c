#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "rpolish.h"

main()
{
	int type, iop1, iop2;
	double op2;
	char s[MAXOP];

	while( (type = getop(s)) != EOF )
	{
		viewstack();
		switch( type )
		{
			case NUMBER :
				push( atof(s) );
				break;
			case MNUMBER :
				push( atof(s) * -1.0 );
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
			case '\n' :
				printf("\t%.8g\n", pop() );
				break;
			case 't' :
				topstack();
				break;
			case 'c' :
				clearstack();
				break;
			default :
				printf("error : unknown command %s\n", s);
				break;
		}
	}
	return 0;
}	

