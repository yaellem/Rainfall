#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void n()
{
	char s[0x18];

	system("/bin/sh");
	return ;
}

void	m()
{
	char s[0x18];

	puts("Nope");
	return 0;
}

__attribute__((force_align_arg_pointer)) int main(int ac, char **av)
{
	char *s1 = malloc(0x40);
	char *s2 = malloc(0x4);

	
	s2 = (char *)m;
	strcpy(s1, av[1]);
	
	uint32_t *func_to_call = (uint32_t *)s2;
	
	((void(*)(void))*func_to_call)();
	return 0;
}
