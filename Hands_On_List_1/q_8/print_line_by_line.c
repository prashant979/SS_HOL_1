#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	int fd = open("test.txt", O_RDONLY);
	char c;
	int n = 0;
	while((n = read(fd,&c,1)) > 0) {
		write(1, &c,1);
	}
	close(fd);
	return 0;
}
