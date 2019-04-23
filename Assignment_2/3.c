#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 

int x = 50 ;

int main() 
{ 
  printf("Original global value : %d\n", x) ;

  pid_t pid ;
  pid = fork() ;
  
  if(pid != 0) 
  {
    x = x+1 ;
    printf("New global value = %d , PID : %u\n", x,getpid()) ;
    exit(0) ; 	
  }
  else 
  {
    x = x-1 ;
    printf("New global value = %d , PID : %u\n", x,getpid()) ;
    exit(0) ;
  }
  return 0 ; 
} 

