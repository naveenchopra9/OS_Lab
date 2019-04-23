#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main(){
  int queue[1000];
  int head, max, q_size, temp, sum,Seektime;
  int dloc; //location of disk (head) arr


  printf("%s", "Input no of disk locations :");
  scanf("%d", &q_size);
  head=50;

  printf("%s\n", "Input elements into disk queue :");
  for(int i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
  }
  queue[q_size] = head; //add RW head into queue
  q_size++;

  //sort the array
  for(int i=0; i<q_size;i++){

    for(int j=i; j<q_size; j++){

      if(queue[i]>queue[j]){

        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  max = queue[q_size-1];

  //locate head in the queue

  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

      for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
      for(int j=dloc+1; j<q_size; j++){
        printf("%d --> ",queue[j]);
      }

      } else {

      for(int j=dloc+1; j<q_size; j++){
          printf("%d --> ",queue[j]);
      }
      for(int j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }

  }



  printf("\n");
  sum  = head + max;
  printf("\nTotal head movement  is : %d\n",sum);
  Seektime=5*sum;
  printf("\nAverage seek time is :%d \n", Seektime);

  return 0;
}
