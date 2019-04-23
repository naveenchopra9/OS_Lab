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
  int pid, status ;
  char n1[40], n2[40];
  printf("Enter the x and n :\n") ;
  scanf("%s %s", n1, n2) ;
  //printf("%c %c %c\n", n1, sign, n2) ;
  pid = fork() ;
  if(pid==0)
  {
    printf("Child(PID=%d) For x = %s the first %s terms yields: \n",getpid(),n1,n2 );
    // printf("Child(PID=%d) : For x = %s the first %s terms yields :",getpid(),n1,n2);
    if(execl("./file2", n1, n2, NULL)<0)
    perror("error") ;
    printf("\n" );
  }
  else if(pid>0)
  {
    printf("Parent(PID=%d) : Done\n",getpid() );
    waitpid(pid, &status, 0) ;
    // printf("result :\n",WEXITSTATUS(status)) ;
  }
  exit(0) ;
}
