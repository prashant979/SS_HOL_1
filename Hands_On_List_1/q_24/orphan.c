#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	int fd[2];
	// fd -> 0 -> read end
	// fd -> 1 -> write end

	pipe(fd);
	pid_t pid = fork();

	if (pid) {
		sleep(5);
		close(fd[0]); // closing read end for parent
		printf("Parent: %d\n", getpid());
		write(fd[1], "A", 1);
		close(fd[1]);
		exit(0);
	} else {
		sleep(20);
		close(fd[1]); // closing write end for child
		printf("Child: %d\n", getpid());
		printf("C_Parent: %d\n", getppid());
		char c;
		read(fd[0], &c, 1); 
		close(fd[0]);
	}
	return 0;
}

