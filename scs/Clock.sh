#!/bin/bash

case $BUTTON in 
  1) dunstify "$(date)" ;;
  2) alacritty -e tty-clock -ctC6 ;;
  3) dunstify "$(cal)" ;;
esac

dte="$(date +"%Y %b %d (%a) [%I:%M:%S] %p")"
echo -e "$dte"
