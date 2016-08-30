#include <stdio.h>

#define	MAXLEN	255

int escape( char[], char[] );

main()
{
	int i;
	char c, in[MAXLEN], out[MAXLEN];

	for( i=0; i<MAXLEN; i++ )
		in[i] = out[i] = ' ';

	printf("Enter a string : ");
	for( i=0; i<MAXLEN && (c=getchar()) != EOF; i++ )
		in[i] = c;

	i++;
	in[i] = '\0';

	if( !escape(in, out) )
		printf("Entered string is : %s\nTransformed string is : %s\n", in, out);
	else
		return -1;

	return 0;
}

int escape( char in[], char out[] )
{
	int i, j;
	i=j=0;

	for( i=0; i<MAXLEN; i++ )
	{
		switch( in[i] )
		{
			case '\t' :
				out[j] = '\\';
				out[j+1] = 't';
				j+=2;
				break;
			case '\n' :
				out[j] = '\\';
				out[j+1] = 'n';
				j+=2;
				break;
			case ' ' :
				out[j] = '\\';
				out[j+1] = ' ';
				j+=2;
				break;
			case '\0' :
				out[j] = '\0';
				return 0;
				break;
			default :
				out[j] = in[i];
				j++;
				break;
		}
	}
	return 0;
}
