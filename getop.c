#include <stdio.h>
#include <ctype.h>
#include "rpolish.h"

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0;   /* next free position in buf */

/* getop : get next operator or numeric operand */
int getop( char s[] )
{
        int i,c,next, ret;

        ret = NUMBER;
        while( (s[0]=c=getch()) == ' ' || c=='\t' );
                ;

        s[1] = '\0';

        if( !isdigit(c) && c!='.' && c!='-' )
                return c;       /* not a number */

        i = 0;

        if( c=='-' )
        {
                next = getch();
                if( isdigit(next) )
                {
                        ret = MNUMBER;
                        s[0] = c = next;
                }
                else
                        return c;
        }

        if( isdigit(c) ) /* collect integer part */
                while( isdigit(s[++i] = c = getch() ) )
                        ;

        if( c == '.' )  /* collect fraction part */
                while( isdigit(s[++i] = c = getch() ))
                        ;
        s[i] = '\0';
        if( c != EOF )
	{
		if( bufp >= BUFSIZE )
		{
			printf("too many characters.\n");
			return -1;
		}
		else
			buf[bufp++] = c;
	}
		
        return ret;
}

int getch( void )
{
        return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch( int c )
{
	if( bufp >= BUFSIZE )
		printf("ungetch : too many characters\n");
	else
		buf[bufp++] = c;
}
void ungets( char s[] )
{
	int i = 0;

	while( s[i] )
	{
		buf[bufp+i] = s[i];
		i++;
	}
	bufp += i;
}
