#!/bin/bash

export VISUAL=vim
case $BUTTON in 
  1) alacritty -e calcurse ;;
  2) dunstify "$(cal)" ;;
  3) alacritty -e tty-clock -ctC6 ;;
esac

dte="$(date +"%Y %b %d (%a) [%I:%M:%S] %p")"
echo "$dte"
