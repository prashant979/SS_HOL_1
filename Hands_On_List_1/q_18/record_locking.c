#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[20];
 	int balance;
} Emp;


void lock_record(int fd, int record_no, short type) {
	struct flock lock;

	lock.l_type = type;
	lock.l_whence = SEEK_SET;
	lock.l_start = (record_no - 1) * sizeof(Emp);
	lock.l_len = sizeof(Emp);
	lock.l_pid = getpid();

	if (fcntl(fd, F_SETLKW ,&lock) == -1) {
		perror("LockFailed: ");
		exit(1);
	}

}

void unlock_record(int fd, int record_no) {
	struct flock lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (record_no - 1) * sizeof(Emp);
	lock.l_len = sizeof(Emp);
	lock.l_pid = getpid();

	if (fcntl(fd, F_SETLK, &lock) == -1) {
		perror("Unlock Failed: ");
		exit(1);
	}
}

void initialize_file()
{
    int fd = open("emp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    Emp records[3] = {
        {1, "Alice", 1000},
        {2, "Bob", 2000},
        {3, "Charlie", 3000}
    };

    if (write(fd, records, sizeof(records)) != sizeof(records)) {
        perror("write");
        close(fd);
        exit(1);
    }

    close(fd);
}

void read_record(int record_no) {
	int fd = open("emp.txt", O_RDONLY);
	if (fd == -1) {
		perror("Open: ");
		exit(1);
	}
	printf("Process %d: Requesting READ lock on record %d\n", getpid(), record_no);
	lock_record(fd, record_no, F_RDLCK);
	printf("Process %d: READ lock acquired on record %d\n",
           getpid(), record_no);

	Emp emp;
	off_t offset = (record_no - 1) * sizeof(Emp);

	if (pread(fd, &emp, sizeof(Emp), offset) == -1) {
		perror("Read_Record: ");
		unlock_record(fd, record_no);
		close(fd);
		exit(1);
	}
	printf("Record %d -> ID: %d, Name: %s, Balance: %d\n",
           record_no,
           emp.id,
           emp.name,
    	   emp.balance);

	printf("Enter to Quit\n");
	getchar();
	getchar();
	unlock_record(fd, record_no);
	close(fd);
}

void write_record(int record_no, int balance) {
       int fd = open("emp.txt", O_RDWR);
       if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Process %d: Requesting WRITE lock on record %d\n",
           getpid(), record_no);
    lock_record(fd, record_no, F_WRLCK);

    printf("Process %d: WRITE lock acquired on record %d\n",
           getpid(), record_no);
    Emp emp;

    off_t offset = (record_no - 1) * sizeof(Emp);

    if (pread(fd, &emp, sizeof(Emp), offset) == -1) {
	    perror("Pread: ");
	    unlock_record(fd, record_no);
	    close(fd);
	    exit(1);
    }
 	printf("Before modification:\n");
    	printf("ID: %d, Name: %s, Balance: %d\n",
           emp.id,
           emp.name,
           emp.balance);
	
	emp.balance = balance;

	if (pwrite(fd, &emp, sizeof(Emp), offset) == -1) {
		perror("Pwrite: ");
		unlock_record(fd, record_no);
		close(fd);
		exit(1);
	}

	printf("After modification:\n");
    	printf("ID: %d, Name: %s, Balance: %d\n",
           emp.id,
           emp.name,
           emp.balance);

	printf("Enter to Quit\n");
	getchar();
	getchar();
	unlock_record(fd, record_no);
	close(fd);
}
    

int main() {
	printf("1. Initalize\n");
	printf("2. Read Record\n");
	printf("3. Write Record\n");

	int choice;
	scanf("%d", &choice);

	if (choice == 1) {
		initialize_file();
		printf("Records Created\n");
	}
	else if (choice == 2) {
		int record;
		printf("Enter Record to read: \n");
		scanf("%d", &record);
		read_record(record);
	} else {
		int record;
		int balance;
		printf("Enter Record to update: \n");
		scanf("%d", &record);
		printf("Enter balance: \n");
		scanf("%d", &balance);
		write_record(record, balance);
	}
	return 0;

}
