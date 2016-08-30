#include <stdio.h>

#define MAX_LENGTH	256

void squeeze( char[], char[] );

main()
{
	char src[MAX_LENGTH], target[MAX_LENGTH];
	int i;
	
	for ( i=0; i<MAX_LENGTH; i++ )
	{
		src[i] = 0;
		target[i] = 0;
	}

	printf("Enter a source string : ");
	scanf("%s", src);

	printf("Enter a target string : ");
	scanf("%s", target);

	squeeze( src, target );

	printf("Squeezed result string is : %s\n", src);
}


void squeeze( char s[], char t[] )
{
	int i, j, k;

	for( i=0; t[i] != '\0'; i++ )
	{
		for( j=k=0; s[j]!='\0'; j++ )
			if( s[j] != t[i] )
				s[k++] = s[j];
		s[k] = '\0';
	}
}
