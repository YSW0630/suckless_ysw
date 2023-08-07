#!/bin/bash

case $BUTTON in 
  1) alacritty -e htop ;;
  2) alacritty -e vtop ;;
  3) alacritty -e btop ;;
esac

mem=$(free -m | awk '/Mem/ {printf"%d Mi/%d Gi\n", $3, $2 / 1024.0}')
echo -e "$mem"
