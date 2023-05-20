#!/bin/bash

WALLPAPER_DIR="$HOME/Pictures/wallpapers/"
file="$(find "$WALLPAPER_DIR" -type f -iname "*.jpg" | shuf -n1)"
feh --no-fehbg --bg-fill $file
