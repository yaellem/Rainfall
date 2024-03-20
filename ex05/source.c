#include <stdlib.h>
#include <stdio.h>

void		o()
{
	char s1[0x18];

	system("/bin/sh");
	exit(1);
}

void		n()
{
	char s1[0x208];
	char s2[0x10];

	fgets(s1, 0x200, stdin);
	printf(s1);
	exit(1);
}

__attribute__((force_align_arg_pointer)) int main()
{
	n();
	return 0;
}
