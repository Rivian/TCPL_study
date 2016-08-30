#include <stdio.h>

#define MAX	1000000

int binsearch( int, int[], int );


main()
{
	int arr[MAX], i, x, result;

	for ( i=0; i < MAX; i++)
		arr[i]=i;

	printf("Enter a number : ");
	scanf("%d", &x);

	if( (result = binsearch(x, arr, MAX)) != -1)
		printf("Location of %d in arr[] is : %d\n", x, result );
	else
		printf("%d is not exist in arr[].\n", x);
}

// after
int binsearch( int x, int v[], int n )
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while( low < high )
	{
		mid = (low+high)/2;
		if ( x <= v[mid] )
			high = mid;
		else
			low = mid;
	}
	return (v[mid]==x) ? mid : -1;
}

/*
int binsearch( int x, int v[], int n )
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while( low <= high )
	{
		mid = (low+high)/2;
		if ( x < v[mid] )
			high = mid - 1;
		else if ( x > v[mid] )
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
*/
