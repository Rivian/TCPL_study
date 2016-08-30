#include <stdio.h>

#define MAX_DIGIT	100

long int htoi( char[] );

main()
{
	char in[MAX_DIGIT];
	long int result=0;

	printf("Enter a HEX number that starts 0x or 0X : ");
	scanf("%s", in );

	if ( (result = htoi(in)) == -1 )
		printf("Error occured : check input value\n");
	else
		printf("Convert result : %ld\n", result );

	return 0;
}

long int htoi( char s[] )
{
	int i;
	long int n=0;

	if ( s[0]=='0' && (s[1]=='x' || s[1]=='X') )
	{
		for ( i=2; s[i]!='\n' && s[i]!='\0'; i++ )
		{
			if ( s[i]>='0' && s[i]<='9' )
				n = n * 16 + (s[i]-'0');
			else if ( s[i]>='a' && s[i]<='f' )
				n = n * 16 + (s[i]-'a'+10);
			else if ( s[i]>='A' && s[i]<='F' )
				n = n * 16 + (s[i]-'A'+10);
			else
				return -1;
		}	
		return n;
	}

	return -1;
}
