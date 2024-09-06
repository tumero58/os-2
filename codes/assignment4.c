#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0) {
        perror("failed fork");
        return 1;
    } else if (child_pid == 0) {
        execl("/bin/grep", "grep", "main", "../test.txt", NULL);
        perror("failed exec");
        return 1;
    } else {
        printf("Parent process completed\n");
    }

    return 0;
}
