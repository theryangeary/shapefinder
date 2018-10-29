#!/bin/sh
while
  echo "--------------------------------------------------------------------------------"
  date
  echo "Files modified - remaking"
	make all
  flawfinder main
  inotifywait -qqre modify .
do
  :
done
