#!/bin/bash

case $BUTTON in 
  1) alacritty --hold -e neofetch ;;
  2) surf term.ptt.cc ;;
  3) kitty -e cmatrix -C blue;;
esac

kern="$(uname -r)"
echo "$kern"
