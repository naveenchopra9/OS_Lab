#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 

int fac(int n)
{
  if(n==0 || n==1)
  { return 1 ; }
  else
  { return fac(n-1)*n ; }
}

int main() 
{ 
  int n, res ;
  printf("Enter an integer : ") ;
  scanf("%d", &n) ;
  res = fac(n) ;
  printf("Before Fork\n") ;
  printf("Factorial is : %d  PID: %u \n", res, getpid()) ; 	
  fork() ;
  res = fac(n) ;
  printf("After Fork\n") ;
  printf("Factorial is : %d  PID: %u \n", res, getpid()) ; 	
  
  return 0 ; 
} 

