#include <stdio.h>

#define	IN	1
#define	OUT	0

main()
{
	int length, i, c, inout;

	length = inout = 0;

	while ( (c = getchar()) != EOF )
	{
		if ( c == ' ' || c == '\n' || c == '\t' )
			inout = OUT;
		else if ( inout == OUT )
			inout = IN;

		if ( inout == IN )
			++length;
	}

	for( i = 0; i < length; i++ )
		printf("#");
	printf("\n");
}
