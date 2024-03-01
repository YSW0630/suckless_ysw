#!/bin/bash

case $BUTTON in 
  1) alacritty -e yay ;;
  2) alacritty --hold -e sh -c 'colorscript --exec pacman | pv -qL 2500 && yay' ;;
  3) pkill --RTMIN+6 dwmblocks ;;
esac

upd="$(checkupdates | wc -l)"
echo "$upd/$(pacman -Q | wc -l)"
