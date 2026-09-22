#include <stdio.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
int main() {
	int fd = open("test.txt", O_RDWR);
	if (fd == -1) {
		perror("Open: ");
	}
	printf("Choose lock type:\n");
    	printf("1. Write Lock\n");
    	printf("2. Read Lock\n");

   	int choice;
    	scanf("%d", &choice);

	struct flock lock;

	lock.l_type = (choice == 1) ? F_WRLCK : F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	printf("Trying to acquire lock...\n");

	if (fcntl(fd, F_SETLKW, &lock) == -1) {
		perror("fcntl");
		close(fd);
		return 1;
	}

	if (choice == 1) {
        	printf("Write lock acquired.\n");
	}
    	else {
        	printf("Read lock acquired.\n");
	}

    	printf("File is locked. Press ENTER to release the lock...\n");
    	getchar();
    	getchar();

	lock.l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, &lock) == - 1) {
		perror("Unlock: ");
		return 1;
	}
	printf("Lock released.\n");

    	close(fd);

   	 return 0;
}
