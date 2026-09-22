#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){

	if(mkfifo("./myfifo", 0666) == -1) {
		perror("Fifo failed");
	} else {
		printf("Fifo created");
	}
	return 0;
}
