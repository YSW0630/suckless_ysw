#!/bin/bash

case $BUTTON in 
  1) alacritty -e yay ;;
  2) alacritty --hold -e colorscript --exec pacman ;;
  3) pkill --RTMIN+6 dwmblocks ;;
esac

upd="$(checkupdates | wc -l)"
echo "$upd/$(pacman -Q | wc -l)"
