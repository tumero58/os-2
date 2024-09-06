#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if(child_pid < 0){
    	perror("fork failed");
	return 1;
    } else if (child_pid == 0){
    	execl("/bin/echo","echo","Hello from the child process",NULL);
	perror("failed exec");
	return 1;
    } else{
	printf("Parent process done \n");
    }
  return 0;
}
