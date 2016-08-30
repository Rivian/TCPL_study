#include <stdio.h>

int convert( int i );

main()
{
	int fahr, celsius;

	for( fahr = 0; fahr <= 300; fahr+=20 )
		printf("%d %d\n", fahr, convert( fahr ) );
	return 0;
}

int convert( int fahr )
{
	int celsius;

	celsius = 0;
	celsius = 5 * (fahr-32) / 9;

	return celsius;
}
