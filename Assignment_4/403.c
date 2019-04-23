#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> 

void *Busy(void *tid) 
{ 
    int *myid = (int *)tid ;
    printf("Busy thread ID: %d\n", *myid) ;
    sleep(2) ; 
    pthread_exit((void *)tid) ;
} 

int main()
{
    int i ;
    pthread_t tid ;
    int err1, err2 ;
    void *status ;
    for(i=1;i<=5;i++)
    {
        printf("Creating thread %d\n", i) ;
        err1 = pthread_create(&tid, NULL, Busy, (void *)&tid) ;
        if(err1)
        { printf("ERROR; return code from pthread_create() is %d\n", err1) ; }
        else
        { printf("ERROR; return code from pthread_create() is %d\n", err1) ; }
        err2 = pthread_join(tid, &status) ;
        if(err2)
        { printf("ERROR; return code from pthread_join() is %d\n", err2) ; }
        else
        { printf("ERROR; return code from pthread_join() is %d\n", err2) ; }
        int *PS = (int *)status;
        printf("Completed join with thread %ld having a status of %d\n",tid,*PS) ;
    }
    printf("Exiting from program.\n");
    pthread_exit(NULL);
    return 0;
}