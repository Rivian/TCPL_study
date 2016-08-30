#include <stdio.h>
#include <string.h>

#define	MAXLEN	255

int itob( int, char[], int );
void reverse( char[] );

main()
{
	int n, b;
	char s[MAXLEN];

	printf("Enter a number to convert : ");
	scanf("%d", &n );

	printf("Enter base of the number : ");
	scanf("%d", &b );

	if( b!=2 && b!=8 && b!=16 )
	{
		printf("ERROR : base only can be 2, 8, 16.\n");
		return -1;
	}

	if( !itob( n, s, b ) )
	{
		printf("Error occured in itob().\n");
		return -1;
	}
	
	printf("Converted string is : %s\n", s );

	return 0;
}

int itob( int n, char s[], int b )
{
	int i, j, sign;

	if ( (sign=n)<0 )
		n = -n;

	i=0;

	do
	{
		j = n % b;
		s[i++] = j > 10 ? (j-10)+'A' : j + '0';
	}
	while( (n/=b) > 0 );

	if( sign < 0 )
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse( char s[] )
{
        int c, i, j;

        for( i=0, j=strlen(s)-1; i<j; i++, j-- )
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}



