#include <math.h>

/* strcmp : compare s1 and s2 */
int strcmp( char *s1, char *s2 )
{
	for( ; *s1 == *s2; s1++, s2++ )
		if( *s1 == '\0' )
			return 0;
	return *s1 - *s2;
}

/* numcmp : compare s1 and s2 numerically */
int numcmp( char *s1, char *s2 )
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if( v1 < v2 )
		return -1;
	else if ( v1 > v2 )
		return 1;
	else
		return 0;
}

/* strcpy : copy s1 to s2; pointer version 3 */
void strcpy( char *s1, char *s2 )
{
	while( *s1++ = *s2++ )
		;
}

int strlen( char *s )
{
	int i=0;
	while( s[i] != '\0' )
		i++;

	return i;
}
