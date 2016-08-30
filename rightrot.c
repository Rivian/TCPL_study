#include <stdio.h>

unsigned rightrot( int, int );

main()
{
	unsigned x, n;

	printf("Enter a number to rotate : ");
	scanf("%d", &x );

	printf("Enter number of bits to rotate : ");
	scanf("%d", &n );

	printf("Result of rightrot : %u\n", rightrot(x,n) );
}

unsigned int rightrot( int x, int n )
{
	unsigned int y=0, b=x, k=0;

	while ( (b=b/2) >= 1 )
		k++;

	y = x & ~(~0 << n);

	return (x >> n) | (y << (k+1-n));
}
