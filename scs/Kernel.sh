#!/bin/bash

case $BUTTON in 
  1) alacritty --hold -e neofetch ;;
  2) alacritty --hold -e curl wttr.in ;;
  3) alacritty --hold -e neofetch ;;
esac

kern="$(uname -r)"
echo -e "$kern"
