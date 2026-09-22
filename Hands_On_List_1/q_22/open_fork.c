#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int fd = open("test.txt", O_WRONLY);

	pid_t pid = fork();

	if (pid == -1) {
		perror("Fork Failed: ");
		close(fd);
		return 1;
	}
	if (pid) {
		char *m = "Parent ";
		lseek(fd, 0, SEEK_END);
		write(fd, m, 7);
		printf("Parent\n");
	} else {
		char *m = "Child";
		lseek(fd, 0, SEEK_END);
		write(fd, m, 5);
		printf("Child\n");
	}
	close(fd);
	return 1;
}
