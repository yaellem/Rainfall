#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

__attribute__((force_align_arg_pointer))int main(int ac, char **av)
{
// ebp = 0xbffff518
	int a; // 0xbffff514
	int b; // 0xbffff510
	
	int fd;// 0xbffff50c -> 0xbffff510
	char s[0xa0 - 0x4]; // 0xbffff470 -> 0xbffff50c

// 0xbffff50c = 
	fd = fopen("/home/user/end/.pass", "r");

	for (int i = 0x21; i != 0; i--)
	{
// 0xbffff488
		s + 0x18 = 0;
		s++;
	}
	if (fd == 0 || ac != 2)
	{
		return -1;		
	}
	
	fread((char *)(s + 0x18), 1, 0x42, fd)
	s + (0x18 + 0x41) = '\0';
			
	int i = atoi(av[1]);
	(char*)(s + 0x18) + i = '\0';
	
	fread((char *)(s + 0x18 + 0x42), 1, 0x41, fd)
	fclose(fd);
	
	if (strcmp((char*)(s + 0x18), av[1]) == 0)
	{
		execl("/bin/sh", "sh", 0);
	}
	else
		puts((s + 0x18 + 0x42));
	return 0; 
}
