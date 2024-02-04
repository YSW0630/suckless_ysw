#!/bin/bash

Status="$(dunstctl is-paused)"

if [ "$Status" == "true" ]; then # notify stop, expect: turn on
  dunstctl set-paused toggle
  dunstify "Notification on" -i "/home/justin/Pictures/Distrub.png"
  sleep 3s
else # now: notify running, expect: close 
  dunstify "Notification off" -i "/home/justin/Pictures/noDistrub.png"
  sleep 3s
  dunstctl set-paused toggle
  dunstctl close-all
fi

