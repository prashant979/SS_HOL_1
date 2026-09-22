#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
	printf("Polciy: %d\n", policy);
    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;

        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;

        case SCHED_RR:
            printf("SCHED_RR\n");
            break;

        default:
            printf("Unknown policy\n");
    }
}

int main() {
	pid_t pid = getpid();
	int policy = sched_getscheduler(pid);

	struct sched_param param;

	printf("Current scheduling policy: ");
    	print_policy(policy);

	param.sched_priority = 10;

	if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
		perror("FIFO: ");
	}

	printf("After changing to SCHED_FIFO: ");
        policy = sched_getscheduler(pid);
        print_policy(policy);

	param.sched_priority = 10;
	if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
		perror("RR: ");
	}
	printf("After changing to SCHED_RR: ");

        policy = sched_getscheduler(pid);
        print_policy(policy);

	return 0;
}
