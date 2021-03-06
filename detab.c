#include<stdio.h>

#define MAXLINE 80
#define TABINC 8
#define YES 1
#define NO 0

main( int argc, char *argv[] )
{
	int i, pos=1, n=0;
	char c;
	char tablist[MAXLINE+1];

	for( i=0; i<MAXLINE; i++ )
		tablist[i] = NO;

	if( argc < 2 )
	{
		for( i=0; i < MAXLINE; i++ )
		{
			if( i % TABINC == 0 )
				tablist[i] = YES;
		}
	} 
	else
	{
		while( --argc > 0 )
		{
			if( !(n=atoi(*++argv)) || n > MAXLINE || n < 0) 
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
		if( c == '\t' )
		{
			do
				putchar(' ');
			while( tablist[pos++] == NO && pos < MAXLINE );
		}
		else if( c == '\n' )
		{
			putchar(c);
			pos = 1;
		}
		else	
		{
			putchar(c);
			pos++;
		}
	}
}
