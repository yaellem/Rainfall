#include <stdio.h>
#include <stdlib.h>

int v()
{
	char s1[0x208];
	char s2[0x10];

	fgets(s1, 0x200, stdin);
	printf(s1); // When printf is called, the address of the input chain is on the stackframe of printf (from its function arguments position), 0x10 bytes further that the begginng of its arguments stack space. Meaning that all further argument that will be popped, depending of the content of its first arg, may be popped from the input chain, because the pop() are contiguous from the stack, and will happen as long as printf needs it, (cqfd) depending of its input string. (the number of formats asked)
	if (*(int*)(0x804988c) == 0x40)
	{
		fwrite("Wait what?!\n", 0x1, 0xc, stdout);
		return system("/bin/sh");
	}
	return 0;
}

__attribute__((force_align_arg_pointer)) int main()
{
	return v();
}
