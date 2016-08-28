#include <stdio.h>
#include <string.h>

#define MAXLINES 1000

char *lineptr[MAXLINES];

int readlines( char *lineptr[], int nlines );	/*pointers to text lines */
void writelines( char *lineptr[], int nlines, int last );

/* write last n input lines */
main(int argc, char *argv[] )
{
	int nlines; /* number of input lines read */
	int last; /* number of last n lines to write */

	if( argc < 2 )
	{
		printf("Usage : tail -n\n");
		return;
	}
	
	if( (*++argv)[0] != '-' || (last = atoi(argv[0]+1)) > MAXLINES )
	{
		printf("Invalid parameter : %s\n", argv[1] );
		return;
	}

	if (( nlines = readlines( lineptr, MAXLINES )) >= 0 )
	{
		writelines( lineptr, nlines, last );
		return 0;
	}
	else
	{
		printf("error : no input to write\n");
		return 1;
	}
}

#define MAXLEN 1000	/* max length of any input line */

int getline( char *, int );
char *alloc(int);

/* readlines : read input lines */
int readlines( char *lineptr[], int maxlines )
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while( (len = getline( line, MAXLEN )) > 0 ) 
	{
		if ((p = alloc(len)) == NULL )
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete newline */
			strcpy( p, line );
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines : write output lines */
void writelines( char *lineptr[], int nlines, int last )
{
	int i;
	
	if ( last > nlines )
		last = nlines;

	for( i=nlines-last; i<nlines; i++ )
		printf("%s\n", lineptr[i] );
}

/* getline : read a line into s, return length */
int getline( char s[], int lim )
{
	int c, i;
	
	for( i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i )
		s[i] = c;

	if( c == '\n' )
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}
