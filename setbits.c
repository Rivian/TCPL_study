#include <stdio.h>

unsigned setbits( unsigned, unsigned, int, int );

main()
{
	int i, y, p, n;

	printf("Enter a number : ");
	scanf("%d", &i);

	printf("Enter another number : ");
	scanf("%d", &y);

	printf("Enter position of bits to change : ");
	scanf("%d", &p);

	printf("Enter number of bits to change : ");
	scanf("%d", &n);

	printf("Number you got is : %d\n", setbits( i, y, p, n ));
}

unsigned setbits( unsigned x, unsigned y, int p, int n )
{
	return (x & ~(~(~0 << n) << (p+1-n))) | (y & (~(~0 << n) << (p+1-n))) ;
}
