#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child: Running ls...\n");
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        exit(1);
    } else {
        printf("Parent: Waiting for child...\n");
        wait(NULL);
        printf("Parent: Child finished.\n");
    }

    return 0;
}

