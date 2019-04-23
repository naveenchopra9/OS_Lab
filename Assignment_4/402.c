#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> 

int globe = 0 ; 
  
void *myThread(void *vargp) 
{ 
    int *myid = (int *)vargp ;  
    static int stat=0 ;
    int loc=0 ; 
    ++stat; ++globe; ++loc; 
    printf("Thread ID: %d, Local: %d, Static: %d, Global: %d\n", *myid, ++loc, ++stat, ++globe) ; 
} 
  
int main() 
{ 
    pthread_t tid1, tid2, tid3, tid4, tid5 ; 
    pthread_create(&tid1, NULL, myThread, (void *)&tid1) ; 
    pthread_create(&tid2, NULL, myThread, (void *)&tid2) ;
    pthread_create(&tid3, NULL, myThread, (void *)&tid3) ;
    pthread_create(&tid4, NULL, myThread, (void *)&tid4) ;
    pthread_create(&tid5, NULL, myThread, (void *)&tid5) ;
    pthread_exit(NULL) ; 
    return 0 ; 
} 