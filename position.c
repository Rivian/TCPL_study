#include <stdio.h>

#define MAX_LENGTH	256

int any( char[], int );

main()
{
	char src[MAX_LENGTH];
	int c=0;
	int i, result;

	for( i=0; i<MAX_LENGTH; i++)
		src[i] = 0;

	printf("Enter a string : ");
	fgets( src, MAX_LENGTH, stdin );

	printf("Enter a character : ");
	c=getchar();

	result = 0;
	if( (result=any(src,c)) != -1 )
		printf("Position of %c in %s is : %d\n", c, src, any(src,c) );
	else
		printf("There is no %c in %s.\n", c, src );
}

int any( char s[], int c )
{
	int i, len;

	for( len=0; s[len] != '\0'; len++ )
		;

	for( i=0; i<len; i++ )
	{
		if( s[i]==c )
			return ++i;
	}
	return -1;
}
