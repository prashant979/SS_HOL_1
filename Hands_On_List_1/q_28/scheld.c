#include <stdio.h>
#include <sched.h>

int main()
{
    int min_priority, max_priority;

    min_priority = sched_get_priority_min(SCHED_FIFO);
    max_priority = sched_get_priority_max(SCHED_FIFO);

    if (min_priority == -1 || max_priority == -1)
    {
        perror("sched_get_priority");
        return 1;
    }

    printf("SCHED_FIFO:\n");
    printf("Minimum real-time priority = %d\n", min_priority);
    printf("Maximum real-time priority = %d\n", max_priority);

    min_priority = sched_get_priority_min(SCHED_RR);
    max_priority = sched_get_priority_max(SCHED_RR);

    printf("\nSCHED_RR:\n");
    printf("Minimum real-time priority = %d\n", min_priority);
    printf("Maximum real-time priority = %d\n", max_priority);

    return 0;
}
