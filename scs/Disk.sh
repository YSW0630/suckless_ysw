#!/bin/bash

case $BUTTON in 
  1) alacritty -e ncdu ;;
  2) pkill -RTMIN+9 dwmblocks ;;
  3) alacritty -e yay -Sc && pkill -RTMIN+9 dwmblocks;;
esac

disk=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)\n", $3, $2, $5}')
echo -e $disk 
