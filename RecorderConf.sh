#!/bin/bash
function config()
{
    echo $1 > Recorder.conf
}

inputFile=""
if [ $# -ge 1 ]
then
inputFile=$1
else
read -p "Path of Input File:(Example /dev/input/by-path/platform-i8042-serio-0-event-kbd):" inputFile
fi
config $inputFile
