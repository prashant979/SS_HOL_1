#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("Fork Failed: ");
		return 1;
	} else if (pid) {
		printf("Parent process:\n");
        	printf("Parent PID: %d\n", getpid());
        	printf("Child PID: %d\n", pid);
	} else {
		printf("Child process:\n");
        	printf("Child PID: %d\n", getpid());
        	printf("Parent PID: %d\n", getppid());
	}
	return 0;
}
