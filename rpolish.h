#define BUFSIZE 100
#define NUMBER 'N'
#define MNUMBER 'M'
#define MAXOP   100
#define MAXVAL  100
#define VARIABLE_U 'V'
#define VARIABLE_L 'v'

int getop( char [] );
void push( double );
double pop( void );

int getch(void);

void viewstack( void );

void topstack( void );
void clearstack( void );
