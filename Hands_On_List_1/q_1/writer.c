#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char buffer[100];

	int fd= open("myfifo", O_WRONLY);

//	while(1) {
		printf("Enter Message: ");
		fgets(buffer, sizeof(buffer), stdin);
		write(fd, buffer, sizeof(buffer));
//	}
	close(fd);
	return 0;
}
