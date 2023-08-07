#!/bin/bash

case $BUTTON in 
  1) alacritty -e yay ;;
  2) pkill --RTMIN+6 dwmblocks ;;
  3) alacritty --hold -e colorscript --exec pacman ;;
esac

upd="$(checkupdates | wc -l)"
echo -e "$upd/$(pacman -Q | wc -l)"
