#!/bin/sh
while
    make tags
    echo "--------------------------------------------------------------------------------"
    date
    echo "Files modified - remaking"
    make all
    flawfinder main
    inotifywait -qqre modify .
do
    :
done
