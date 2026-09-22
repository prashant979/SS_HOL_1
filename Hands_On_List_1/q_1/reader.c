#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char buffer[100];

	int fd = open("myfifo", O_RDONLY);

	while(1) {
		int n = read(fd, buffer, sizeof(buffer)-1);

		if(n > 0){
			buffer[n] = '\n';
			printf("Received %s", buffer);
		}
	}
	close(fd);
	return 0;
}
