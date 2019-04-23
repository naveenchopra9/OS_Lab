
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// #define FR freopen("/pages.txt","r",stdin)
#define FR freopen("/Users/naveen/Desktop/6th/cs342/1601CS28_Assignment_8/page.txt","r",stdin)

int number_of_references=500;
int pointer,frame_size;
int faults ,hits;
bool checkvalue=false;
int freq[500];

void print(int frame_size,int frame[])
{
	int i;
	//printf("Printing the Frames: ");
	if(checkvalue)
	{
		for(i=0;i<frame_size;i++)
		{
			if(frame[i]==-1)
				printf(" ");
			else
				printf("%d ",frame[i]);
		}
    }
    checkvalue=false;
	printf("\n");
}

int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
	int min_indx=0,minv=10000;
	for(int i =0 ; i< frame_size ; i++){
		if(minv>freq[frame[i]]){
			minv=freq[frame[i]];
			min_indx=i;
		}
	}
	return min_indx;
}

void add_reference(int frame_size,int frame[], int reference, int current_position,int reference_length, int references[])
{
	int i;
	bool allocated=false;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==reference)
		{
			hits++;
			allocated = true;
			break;
		}

		else if(frame[i]==-1)
		{
			frame[i] = reference;
			checkvalue=true;
			faults++;
			allocated = true;
			break;
		}
	}

	if(allocated==false)
	{
		int j = predict(reference_length,references,current_position,frame_size,frame,current_position+1);
		checkvalue=true;
		frame[j] = reference;
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
			if(reference[i]==-1)
					break;
			i++;
		}
		
		i=0;
		// memset(freq,0,sizeof(freq));
		for(int i =0 ; i< 500; i++){
			freq[i]=0;
		}

		while(1)
		{
			// scanf("%d",&reference[i]);
			if(reference[i]==-1)
					break;

			add_reference(frame_size,frame,reference[i],i,number_of_references,reference);
			freq[reference[i]]++;
			i++;
		}

		printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
	}

	return 0;
}
