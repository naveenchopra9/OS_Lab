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
  char sign ;
  printf("Enter the two integers and the sign:\n") ;
  scanf("%s %c %s", n1, &sign, n2) ;
  //printf("%c %c %c\n", n1, sign, n2) ;
  pid = fork() ;
  if(pid==0)
  {
    if(execl("./server", n1, n2, &sign, NULL)<0)
    perror("error") ;
  }
  else if(pid>0)
  {
    waitpid(pid, &status, 0) ;
    printf("result of n1 :%s  %c n2 : %s == %d\n", n1,sign,n2, WEXITSTATUS(status)) ;
  }
  exit(0) ;
}
