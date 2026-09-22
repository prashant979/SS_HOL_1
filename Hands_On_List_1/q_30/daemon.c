#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
        pid_t pid = fork();

        if (pid) {
                printf("Parent Exiting\n");
                exit(0);
        }
        setsid();
        sleep(60);
        execl("/bin/sh", "sh", "./myscript.h", (char *)NULL);
        printf("ScriptFailed");
        return 1;
}
