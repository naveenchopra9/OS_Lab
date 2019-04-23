#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
double sol(double x ,double n){
  double result=1.0f;
  for (int i = n - 1; i > 0; --i )
        result = 1 + x * result / i;

    return result;

}
int main(int argc, char **argv)
{
  float a, b, ans=0 ;
  a = atof (argv[0]) ;
  b = atoi(argv[1]) ;
  printf("%f\n",sol(a,b) );
  return sol(a,b) ;
}
