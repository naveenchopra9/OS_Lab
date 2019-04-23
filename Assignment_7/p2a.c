#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// #define FR freopen("/pages.txt","r",stdin)
#define FR freopen("/Users/naveen/Desktop/6th/cs342/Assignment7/pages.txt","r",stdin)

int number_of_references=100;
int pointer,frame_size;
int faults ,hits;
void print(int frame_size,int frame[])
{
	int i;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==-1)
			printf("0 ");
		else
			printf("%d ",frame[i]);
	}

	printf("\n");
}

void add_reference(int frame_size,int frame[], int reference)
{
	int i;
	bool alloted = false;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==reference)
		{
			alloted = true;
			printf("  Hit for %d | ", reference);
			hits++;
			break;
		}
		else if(frame[i]==-1)
		{
			alloted = true;
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			break;
		}
	}

	if(alloted == false)
	{
		faults++;
		printf("Fault for %d | ", reference);
		frame[pointer] = reference;
		pointer = (pointer+1)%frame_size;
	}
	print(frame_size, frame);
}

int main()
{
	FR;

	while(1){
	hits=0;
	faults=0;
	pointer=0;
	scanf("%d",&frame_size);
	if(frame_size==-1)break;
	int i,number_of_references;
	int frame[frame_size];
	for(i=0;i<frame_size;i++)
	{
		frame[i] = -1;
	}
	print(frame_size,frame);
	int reference1;
	while(1)
	{
		scanf("%d",&reference1);
		if(reference1==-1){
			break;
		}

		add_reference(frame_size,frame,reference1);
	}

	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
 }
	return 0;
}
