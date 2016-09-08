#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"

main()	/* convert declaration to words */
{
	int i;
	while( gettoken() != EOF )	/* 1st token on line */
	{
		if( isdtype( token ) )
			strcpy( datatype, token );	/* is the datatype */
		else
		{
			printf("Data type must be 1st word.\n");
			return 0;
		}
		out[0] = '\0';
		dcl();
		if( tokentype != '\n' )
			printf("syntax error\n");
		printf("%s : %s %s\n", name, out, datatype );
	}
	return 0;
}

