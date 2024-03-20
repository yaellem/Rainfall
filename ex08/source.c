#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *auth;
char *service;

int main()
{
	char *input;
	int a_index;
	
	while (1)
	 {
		printf("%p, %p \n",auth,service);
		input = fgets(input, 0x80, stdin);
		
		if (input == NULL)
			return 0;
		
		if (input == "auth")
		{
			auth = malloc(0x4);
			*(auth + 0) = 0;
			len_auth = strlen(input + 5) - 1;
			if (len_auth == 30)
				strcpy(auth, input + 5)			
		}			
		if (input == "reset")
			free(auth);
		if (input == "servic")
			service = strdup(input + 7)
		if (input == "login")
			if (*auth + 0x20 == 0)
				print("password:\n")
			else	
				system("/bin/sh");
	}
	return 0;	
}

