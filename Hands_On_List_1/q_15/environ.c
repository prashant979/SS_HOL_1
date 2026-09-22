#include <stdio.h>
#include <stdlib.h>
extern char **environ;

int main() {
	char **env = environ;
	while(*env != NULL) {
	//	printf("%s\n", *env);
		env++;
	}
	printf("%s\n", getenv("PATH"));
	return 0;
}
