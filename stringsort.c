#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char p[MAXLEN];

int readlines( char *lineptr[], int nlines );
void writelines( char *lineptr[], int nlines );

void qsort( char *lineptr[], int left, int right );

main()
{
	int nlines;
	if (( nlines = readlines( lineptr, MAXLINES )) >= 0 )
	{
		qsort( lineptr, 0, nlines-1 );
		writelines( lineptr, nlines );
		return 0;
	}
	else
	{
		printf("error : input too big to sort\n");
		return 1;
	}
}

int getline( char *, int );
char *alloc( int );

int readlines( char *lineptr[], int maxlines )
{
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	while( (len = getline(line, MAXLEN)) > 0 )
		if( nlines >= maxlines )
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete newline */
			strcpy( p, line );
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines( char *lineptr[], int nlines )
{
	while( nlines-- > 0 )
		printf("%s\n", *lineptr++ );
}

void qsort( char *v[], int left, int right )
{
	int i, last;
	void swap( char *v[], int i, int j );

	if( left >= right )
		return ;

	swap( v, left, (left+right)/2 );
	last = left;
	for( i=left+1; i <= right; i++ )
		if( v[i] < v[left] )
			swap( v, ++last, i );
	swap( v, left, last );
	qsort( v, left, last -1 );
	qsort( v, last+1, right );
}

void swap( char *v[], int i, int j )
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getline( char *s, int lim )
{
	int c, i;

	for( i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i )
		s++ = c;

	if( c=='\n' )
	{
		s++ = c;
		++i;
	}
	s++ = '\0';
	return i;
}

#define	ALLOCSIZE	10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc( int n )	/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n )
	{
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void afree( char *p )
{
	if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
		allocp = p;
}	
