#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		return 1;
	}
	if (pid == 0) {
		printf("Child: %d\n", getpid());
		exit(0);
	} else {
		printf("Parent: %d\n", getpid());
		printf("P_Child: %d\n", pid);
		sleep(30);
	}
	return 0;
}


