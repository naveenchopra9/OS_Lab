#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char*argv[])
{
    int num =0;
    char word[2000];
    char string[30];
    char* fn1 = argv[1];

    // char fn0[] = "/Users/naveen/Desktop/6th/cs342/lab3/p4/process.txt";

    FILE *in_file = fopen(fn1, "r");

    if (in_file == NULL)
    {
        printf("Error file missing\n");
        exit(-1);
    }


    int cnt=0;
    while(!feof(in_file))//this loop searches the for the current word
    {
        fscanf(in_file,"%s",string);
        cnt++;
        if(cnt%3==0){
            printf("%s ",string);
        }
    }
//    printf("we found the word %s in the file %d times\n",word,num );
    return 0;
}
