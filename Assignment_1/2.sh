#!/bin/bash

# Assignment submitted by: Piyush Singh (1601CS30)
 
#2.a)
echo "The number of unique characters are : "
tr ' ' '\n' < welcome.txt | uniq -c | sort | wc -l

#2.b)
echo "The word which occurs maximum number of times is : "
cat welcome.txt | tr ' ' '\n' | sort | uniq -c | sort -n | tail -n1