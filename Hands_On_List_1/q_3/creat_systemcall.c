#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	fd = creat("myfile.txt", 0644);
	if (fd == -1) {
		perror("creation unsuccessfull");
	} else {
		printf("File Descriptor =%d\n", fd);
	}
	return 0;
}
