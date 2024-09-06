#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
        fork();
printf("1 \n");
        fork();
 printf("2 \n");
        fork();
 printf("3 \n");
       
        return 0; 
} 
