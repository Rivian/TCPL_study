#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "rpolish.h"

#define MAXTOKEN 100

char *dtype[] = { "char", "int", "float", "double", "long" };

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl( void );
void dirdcl( void );
void errmsg( char * );

int gettoken( void );
int tokentype;			/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out[1000];			/* output string */
int prevtoken = NO;		/* there is no previous token */

int isexist( char **, char * );

int gettoken( void )
{
        int c, getch( void );
        void ungetch( int );
        char *p = token;

	if( prevtoken == YES )
	{
		prevtoken = NO;
		return tokentype;
	}

        while( (c = getch()) == ' ' || c == '\t' )
                ;

        if( c == '(' )
        {
                if( (c = getch()) == ')' )
                {
                        strcpy( token, "()" );
                        return tokentype = PARENS;
                }
                else
                {
                        ungetch( c );
                        return tokentype = '(';
                }
        }
        else if( c == '[' )
        {
                for( *p++ = c; (*p++ = getch()) != ']'; )
                        ;
                *p = '\0';
                return tokentype = BRACKETS;
        }
        else if( isalpha(c) )
        {
                for( *p++ = c; isalnum(c = getch()); )
                        *p++ = c;
                *p = '\0';
                ungetch( c );
                return tokentype = NAME;
        }
        else
	{
                return tokentype = c;
	}
}

int isexist( char *dtype[], char *token )
{
	int i = 0;
	int size = 5;

	for( i=0; i<size; i++ )
		if( !strcmp( dtype[i], token ) )
			return 1;

	return 0;
}

/* dcl : parse a declarator */
void dcl( void )
{
        int ns;

        for( ns = 0; gettoken() == '*'; ) /* count *'s */
                ns++;

        dirdcl();
        while( ns-- > 0 )
                strcat( out, " pointer to" );
}

/* dirdcl : parse a direct declarator */
void dirdcl( void )
{
        int type;

        if( tokentype == '(' )  /* dcl */
        {
                dcl();
                if( tokentype != ')' )
                        errmsg("error : missing )\n");
        }
        else if( tokentype == NAME )    /* variable name */
                strcpy( name, token );
        else
                errmsg("error : expected name or (dcl)\n");

        while( (type=gettoken()) == PARENS || type == BRACKETS )
                if( type == PARENS )
                        strcat( out, " function returning " );
                else
                {
                        strcat( out, " array");
                        strcat( out, token );
                        strcat( out, " of");
                }
}

void errmsg( char *msg )
{
        printf("%s", msg );
        prevtoken = YES;
}
