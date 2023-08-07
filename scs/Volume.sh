#!/bin/bash

case $BUTTON in 
  1) pamixer -ud 1 --allow-boost && pkill -RTMIN+4 dwmblocks;;
  2) pamixer -t && pkill -RTMIN+4 dwmblocks ;;
  3) pamixer -ui 1 --allow-boost && pkill -RTMIN+4 dwmblocks;;
esac

vol="$(pamixer --get-volume-human)"
echo -e "$vol"
