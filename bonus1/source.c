#include <unistd.h>
#include <stdlib.h>
#include <string.h>

__attribute__((force_align_arg_pointer)) int main(int ac, char **av)
{

	int i;
	char s[0x3c];
	
	i = atoi(av[1]);	
	if (i > 0x9)
		return 1;
					
	memcpy((void*)(s + 0x14), av[2], i * 4); 
	if (i == 0x574f4c46)
	{	execl("/bin/sh", "sh");	
		return 0;
	}
	return 1;
}

