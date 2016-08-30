#include <stdio.h>
#include <string.h>

int strend( char *, char * );

main()
{
	char *s, *t;

	s = "abcdefg";
	t = "efg";

	printf("s=%s, t=%s\n", s, t );

	if( strend( s, t ) )
		printf("t : %s is end of s : %s\n", t, s );
	else
		printf("t : %s is not end of s : %s\n", t, s );

	s = "abcdefg";
	t = "efghij";

	printf("s=%s, t=%s\n", s, t );

	if( strend( s, t ) )
		printf("t : %s is end of s : %s\n", t, s );
	else
		printf("t : %s is not end of s : %s\n", t, s );
}

int strend( char *s, char *t )
{
	char *i, *j;
	int k;

	i = s+strlen(s);
	j = t+strlen(t);

	for( k=0; k<strlen(t); k++ )
	{
		if( *i-- != *j-- )
			return 0;
	}
	return 1;
}
