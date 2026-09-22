#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	int fd = open("test.txt", O_RDWR);

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	if (fcntl(fd, F_SETLKW, &lock) == -1) {
		perror("Fcnlt: ");
		return 1;
	}
	printf("Lock Acquired\n");

	lseek(fd, 0, SEEK_SET);

	int ticket;
	int len;
        if((len= read(fd, &ticket, sizeof(ticket))) == -1){
       		perror("Read: ");
		return 1;
       	}
	printf("Current Ticket: %d\n", ticket);
	ticket++;
	lseek(fd, 0, SEEK_SET);
	if (write(fd, &ticket, sizeof(ticket)) == -1) {
		perror("Write: ");
		return 1;
	}
	printf("Updated Ticket: %d\n", ticket);

	lock.l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, &lock) == -1) {
		perror("Unlock: "); 
		return 1;
	}
	printf("Lock Released:\n");
	close(fd);
	return 0;
}


		     
