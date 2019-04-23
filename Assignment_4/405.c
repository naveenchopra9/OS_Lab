#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> 

pthread_t tid[2] ;
int count=0 ;
pthread_mutex_t mutex ;
unsigned int rc ;

void *Even(void *tid) 
{ 
  int *myid = (int *)tid ;
  rc = pthread_mutex_lock(&mutex) ;
  do
  {
    if(count%2==0)
    {
      printf("%d\n", count) ;
      count++ ;
    }
    else
    { rc=pthread_mutex_unlock(&mutex) ; }
  } 
  while(count<=20000) ;
} 

void *Odd(void *tid) 
{ 
  int *myid = (int *)tid ;
  rc = pthread_mutex_lock(&mutex) ;
  do
  {
    if(count%2!=0)
    {
      printf("%d\n", count) ;
      count++ ;
    }
    else
    { rc = pthread_mutex_unlock(&mutex) ; }
  } 
  while(count<=20000) ;
}

int main() 
{ 
  pthread_create(&tid[0], 0, Odd, 0) ;
  pthread_create(&tid[1], 0, Even, 0) ;
  sleep(2) ;
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  pthread_exit(NULL) ; 
} 
