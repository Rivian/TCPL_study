#include <stdio.h>

#define	MAXLINE	1000  /* maximum input line size */

int getlin( char line[], int maxline );
void reverse( char to[], char from[], int length );

/* reverse all characters in line */
main()
{
	int len;
	int max;

	char line[MAXLINE];
	char reversed[MAXLINE];

	max = 0;

	while ( (len = getlin(line, MAXLINE)) > 0 )
	{
		reverse(reversed, line, len);
		printf("%s", reversed);
	}
	return 0;
}

/* getlin : read a line into s, return length */
int getlin( char s[], int lim )
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if ( c=='\n' )
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* reverse : copy 'from' into 'to' by reversed order; assume 'to' is big enough */
void reverse( char to[], char from[], int length )
{
	int i, j;

	i = 0;

	for ( j = length; from[j]=='\n' || from[j]=='\0'; j-- )
		;

	while ( i <= j )
	{
		to[i] = from[j-i]; 
		++i;
	}

	while ( (to[i] = from[i]) != '\0' )
		++i;	

}
