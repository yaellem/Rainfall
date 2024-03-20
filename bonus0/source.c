#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*p(void *arg1, void *arg2)
{
// stackframe ebp = 0xbffff688
// &arg1 = 0xbffff690 
//	arg1 = 0xbffff6b8	arg1 = 0xbffff6cc
// &arg2 = 0xbffff694
//	arg2 = 0x080486a0
	char s[0x1018]; //0xbffff688 -> 0xbfffe680: 0xbfffe680

	puts(arg2); // " - "	
	read(0, s, 0x1000);

	char *s_eol =  strchr(s, '\n');
	*s_eol = '\0';

	return strncpy(arg1, s, 0x14); //0xbffff6b8 = s(0x14)
								   //0xbffff6cc = s(0x14)
}

char	*pp(char *s1)
{
// stackframe ebp = 0xbffff6e8
// &s1 = 0xbffff6f0
//	s1 = 0xbffff706
	char align[0x8]; //0xbffff6e8 -> 0xbffff6e4 -> 0xbffff6e0

	char ptr[0x50]; //0xbffff6e0 -> 0xbffff690 : 0xbffff690

//	void *ptr + 0x28; // 0xbffff6b8; // ebp - 0x30 : 0xbffff6b8
//	void *0x080486a0; //*a2 = ' - '
	p((void*)(ptr + 0x28), " - ");
	
//	void *ptr + 0x3c; // 0xbffff6cc
//	void *0x080486a0; //*a2 = ' - '
	p((void*)(ptr + 0x3c), " - ");

	strcpy(s1, (void*)(ptr + 0x28)); //0xbffff706 = a1
	
	int i = 0;
	while (s1[i])
		i++;
	s1[i]  = ' ';
	return strcat(s1, (void *)(ptr + 0x3c)); //eip in stack is at 0xbffff6ec
}

__attribute__((force_align_arg_pointer)) int	main()
{
// ebp = 0xbffff738
	char s1[0x10];
	char s2[0x2a]; //s2 = 0xbffff706

	pp(s2); //&s2 = 0xbffff6f0: 
	puts(s2);
	return 0; //pop 0xbffff73c = jump at 0xb7e454d3
}
