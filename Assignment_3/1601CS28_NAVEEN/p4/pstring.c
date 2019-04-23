#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[100] ="./dstring";

    execlp("/opt/X11/bin/xterm","xterm","-hold","-e","./dstring process.txt",NULL);

    exit(0) ;
}
