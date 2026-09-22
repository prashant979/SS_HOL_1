#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char data1[] = "ABCDEFGHIJ";
	char data2[] = "1234567890";

	int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd == -1) {
		perror("Open: ");
		return 1;
	}

	if(write(fd, data1, 10) == -1) {
		perror("Write: ");
		close(fd);
		return 1;
	}
	off_t ret = lseek(fd, 10, SEEK_CUR);

	if(ret == (off_t)-1){
		perror("lseek: ");
		close(fd);
		return 1;
	}
	printf("Lseek returned: %ld\n", (long)ret);

	if(write(fd, data2, 10) == -1) {
		perror("Write: ");
		close(fd);
		return 1;
	}
	close(fd);
	return 0;
}
