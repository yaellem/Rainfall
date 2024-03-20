#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char *s = av[1];
	char *cmd[3] = {"/bin/sh", NULL};
	int arg = atoi(s);

	if (arg != 423)
	{
		fwrite("No !\n", 1, 0x5, stderr);	
		return 0;
	}
	char *s1 = strdup("/bin/sh");
	gid_t egid = getegid();
	uid_t euid = geteuid();
//	setresgid(egid, egid, egid);
//	setresuid(euid, euid, euid);
	execve("/bin/sh", cmd, NULL);
	return 0;
}
