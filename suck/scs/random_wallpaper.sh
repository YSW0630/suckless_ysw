#!/bin/bash

WALLPAPER_DIR="$HOME/Pictures/wallpapers/"
while true; do
  file="$(find "$WALLPAPER_DIR" -type f -iname "*.jpg" | shuf -n1)"
  feh --no-fehbg --bg-fill $file
  sleep 600
done
