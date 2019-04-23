#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  int a, b, ans=0 ;
  a = atoi(argv[0]) ;
  b = atoi(argv[1]) ;
  if(*argv[2]=='+')
  { ans = a+b ; }
  else
  { ans = a-b ; }
  return ans ;
}
