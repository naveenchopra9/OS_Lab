#include <stdio.h>
#include <stdlib.h>
int g;

int main()
{
    static int s=1;
    int a=3;

    int *arr =(int*)malloc(2*sizeof(int));
    arr[0]=4; arr[1]=8;

    printf("Data Segment value is %d and address is %p\n",s,&s);
    printf("BSS Segment value is %d and address is %p\n",g,&g);
    printf("Stack Segment value is %d and address is %p\n",a,&a);
    printf("Heap Segment value is %d and address is %p\n",arr[0],&arr[0]);
    printf("Heap Segment value is %d and address is %p\n",arr[1],&arr[1]);

    return 0;
}
