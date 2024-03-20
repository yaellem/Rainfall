#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>

char *p()
{
	void *p = NULL;
	char j[0x48];

	
	fflush(stdout);
	gets(j);
	if (((unsigned int)*(&p + 2) & 0xb0000000) == 0xb0000000)
	{
		printf("%p\n", *(&p + 2));
		exit(1);;
	}
	
	puts(j);
	return strdup(j);
}

int main()
{
	p();
	return 0;	
}
