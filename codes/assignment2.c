#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1_pid, child2_pid;

    child1_pid = fork();
    if (child1_pid < 0) {
        perror("failed for child1");
        return 1;
    } else if (child1_pid == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("failed exec ls");
        return 1;
    }

    child2_pid = fork();
    if (child2_pid < 0) {
        perror("fork failed child2");
        return 1;
    } else if (child2_pid == 0) {
        execl("/bin/date", "date", NULL);
        perror("failed exec date");
        return 1;
    }

    printf("Parent process done\n");

    return 0;
}
