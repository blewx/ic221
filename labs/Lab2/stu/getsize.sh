#!/bin/bash


if [ -e $1 ]
then
  ls -la | wc -c $1 | tr -s ' ' | cut -d ' ' -f 1
  

else
  echo "ERROR: File $1 does not exist" 1>&2

fi
