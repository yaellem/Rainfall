#include <stdio.h>
#include <stdlib.h>

int	language = 0;

void	greetuser(char *arg)
{
// eip ret at 0xbffff40c
//	ebp = 0xbffff408
	char s[0x58];//0xbffff3b0 -> 0xbffff408

	if (language == 0) 
	{
		edx = "Hello ";
		(char *)(s + 0x10) = "Hello "; //0x8048710 -> //0x8048716
	}
	else if (language == 1)
	{
		
		(char *)(s + 0x10) = "Hyvää päivää "; //0x8048717 -> 0x8048729
	}
	else if (language == 2)
	{ 
		(char *)(s + 0x10) = "Goedemiddag! "; //0x804872a -> 0x804837
	}
//	0xbffff3c0 + 0xc + 0x48 = 0xBFFFF414
	strcat((char*)(s + 0x10), arg)
	puts((char*)(s + 0x10));
	return;
}

__attribute__((force_align_arg_pointer))int main(int ac, char **av)
{
//	ebp = 0xbffff4c8
	int a; // 0xbffff4c4
	int b; // 0xbffff4c0
	int c; // 0xbffff4bc

	char align[0xc]; // 0xbffff4b0 -> 0xbffff4bc
	char s[0xa0]; // 0xbffff410 -> 0xbffff460
	
	if (ac != 0x3)
		exit(1);
	for (int i = 0x4c; i != 0 ; i--)
		*((char*)(s + 0x50 + i)) = 0;

// 0xbffff460 -> 0xbffff488 = av[1] max 0x28
	strncpy((void*)(s + 0x50), av[1], 0x28)
// 0xbffff488 -> 0xbffff4a8 = av[2] max 0x20
	strncpy((void*)(s + 0x50 + 0x28), av[2], 0x20);
	(char*)(s + 0x9c) = getenv("LANG");
	if ((char*)(s + 0x9c) != NULL)
	{
		if (memcmp((char *)(s + 0x9c), "fi", 0x2) != 0)
		{
			if (memcmp((char*)(s + 0x9c), "nl", 2) == 0)
				language = 2;
		}
		else // s + 0x9c == "fi"
			language = 1;
		
	}
// 0xbffff410 -> 0xbffff45c = 0xbffff460 -> 0xbffff4ac
	for (int i = 0x4c; i != 0; i--)
	{
		s = *(char*)(s + 0x50 + i); 
		s++;
		
	}
	greetuser(s); //&s = 0xbffff410
	return 0;// pop 0xbffff4cc 
}
