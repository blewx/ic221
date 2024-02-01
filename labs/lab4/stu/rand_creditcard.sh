#!/bin/bash


while true; do
  random_number=$RANDOM
  let "random_number %=9";
  let "random_number = random_number +1";
  range=10
  for i in {1..15}; 
   do
     r=$RANDOM
     let "r %= $range"
     random_number="$random_number""$r";
   done;
   ./check $random_number 1>/dev/null
   if [ $? -eq 0 ]; then
     echo $random_number
     break
   fi
done
    
