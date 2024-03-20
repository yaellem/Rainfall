#include <stdio.h>
#include <stdlib.h>

int m = 0;

int	p(char *arg1)
{
	char s1[0x18]; // sizeof stackframe post arg_space, ebp
	
	return printf(arg1);
}

int	n()
{
	char s1[0x208];
	char s2[0x10];

	fgets(s1, 0x200, stdin);
	p(s1);
	if (m != 0x1025544)
		return m
	return system("/bin/cat /home/user/level5/.pass")
}

__attribute__((force_align_arg_pointer)) int main()
{
	return n();
}
