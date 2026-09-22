#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
	int ticket = 100;
	int fd = open("test.txt", O_RDWR);

	if (fd == -1) {
		perror("Open: ");
		return 1;
	}

	//if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
	//	perror("Write: ");
	//	close(fd);
	//	return 1;
	
	//}
	lseek(fd, 0, SEEK_SET);
	int t1;
	read(fd, &t1, sizeof(ticket));
	printf("%d\n", t1);
	close(fd);
	printf("Initial ticket: %d\n", ticket);
	return 0;
}
