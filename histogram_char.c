#include <stdio.h>

main()
{
	int i, j, c;
	int nchars[26];

	for ( i = 0; i < 26; ++i )
		nchars[i] = 0;

	while ( (c = getchar()) != EOF )
	{
		if ( c >= 'a' && c <= 'z' )
			++nchars[ c-'a' ];
		else if ( c >= 'A' && c <= 'Z' )
			++nchars[ c-'A' ];
	}

	for ( i = 0; i < 26; ++i )
	{
		printf("%c : ", 'a'+i);
		for ( j = 0; j < nchars[i]; ++j )
			printf("#");
		printf("\n");
	}
}
