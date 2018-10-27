#!/bin/sh
while 
  echo "--------------------------------------------------------------------------------"
  echo "Files modified - remaking $(date)"
	make all 
  inotifywait -qqre modify .
do
  :
done
