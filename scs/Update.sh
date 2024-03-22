#!/bin/bash

case $BUTTON in 
  1) alacritty -e sh -c 'colorscript --exec pacman && yay' ;;
  2) alacritty -e asciiquarium ;;
  3) pkill --RTMIN+6 dwmblocks ;;
esac

upd="$(checkupdates | wc -l)"
echo "$upd/$(pacman -Q | wc -l)"
