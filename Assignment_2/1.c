#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 

int main() 
{ 
  pid_t pid ;
  pid = fork() ;
  if(pid != 0) 
  {
    printf("You've entered Parent process \n") ;
    printf("Parent process id : %u \n", getpid()) ;
    printf("Child id from parent process : %u \n", pid) ;
    exit(0) ; 	
  }
  else 
  {
    printf("You've entered Child process \n") ;
    printf("Child process id : %u \n", getpid()) ;
    printf("Parent id from child process : %u \n", getppid()) ;
    exit(0) ;
  }
  
  return 0 ; 
} 

