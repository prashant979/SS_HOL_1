#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char buffer[100];

	int rd = read(0, buffer, sizeof(buffer)-1);
	int wd = write(1, buffer, rd);
	return 0;
}
