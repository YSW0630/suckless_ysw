#! /bin/bash

####################################     MY CONFIG     #########################################

# xrandr setting is delivered to autorandr

# start some tray
killall lxsession 
killall cbatticon
killall xpad
killall flameshot
killall pasystray
lxsession & # nm-applet, blueman-applet, picom, fcitx5, pasystray
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
feh --no-fehbg --bg-fill Pictures/mywall/pxfuel5.jpg
# $HOME/scs/Random_wallpaper.sh &
# feh --no-fehbg --bg-fill Pictures/mywall/pxfuel6.jpg
# feh --no-fehbg --bg-fill ~/Pictures/wallpapers/0213.jpg

# auto lock screen
xautolock -time 10 -locker slock &

# refresh volume
sleep 1 && pkill -RTMIN+4 dwmblocks &

####################################     END CONFIG     ########################################
