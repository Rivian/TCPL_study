#include <stdio.h>

#define	MAXLINES	5000
#define	NUMERIC		1
#define	REVERSE		2
#define IGNORE		4
#define	DIR		8
#define FIELD		16

char *lineptr[MAXLINES];

static char option = 0;

int readlines( char *lineptr[], int nlines );	/*pointers to text lines */
void writelines( char *lineptr[], int nlines, int reverse );

void qsort( void *lineptr[], int left, int right, int (*comp)(void *, void *) );
int numcmp( char *, char * );
int numcmpf( char *, char * );
int strcmp( char *, char * );
int strcmpf( char *, char * ); /* compare two strings while ignore alphabet case */
void strcpy( char *, char *);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	int i, rc;
	char c;

	while( --argc > 0 && (*++argv)[0] == '-' )
	{
		while( c = *++argv[0] )
		{
			switch( c )
			{
				case 'n' :
					option |= NUMERIC;
					break;
				case 'r' :
					option |= REVERSE;
					break;
				case 'f' :
					option |= IGNORE;
					break;
				case 'd' :
					option |= DIR;
					break;
				case 'i' :
					option |= FIELD;
					break;
				default :
					printf("Invalid option : %c\n", c );
					argc = 1;
					rc = -1;
					break;
			}
		}
	}

	if (( nlines = readlines( lineptr, MAXLINES )) >= 0 )
	{
		if( option & NUMERIC )
		{
			qsort( (void **)lineptr, 0, nlines-1, 
				(int (*)(void*,void*)) numcmp );
		}
		else
		{
			qsort( (void **)lineptr, 0, nlines-1, 
				(int (*)(void*,void*)) strcmpf );
		}
		writelines( lineptr, nlines, option & REVERSE );
		rc = 0;
	}
	else
	{
		printf("error : input too big to sort\n");
		rc = -1;
	}
	return rc;
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
		if (( nlines >= maxlines) || (p = alloc(len)) == NULL )
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
void writelines( char *lineptr[], int nlines, int reverse )
{
	int i;

	if( reverse )
		for( i=nlines-1; i>=0; i-- )
			printf("%s\n", lineptr[i] );
	else
		for( i=0; i<nlines; i++ )
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

/* qsort : sort v[left]...v[right] into increasing order */
void qsort( void *v[], int left, int right,
		int (*comp)(void *, void *) )
{
	int i, last;
	void swap( void *v[], int i, int j );

	if( left >= right )	/* do nothing if array contains */
		return;		/* fewer than two elements */

	swap( v, left, (left+right)/2 );
	last = left;
	for( i=left+1; i<=right; i++ )
		if( (*comp)( v[i], v[left] ) < 0 )
			swap( v, ++last, i );
	swap( v, left, last );
	qsort( v, left, last-1, comp );
	qsort( v, last+1, right, comp );
}

void swap( void *v[], int i, int j )
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int strcmpf( char *s1, char *s2 )
{
	char a, b;

	do
	{
		if( option & DIR ) 
		{
			while( !isalnum(*s1) && *s1 != ' ' && *s1 != '\0' )
				s1++;
			while( !isalnum(*s2) && *s2 != ' ' && *s2 != '\0' )
				s2++;
		}

		a = (option & IGNORE) ? tolower(*s1) : *s1;
		s1++;
		b = (option & IGNORE) ? tolower(*s2) : *s2;
		s2++;
		if( a == b && a == '\0' )
			return 0;
	} while( a == b );

	return a - b;
}
