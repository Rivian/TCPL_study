#include <stdio.h>

main()
{
	printf("%u\n", ~(~0U >> 1));
}
