#!/bin/bash

case $BUTTON in 
  1) light -U 10 && pkill -RTMIN+5 dwmblocks ;;
  2) alacritty --hold -e curl wttr.in ;;
  3) light -A 10 && pkill -RTMIN+5 dwmblocks ;;
esac

light="$(xbacklight -get)%"
echo "$light"
