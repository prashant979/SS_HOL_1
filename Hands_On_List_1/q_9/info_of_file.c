#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main() {
	char filename[100];
	struct stat file_stat;
	char buffer[100];

	int rd = read(0, filename, 100);
	if (filename[rd-1] == '\n') {
		rd--;
	}
	filename[rd] = '\0';
	if(stat(filename, &file_stat) == -1) {
		perror("Stat: ");
	} else {
		int len = snprintf(buffer, sizeof(buffer), "%ld\n", file_stat.st_ino);
		write(1, &"Inode: ", 7);
		write(1, buffer, len);
		
		len = snprintf(buffer, sizeof(buffer), "%ld\n", file_stat.st_nlink);
		write(1, &"Hardlink: ", 10); 
		write(1, buffer, len);

		len = snprintf(buffer, sizeof(buffer), "%d\n", file_stat.st_uid);	
		write(1, &"OwnerId: ", 9);
		write(1, buffer, len);

		printf("GroupId: %d\n", file_stat.st_gid);	
		printf("File Size: %ld bytes \n", file_stat.st_size);
		printf("Block Size: %ld bytes \n", file_stat.st_blksize);
		printf("#Blocks: %ld \n", file_stat.st_blocks);
		printf("Last access time: %s", ctime(&file_stat.st_atime));
		printf("Last modified time: %s", ctime(&file_stat.st_mtime));
		printf("Last change time: %s", ctime(&file_stat.st_ctime));
	}
	return 0;
}
