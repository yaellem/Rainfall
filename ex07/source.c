#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *c = NULL; //0x8049960

void	m() // address 0x080484f4
{
	char s[0x18];
	
	printf("%s - %d\n", c, time(0));
}

__attribute__((force_align_arg_pointer)) int main(int ac, char **av)
{
	char *s1 = malloc(0x8);
	s1[0] = 0x1;	
	(char*)(s1 + 4) = malloc(0x8);
	
	char *s2 = malloc(0x8);
	s2[0] = 0x2;
	(char *)(s2 + 4) = malloc(0x8);

	strcpy((char *)(s1 + 4), av[1]);
	strcpy((char*)(s2 + 4), av[2]);
	
	fgets(c, 0x44, fopen("/home/user/level8/.pass", "r"));
	puts("~~");
	
	return 0;
}
