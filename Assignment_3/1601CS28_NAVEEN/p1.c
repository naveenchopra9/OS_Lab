#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

char msg1[16] = "hello, world #1";
char msg2[16]= "hello, world #2";
char msg3[16] = "hello, world #3";
int sizelength=16;
int main()
{
    char inbuf[sizelength];
    int p[2], pid;
    ssize_t nbytes;

    if (pipe(p) < 0)
        exit(1);
    /* continued */
    if ((pid = fork()) > 0) {
        write(p[1], msg1, sizelength);
        write(p[1], msg2, sizelength);
        write(p[1], msg3, sizelength);

        // Adding this line will
        // not hang the program
        // close(p[1]);
        wait(NULL);
    }

    else {
        // Adding this line will
        // not hang the program
        // close(p[1]);
        printf("parent id and child id are :%d , %d\n",getppid(),getpid());
        while ((nbytes = read(p[0], inbuf, sizelength)) > 0)
            printf("%s\n", inbuf);

        if (nbytes != 0)
            exit(2);

        printf("Finished reading\n");
    }
    return 0;
}
