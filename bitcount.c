#include <stdio.h>

int bitcount( unsigned );

main()
{
	unsigned x;

	printf("Enter a number to count bits of 1 : ");
	scanf("%u", &x);

	printf("Bits of 1 is : %d\n", bitcount(x) );
}

/* example
int bitcount( unsigned x )
{
	int b;

	for( b=0; x!=0; x >>= 1 )
		if( x & 01 )
			b++;
	return b;
}
*/

int bitcount( unsigned x )
{
	int b;
	
	for( b=0; x!=0; x&=x-1 )
		b++;
	return b;
}
