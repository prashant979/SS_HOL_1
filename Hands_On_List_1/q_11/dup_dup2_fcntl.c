#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int main() {
	int fd = open("test.txt", O_WRONLY | O_APPEND);
	printf("fd %d\n", fd);
	if(fd == -1) {
		perror("Open: ");
		return 1;
	}

	int fd2 = dup(fd);

	if (fd2 == -1) {
		perror("Dup: ");
		return 1;
	}
	write(fd, "Hello ", 6);
	write(fd2, "World \n", 7);
	printf("fd2 %d\n", fd2);

	int fd3 = dup2(fd, 10);
	write(fd3, "New Wolrdi\n", 10);
	printf("fd3 %d\n", fd3);

	int fd4 = fcntl(fd, F_DUPFD, 10);
	printf("fd4 %d\n", fd4);
	write(fd4, "Toxic World", 11);

	return 0;
}
