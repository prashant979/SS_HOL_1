#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char filename[50];
	int fd;
	sleep(30);
	for (int i = 0; i < 5; i++) {
		sprintf(filename,"file_%d.txt",i);
		fd = creat(filename, 0644);
		if (fd == -1) {
			perror("creation unsuccessfull");
		} else {
			printf("File Descriptor =%d\n", fd);
		}
	}
	while(1){}
	return 0;
}
