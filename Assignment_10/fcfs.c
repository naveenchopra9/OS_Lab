/*
  FCFS Disk Scheduling Implementation

*/

#include <stdio.h>
#include <stdlib.h>


int main(){
  int queue[1000], q_size, head, thm =0, diff,Seektime;
  float avg;

  printf("%s\n", "FCFS Disk Scheduling Algorithm:\n");

  printf("%s\n", "Enter the size of the queue :");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements :\n");
  for(int i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }

  head=50;

  queue[0]=head;

  for(int j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    thm += diff;
    printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
  }

  printf("\nTotal head movement  is : %d\n",thm);
  Seektime=5*thm;
  printf("\nAverage seek time is :%d \n", Seektime);

  return 0;
}
