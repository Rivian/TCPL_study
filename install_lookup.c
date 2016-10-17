struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE	101

static struct nlist *hashtab[HASHSIZE];

/* hash : form hash value for string s */
unsigned hash( char *s )
{
	unsigned hashval;

	for( hashval=0; *s!='\0'; s++ )
		hashval = *s + 31*hashval;

	return hashval % HASHSIZE;
}

/* lookup : look for s in hashtab */
struct nlist *lookup( char *s )
{
	struct nlist *np;

	for( np = hashtab[hash(s)]; np != NULL; np = np->next )
		if( strcmp(s, sp->name) == 0 )
			return np;

	return NULL;
}

char *strdup( char * );

/* install : put (name, defn) in hashtab */
struct nlist *install( char *name, char *defn )
{
	struct nlist *np;
	unsigned hashval;

	if( (np = lookup(name)) == NULL )	/* not found */
	{
		np = (struct nlist *)malloc( sizeof(*np) );
		if( np == NULL || (np->name = strdup(name)) == NULL )
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} 
	else		/* already there */
		free( (void *) np->defn );	/* free previous defn */
		
	if( (np->defn = strdup(defn) ) == NULL )
		return NULL;

	return np;
}

void undef( char *name, char *defn )
{
	struct nlist *np, *prev;
	unsigned hashval;

	prev = NULL;
	hashval = hash(name);

	for( np = hashtab[hashval]; np != NULL; np = np->next )
	{
		if( strcmp( name, np->name ) == 0 )
			break;
		prev = np;		/* remember previous node */
	}
	
	if( np != NULL )
	{
		if( prev = NULL )
			hashtab[hashval] = np->next;
		else
			prev->next = np->next;

		free( (void *)np->name );
		free( (void *)np->defn );
		free( (void *)np );
	}
}
	return 1;
}
