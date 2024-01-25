#!/bin/bash

cut -d ':' -f 5 /etc/passwd | grep "^$1" | cat
