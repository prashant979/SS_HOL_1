#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
int main() {
	fd_set readFds;
	struct timeval timeout;

	FD_ZERO(&readFds);
	FD_SET(0, &readFds);

	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	printf("Waiting 10 sec..\n");
	// fflush(stdout);

	int ret = select (0+1, &readFds, NULL, NULL, &timeout);

	if (ret == -1) {
		perror("Select: ");
	} else if (ret == 0) {
		printf("No Data Available within 10 sec\n");
	} else {
		if (FD_ISSET(0, &readFds)){
			printf("Data Available\n");

			char buffer[100];
			int n = read(0, buffer, 100);

			if(n > 0) {
				buffer[n] = '\0';
				printf("Data: %s", buffer);
			}
		}
	}
	return 0;
}
