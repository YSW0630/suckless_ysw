#!/bin/bash

case $BUTTON in
  2) amixer set Capture toggle ;;
esac

amixer get Capture | rg -q "\[off\]" # return 1: mic on, 0: mic off

if [ "$?" == 1 ]; then
  echo "^c#98c379^ "
else 
  echo "^c#98c379^ "
fi
