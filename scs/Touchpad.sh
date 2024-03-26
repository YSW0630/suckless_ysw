#!/bin/bash

Status="$(xinput list-props 10 | awk '/Device Enabled/{print $NF}')"

if [ "$Status" == "1" ]; then
  dunstify "Touchpad off" -i "/home/justin/Pictures/touchpad_off.jpeg"
  xinput disable 10
else
  dunstify "Touchpad on" -i "/home/justin/Pictures/touchpad_on.png"
  xinput enable 10
fi
