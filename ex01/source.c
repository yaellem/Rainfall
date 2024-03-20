#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__attribute__((force_align_arg_pointer)) void run()
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
	return ;
}

int main(void)
{
	char buf[0x30];

	gets(buf);
	return 0;
}
