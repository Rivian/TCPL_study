#include <stdio.h>

unsigned getbits( unsigned, int, int );

main()
{
	int i, p, n;

	printf("Enter a number : ");
	scanf("%d", &i);

	printf("Enter position : ");
	scanf("%d", &p);

	printf("Enter number of bits to get : ");
	scanf("%d", &n);

	printf("Bits you got is : %d\n", getbits( i, p, n ));
}

unsigned getbits( unsigned x, int p, int n )
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
