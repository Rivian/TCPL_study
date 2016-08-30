#include <stdio.h>

#define MAXLINE 80
#define TABINC 8
#define YES 1
#define NO 0

main(int argc, char *argv[])
{
	char c;
	int i, spc=0, pos=0, tabs=0, n;
	char tablist[MAXLINE];

	for( i=0; i<MAXLINE; i++ )
		tablist[i] = NO;

	if( argc < 2 )
	{
		for( i=0; i< MAXLINE; i++)
			if( i % TABINC == 0 )
				tablist[i] = YES;
	}
	else
	{
		while( --argc > 0 )
		{
			if( !(n=atoi(*++argv)) || n > MAXLINE || n < 0 )
			{
				printf("Invalid parameter : %s\n", *argv );
				return;
			}
			else
				tablist[n] = YES;
		}
	}

	while( (c=getchar()) != EOF )
	{
		if( c == ' ' )
		{
			if( tablist[pos] == NO && pos < MAXLINE )
			{
				spc++;
			}
			else
			{
				tabs++;
				spc = 0;
			}
		}
		else
		{
			while( tabs-- > 0 )
				putchar('\t');

			if( c == '\t' )
			{
				spc=0;
				pos++;
			}
			else
				while( spc-- > 0 )
					putchar(' ');

			putchar(c);

			if( c == '\n' )
				pos = 0;
		}
		pos++;
	}
}
