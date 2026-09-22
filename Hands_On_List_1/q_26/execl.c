#include <stdio.h>
#include <unistd.h>
int main() {
	printf("Executing Hello\n");
	execl("./hello", "Prashant", NULL);
	printf("This part not executed");
	return 0;
}
