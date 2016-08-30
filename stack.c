#include <stdio.h>
#include "rpolish.h"

int sp = 0;
double val[MAXVAL];

void push( double f )
{
        if( sp < MAXVAL )
                val[sp++] = f;
        else
                printf("push():error: stack full\n");
}

double pop( void )
{
        if( sp > 0 )
        {
                return val[--sp];
        }
        else
        {
                printf("pop():error: stack empty\n");
                return 0.0;
        }
}

void viewstack(void)
{
        int i;
        printf("\nstack:\n");
        for(i = sp - 1; i >= 0; i--)
                printf("%lf\n", val[i]);
}

void topstack(void)
{
        printf("top of stack is : %lf\n", val[sp] );
}

void clearstack(void)
{
        while( sp > 0 )
                pop();
}

