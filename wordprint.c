#include <stdio.h>

#define	IN	1
#define	OUT	0

/* print a word per line */
main()
{
	int c, state;
	state = OUT;
	c = 0;
	while ((c = getchar()) != EOF )
	{
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			putchar('\n');
			putchar(c);
		}
		else
			putchar(c);
	}
}
