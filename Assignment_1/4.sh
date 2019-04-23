#!/bin/bash

# Assignment submitted by: Piyush Singh (1601CS30)

clear
cd OS
filename=($(ls -rSA))
for((i=1;i<=4;i++))
do
{ 
cat ${filename[i]} | head -n1 -q >>${filename[0]} 
}
done
