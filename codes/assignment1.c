#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{
       	pid_t child_pid;
	child_pid = fork();
	if(child_pid < 0){
		perror("failed fork");
		return 1;
	} else if(child_pid == 0){
		execl("/bin/ls","ls",NULL);
		perror("failed exec");
		return 1;
	} else {
		printf("Parent process done");
	}
return 0;
} 
