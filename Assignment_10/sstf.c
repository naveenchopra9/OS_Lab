/*
  SSTF Disk Scheduling Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_near(int fin[] ,int arr[] ,int n ,int start)
{
  int i,min_pos ,mini=9999;
  for(i=0;i<n;i++)
  {
    if(fin[i]==0)
    {
       int t = abs(arr[i]- start);
       if(t < mini)
         {
          mini = t ;
          min_pos =i;
         }
    }
  }
  return min_pos;
}

int SSTF(int arr[] ,int n ,int start)
{
  int sstf_ans=0;
  int nearest;
  int fin[n];
    for(int i =0 ; i< n ; i++)fin[i]=0;    
    for(int i=0;i<n;i++)
    {
      nearest = find_near(fin , arr , n ,start);
      sstf_ans = sstf_ans +  abs(arr[nearest] - start);
        printf("Move from %d to %d with Seek %d\n",arr[nearest],start,abs(arr[nearest] - start));
      start = arr[nearest];
      fin[nearest]=1;
    }
    return sstf_ans;
}

int main() {
  int queue[100], queue2[100], q_size, head, seek=0, temp,Seektime;
  float avg;

  printf("%s\n", "SSTF Disk Scheduling Algorithm");

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(int i=0; i<q_size; i++){
    scanf("%d",&queue[i]);
  }

  head=50;

  seek=SSTF(queue,q_size,head);

  printf("\nTotal head movement  is : %d\n",seek);
  Seektime=5*seek;
  printf("\nAverage seek time is :%d \n", Seektime);

  return 0;
}
