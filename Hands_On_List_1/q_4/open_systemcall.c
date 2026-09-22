#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	fd = open("test.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd == -1) {
		perror("Open");
	} else {
		printf("File Opened Successfully");
		printf("File Descriptor %d", fd);
	}
	close(fd);
	return 0;
}
