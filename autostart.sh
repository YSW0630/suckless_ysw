#! /bin/bash

####################################     MY CONFIG     #########################################

# auto adjust xrandr
xrandr --auto
# xrandr --output eDP-1 --mode 1920x1080 --pos 2560x0 --rotate normal --output HDMI-1 --primary --mode 2560x1440 --pos 0x0 --rotate normal --output DP-1 --off --output DP-2 --off --output DP-3 --off --output DP-4 --off
# xrandr --output HDMI-1 --same-as eDP-1

# start some tray
# killall lxsession 
killall cbatticon
killall xpad
killall flameshot
# lxsession & # nm-applet, blueman-applet, picom, fcitx5
cbatticon -n &
xpad -N &
flameshot &
# udiskie &
# volumeicon &
# my-weather-indicator &

# start unclutter
killall unclutter
unclutter &

# start dunst 
killall dunst
dunst &

# start dwmblocks
killall dwmblocks
dwmblocks &

# start pcmanfm daemon
killall pcmanfm
pcmanfm -d &

# wallpaper
feh --no-fehbg --bg-fill ~/Pictures/wallpapers/0213.jpg
# $HOME/scs/Random_wallpaper.sh &
# feh --no-fehbg --bg-fill Pictures/mywall/pxfuel6.jpg
# feh --no-fehbg --bg-fill Pictures/mywall/pxfuel5.jpg

# auto lock screen
xautolock -time 10 -locker slock &

####################################     END CONFIG     ########################################
