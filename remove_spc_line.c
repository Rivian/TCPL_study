#include <stdio.h>

#define	MAXLINE	1000  /* maximum input line size */

int getlin( char line[], int maxline );
void copy( char to[], char from[] );

/* remove tabs and spaces after lines */
main()
{
	int len;
	int max;

	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ( (len = getlin(line, MAXLINE)) > 0 )
		if ( len >1 )
			printf("%s", line);
	return 0;
}

/* getlin : read a line into s, return length */
int getlin( char s[], int lim )
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	while( s[i-1]==' ' || s[i-1]=='\t' )
		--i;

	if ( c=='\n' )
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
