#include <stdio.h>

#define MAX_DIGIT	100

long int atoi( char[] );

main()
{
	char in[MAX_DIGIT];

	printf("Enter a number : ");
	scanf("%s", in );

	printf("Convert result : %ld\n", atoi(in) );

	return 0;
}

long int atoi( char s[] )
{
	long int i, n;

	n = 0;
	for ( i=0; s[i]>='0' && s[i]<='9'; ++i )
		n = 10*n+(s[i]-'0');
	return n;
}
