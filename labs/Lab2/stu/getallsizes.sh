#!/bin/bash





for var in "$@"
do
  if [ -e $var ]
  then
    echo -n "$var " 
    ls -la | wc -c $var | tr -s ' ' | cut -d ' ' -f 1
  else
    echo "ERROR: File $var does not exist" 1>&2
  fi

done



  


