#include <stdio.h>
#include <sys/stat.h>
int main() {
	char fileName[20];
	scanf("%s", fileName);
	struct stat st;
	if (lstat(fileName, &st) == -1) {
		perror("stat: ");
		return 1;
	}

	if (S_ISREG(st.st_mode)){
		printf("Reg File\n");
	}
	if (S_ISDIR(st.st_mode)){
		printf("Dir\n");
	}
	if (S_ISLNK(st.st_mode)){
		printf("SymLink\n");
	}
	if (S_ISFIFO(st.st_mode)) {
		printf("Named Pipe\n");
	}
	if (S_ISCHR(st.st_mode)){
		printf("Char Device\n");
	}
	if (S_ISBLK(st.st_mode)) {
		printf("Block\n");
	} else {
		printf("Unknown");
	}
	return 0;
}
