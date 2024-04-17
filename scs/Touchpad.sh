#!/bin/bash

Status=$(xinput list-props "SynPS/2 Synaptics TouchPad" | awk '/Device Enabled/{print $NF}')

if [ "$Status" == 1 ]; then
  dunstify "Touchpad off" -t 3000 -i "/home/justin/Pictures/sys/touchpad_off.jpeg"
  xinput disable "SynPS/2 Synaptics TouchPad"
else
  dunstify "Touchpad on" -t 3000 -i "/home/justin/Pictures/sys/touchpad_on.png"
  xinput enable "SynPS/2 Synaptics TouchPad"
fi
