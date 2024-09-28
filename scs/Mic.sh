#!/bin/bash

case $BUTTON in
  1) amixer set Capture toggle ;;
  2) pavucontrol --tab=4 ;;
  3) alacritty -e alsamixer -V capture ;;
esac

# amixer get Capture | rg "\[[0-9]+%\]"
amixer get Capture | rg -q "\[off\]" # return 1: mic on, 0: mic off

if [ "$?" == 1 ]; then
  echo "  on"
else 
  echo "  off"
fi
