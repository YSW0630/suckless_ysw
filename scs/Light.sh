#!/bin/bash

case $BUTTON in 
  1) light -U 1 && pkill -RTMIN+5 dwmblocks ;;
  2) dunstify "$(fortune)" ;;
  3) light -A 1 && pkill -RTMIN+5 dwmblocks ;;
esac

light="$(xbacklight -get)%"
echo -e "$light"
