#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"

int nexttoken( void );

/* undcl : convert word description to declaration */
main()
{
	int type;
	char temp[MAXTOKEN];

	while( gettoken() != EOF )
	{
		strcpy( out, token );
		while( (type = gettoken()) != '\n' )
			if( type == PARENS || type == BRACKETS )
				strcat( out, token );
			else if( type == '*' )
			{
				if( (type = nexttoken()) == PARENS ||
					type == BRACKETS )
					sprintf( temp, "(*%s)", out );
				else
					sprintf( temp, "*%s", out );
				strcpy( out, temp );
			}
			else if( type == NAME )
			{
				sprintf( temp, "%s %s", token, out );
				strcpy( out, temp );
			}
			else
				printf("invalid input at %s\n", token );

		printf("%s\n", out );
	}

	return 0;
}

int nexttoken( void )
{
	int type;
	extern int prevtoken;

	type = gettoken();
	prevtoken = YES;
	return type;
}
