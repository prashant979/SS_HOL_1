#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	fd = open("test.txt", O_RDWR);
	if (fd == -1) {
		perror("Open");
	} else {
		printf("File Opened Successfully");
		printf("File Descriptor %d", fd);
	}
	close(fd);
	return 0;
}
