#include <stdio.h>

/* echo command-line arguments; 1st version */
main( int argc, char *argv[] )
{
	int i;

	while( --argc > 0 )
		printf("%s%s", *++argv, (argc > 1)?" " : "" );
	printf("\n");
	return 0;
}
