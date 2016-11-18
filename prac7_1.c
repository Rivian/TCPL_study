#include <stdio.h>
#include <ctype.h>

int main( int argc, char *argv[] )
{
	int c;

	if( strcmp(argv[0],"lower") == 0 )
	{
		printf("%s : lower case\n", argv[0]);
		while( (c = getchar()) != EOF )
			putchar( tolower(c) );
	}
	else
	{
		printf("%s : upper case\n", argv[0]);
		while( (c = getchar()) != EOF )
			putchar( toupper(c) );	
	}
	return 0;
}
