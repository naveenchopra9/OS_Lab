#!/bin/bash

# Assignment submitted by: Piyush Singh (1601CS30)
 
echo "Enter the value of n : "
read n
declare -a Fib=(0 1)
for((i=2; i<$n; i++));
  do
    {
      Fib[i]=$((Fib[i-1]+Fib[i-2]))  # Creating the Fibonacci Sequence 
    }
  done
echo "The Fibonacci sequence is : "
echo "${Fib[@]}" 
z=$((n/3))
for((i=0;i<$z;i++));
do
  {
    Fib[i]=$((Fib[i]+Fib[i+2*z]))  # Adding 1st & 3rd elements
  }
done
echo "After summing and concatinating we get : "
for((i=0; i<$((2*z)); i++));
do
  { 
    echo -ne "${Fib[i]}" 
  }
done
