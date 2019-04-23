#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define no_philosopher 5
#define no_Fork 5
pthread_mutex_t lock ;

sem_t forkAvailable[no_Fork] ;
int allocationMatrix[no_philosopher][no_philosopher] ;
int requestMatrix[no_philosopher][no_philosopher] ;

void printMatrix()
{
	int i,j ;
	pthread_mutex_lock(&lock) ;
	printf("Resource Allocation Matrix : \n") ;
	for(i=0;i<no_philosopher;i=i+1)
	{
		for(j=0;j<no_Fork;j=j+1)
		{ printf("%d ", allocationMatrix[i][j]) ; }
		printf("\n") ;
	}
	printf("Request Matrix :\n") ;
	for(i=0;i<no_philosopher;i=i+1)
	{
		for(j=0;j<no_Fork;j=j+1)
		{ printf("%d ", requestMatrix[i][j]) ; }
		printf("\n") ;
	}
	pthread_mutex_unlock(&lock) ;
}

void request(int ph_id, int fork, int re)
{ requestMatrix[ph_id][fork] = re ; }

void allocate(int ph_id,int fork,int re)
{ allocationMatrix[ph_id][fork] = re ; }

void P(int ph_id, int fork)
{
	request(ph_id,fork,1) ;
	sem_wait(&forkAvailable[fork]) ;
	request(ph_id,fork,0) ;
	allocate(ph_id,fork,1) ;
}

void V(int ph_id, int fork)
{
	allocate(ph_id,fork,0) ;
	sem_post(&forkAvailable[fork]) ;
}

void* dine(void *arg)
{
	int philId = *((int *)arg) ;
	while(!0)
	{
		int leftfork=(philId), rightfork=((philId+1)%no_Fork) ;
		P(philId,leftfork) ;
		printf("Philosopher %d grab fork %d (left)\n", philId,leftfork) ;
		sleep(1) ;
		P(philId,rightfork) ;
		printf("Philosopher %d grab fork %d (right)\n", philId,rightfork) ;
		sleep(1) ;
		printf("Philosopher %d starts eating.\n", philId) ;
		sleep(1) ;
		printMatrix() ;
 	    sleep(1) ;
 		printf("Philosopher %d ends eating and releases forks %d(left) and %d(right)\n", philId,leftfork,rightfork) ;
		V(philId,leftfork) ;
		V(philId,rightfork) ;
		printf("Philosopher %d starts thinking\n", philId) ; 
	}
}

int main()
{
    int i,j ;
    pthread_t threads[no_philosopher] ;
    srand(time(0)) ;
    for(i=0;i<no_Fork;i=i+1)
    { sem_init(&forkAvailable[i],0,1) ; }
    for(i=0;i<no_philosopher;i=i+1)
    {
   	   int thr = pthread_create(&threads[i],NULL,dine,&i) ;
   	   if(!(thr>0))
   	   { printf("Thread failed %d\n", i) ; }
   	   printf("Philosopher %d starts thinking\n", i) ; 
   	   sleep(0.1) ;
    }
    while(1)
    {
   	   int deadlock=0 ;
 	   for(i=0;i<no_Fork;i=i+1)
	   {
	    	if(allocationMatrix[i][i]!=0)
	    	{ deadlock = deadlock+1 ; }
	   }
	   if(!(deadlock==no_philosopher))
	   { continue ; }
	   printf("Parent detected deadlock, going to initiate recovery\n") ;
	   int dropFork = rand()%no_Fork ;
       printf("Parent preempts Philosopher %d\n",dropFork) ;
       V(dropFork,dropFork) ;
       sleep(10) ;
       printMatrix() ;
       sleep(1) ;
    }
    return 0 ;
}