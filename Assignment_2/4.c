#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 

int main() 
{ 
  int t, res ;
  printf("Enter the number of seconds : ") ;
  scanf("%d", &t) ;
  pid_t pid ;
  pid  = fork() ;
  if(pid != 0) 
  {
    wait(&t) ;
    printf("PID : %u, Parent died!\n", getpid()) ;
    exit(0) ; 	
  }
  else 
  {
    sleep(t) ;
    printf("PID : %u, Child Died!\n", getpid()) ;
    exit(0) ;
  }

  return 0 ; 
} 

