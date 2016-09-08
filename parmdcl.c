#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTOKEN	1000

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl( void );
void errmsg( char * );
int gettoken( void );

void dclspec( void );
int typespec( void );
int typequal( void );
int compare( char **, char ** );

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];
extern int prevtoken;

/* parmdcl : parse a parameter declarator */
void parmdcl( void )
{
	do
	{
		dclspec();
	}
	while( tokentype == ',' );

	if( tokentype != ')' )
		errmsg(" missing ) in parameter declaration\n");
}

/* dclspec : declaration specification */
void dclspec( void )
{
	char temp[MAXTOKEN];

	temp[0] = '\0';
	gettoken();

	do
	{
		if( tokentype != NAME )
		{
			prevtoken = YES;
			dcl();
		}
		else if( typespec() == YES )
		{
			strcat( temp, " " );
			strcat( temp, token );
			gettoken();
		}
		else if( typequal() == YES )
		{
			strcat( temp, " ");
			strcat( temp, token );
			gettoken();
		}
		else
			errmsg("unknown type in parameter list\n");
	}
	while( tokentype != ',' && tokentype != ')' );

	strcat( out, temp );
	if( tokentype == ',' )
		strcat( out, "," );
}

/* typespec : return YES if token is a type-specifier */
int typespec( void )
{
	static char *types[] = {
			"char",
			"int",
			"void"
	};

	char *pt = token;

	if( bsearch( &pt, types, sizeof(types)/sizeof(char *), sizeof(char *), compare) == NULL )
		return NO;
	else
		return YES;
}

/* typequal : return YES if token is a type-qualifier */
int typequal( void )
{
	static char *typeq[] = {
			"const",
			"volatile"
	};

	char *pt = token;

	if( bsearch( &pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *), compare ) == NULL )
		return NO;
	else
		return YES;
}

/* compare : compare two strings for bsearch */
int compare( char **s, char **t )
{
	return strcmp( *s, *t );
}
