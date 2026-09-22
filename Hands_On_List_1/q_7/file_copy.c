#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	char buffer[50];
	int fd = open("test.txt", O_RDONLY);

	int fd2 = creat("test2.txt", 0644);
	int n = 0;
	while((n = read(fd, buffer, 50)) > 0) {
		write(fd2, buffer,n);
	}
	close(fd);
	close(fd2);
	return 0;
}
