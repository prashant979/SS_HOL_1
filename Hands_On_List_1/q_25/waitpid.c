#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t child[3];

	for (int i = 0; i < 3; i++) {
		child[i] = fork();

		if (child[i] == 0) {
			printf("Child %d: PID = %d, PPID = %d\n",
                   i + 1, getpid(), getppid());

            		sleep(2 + i);   // Child 1: 2 sec, Child 2: 3 sec, Child 3: 4 sec

            		printf("Child %d exiting\n", i + 1);
            		exit(i + 1);
		}
	}
	printf("Parent: PID = %d\n", getpid());
    	printf("Parent: Waiting for Child 2 (PID = %d)\n", child[1]);
	
	int status;
	pid_t result = waitpid(child[1], &status, 0);

	if (WIFEXITED(status)) {
        	printf("Parent: Child 2 exited with status %d\n",
               WEXITSTATUS(status));
    	}

	printf("Parent: Now waiting for remaining children...\n");

    	// Reap the other two children
    	waitpid(child[0], NULL, 0);
    	waitpid(child[2], NULL, 0);

    	printf("Parent: All children completed\n");

    	return 0;
}
