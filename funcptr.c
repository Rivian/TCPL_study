#include <stdio.h>

// define function pointer type
typedef int (*calcFuncPtr)( int, int );

// add function
int plus( int first, int second )
{
	return first + second;
}

// minus function
int minus( int first, int second )
{
	return first - second;
}

// multiple function
int multiple( int first, int second )
{
	return first * second;
}

// divide function
int division( int first, int second )
{
	return first / second;
}

int calculator( int first, int second, calcFuncPtr func )
{
	return func( first, second );
}

int main( int argc, char **argv )
{
	calcFuncPtr calc = NULL;

	int a = 0, b = 0;
	char op = 0;
	int result = 0;

	scanf("%d %c %d", &a, &op, &b );

	switch( op )
	{
		case '+' :
			calc = plus;
			break;

		case '-' :
			calc = minus;
			break;

		case '*' :
			calc = multiple;
			break;

		case '/' :
			calc = division;
			break;
	}

	result = calculator( a, b, calc );

	printf("result = %d\n", result );

	return 0;
}
