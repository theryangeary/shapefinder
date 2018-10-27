#!/bin/sh
while 
  echo "--------------------------------------------------------------------------------"
  echo "Files modified - remaking $(date)"
	make test 
  inotifywait -qqre modify .
do
  :
done
