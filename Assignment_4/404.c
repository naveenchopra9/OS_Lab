#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> 

int max=10 ;
int i=0 ;

void *Even(void *tid) 
{ 
  int *myid = (int *)tid ;
  while(i<max)
  {
    if(i%2==0)
    { printf("%d\n", i++) ; }
  }  
} 

int main() 
{ 
  pthread_t tid ; 
  pthread_create(&tid, NULL, Even, (void *)&tid) ; 
  while(i<max)
  {
    if(i%2==1)
    { printf("%d\n", i++) ; }
  }
  pthread_exit(NULL) ; 
  return 0; 
} 