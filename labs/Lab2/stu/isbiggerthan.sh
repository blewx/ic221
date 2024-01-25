#!/bin/bash

  
  if [ -n "$2" ]
  then
    :
  else
    echo "ERROR: Require path and size" 1>&2
    exit 2;
  fi


  if [ "$1" -eq "$1" ] 2> /dev/null
  then
    :
  else
    echo "ERROR: Require a number for size" 1>&2
    exit 1;
  fi

  if [ "$1" -ge "0" ]
  then
    :
  else
    echo "ERROR: Require a positive number for size" 1>&2
    exit 3;
  fi

  if [ -e "$2" ] 
  then
    : 
  else
    echo "ERROR: File $2 does not exist" 1>&2
    exit 4;
  fi


  x=$(ls -la | wc -c $2 | tr -s ' ' | cut -d ' ' -f 1)
  
  if [ "$1" -gt "$x" ]
  then
    echo "no"
  else
    echo "yes"
  fi
  

