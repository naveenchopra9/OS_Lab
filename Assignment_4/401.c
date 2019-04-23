#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> 

void *myThread(void *vargp) 
{ 
  int *myid = (int *)vargp ;
  printf("CSE OS LAB by Thread ID: %d\n", *myid) ; 
} 

int main()
{
  pthread_t tid1, tid2, tid3 ;
  pthread_create(&tid1, NULL, myThread, (void *)&tid1) ;
  pthread_create(&tid2, NULL, myThread, (void *)&tid2) ;
  pthread_create(&tid3, NULL, myThread, (void *)&tid3) ; 
  pthread_exit(NULL) ;
}