#include <stdio.h>
#include <unistd.h>
int main(){
	printf("%d",getpid());
	sleep(30);
	while(1) {
	}
	return 0;
}
