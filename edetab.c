#include<stdio.h>

#define MAXLINE 80
#define TABINC 8
#define YES 1
#define NO 0

main( int argc, char *argv[] )
{
	int i, pos=1, n=0, s=0;;
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
		if( argc != 3 )
		{	
			printf("Usage : edetab -m +n\n");
			return;
		}

		*++argv;
		
		if( *argv[0]++ != '-' || (s=atoi(*argv) ) > MAXLINE || s < 0 )
		{
			*--(*argv);
			printf("Invalid parameter 1 : %s\nUsage : edetab -m +n\n", *argv );
			return;
		}

		*++argv;

		if( *argv[0]++ != '+' || (n=atoi(*argv) ) > MAXLINE || n < 0 )
		{
			*--(*argv);
			printf("Invalid parameter 2 : %s\nUsage : edetab -m +n\n", *argv);
			return;
		}

		for( i=s; i<MAXLINE; i++ )
			if( (i % n ) == 0 )
				tablist[i] = YES;
			
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
