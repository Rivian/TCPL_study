#include <stdio.h>

int lower( int );

main()
{
	int in=0;

	while ( (in = getc( stdin )) != EOF )
		putc( lower(in), stdout );
}

int lower( int c )
{
	return (c>='A' && c<='Z') ? c+'a'-'A' : c;
} 
