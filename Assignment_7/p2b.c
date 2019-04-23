
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// #define FR freopen("/pages.txt","r",stdin)
#define FR freopen("/Users/naveen/Desktop/6th/cs342/Assignment7/pages.txt","r",stdin)


int number_of_references=500;
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


int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
	int pos = -1, farthest = start, i;
	for(i=0;i<frame_size;i++)
	{
		int j;
		for(j=start-1;j>=0;j--)
		{
			if(frame[i]==references[j])
			{
				if(j<farthest)
				{
					farthest=j;
					pos=i;
				}
				break;
			}
		}
		if(j==page_no)
			return i;
	}
	if(pos == -1)
		return 0;
	else
		return pos;
}

void add_reference(int frame_size,int frame[], int reference, int current_position,int reference_length, int references[])
{
	int i;
	bool allocated=false;
	for(i=0;i<frame_size;i++)
	{

		if(frame[i]==reference)
		{
			printf("  Hit for %d | ", reference);
			hits++;
			allocated = true;
			break;
		}
		else if(frame[i]==-1)
		{
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			allocated = true;
			break;
		}
	}
	if(allocated==false)
	{
		int j = predict(reference_length,references,current_position,frame_size,frame,current_position+1);

		frame[j] = reference;
		printf("Fault for %d | ", reference);
		faults++;
	}
	print(frame_size, frame);
}

int main()
{
	FR;

	while(1)
	{
		hits=0;
		faults=0;
		pointer=0;
		scanf("%d",&frame_size);
		if(frame_size==-1)break;
		int frame[frame_size];
		int i=0;
		for(i=0;i<frame_size;i++)
		{
			frame[i] = -1;
		}
		print(frame_size,frame);
		int reference[number_of_references];
		i=0;
		while(1)
		{
			scanf("%d",&reference[i]);
			if(reference[i]==-1)break;
			add_reference(frame_size,frame,reference[i],i,number_of_references,reference);
			i++;
		}

		printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
	}

	return 0;
}
