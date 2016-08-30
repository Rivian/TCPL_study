#include <stdio.h>

int invert( int, int, int );

main()
{
	int x, p, n;
	x=p=n=0;


	printf("Enter a number : ");
	scanf("%d", &x );

	printf("Enter position of bits to invert : ");
	scanf("%d", &p );

	printf("Enter number of bits to invert : ");
	scanf("%d", &n );

	printf("Inverted result : %d\n", invert(x, p, n) );
	printf("%d\n", (~(~0 << n) << (p+1-n)) );
}

int invert( int x, int p, int n )
{
	return x ^ (~(~0 << n) << (p+1-n));
}
