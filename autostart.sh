#! /bin/bash

####################################     MY CONFIG     #########################################

# auto adjust xrandr
xrandr --auto
# xrandr --output eDP-1 --mode 1920x1080 --pos 2560x0 --rotate normal --output HDMI-1 --primary --mode 2560x1440 --pos 0x0 --rotate normal --output DP-1 --off --output DP-2 --off --output DP-3 --off --output DP-4 --off

# set cursor size
# xsetroot -xcf /usr/share/icons/Adwaita/cursors/left_ptr 1

# confirm dbus enable
eval "$(dbus-launch --sh-syntax --exit-with-session)" &

# mpd start
mpd ~/.config/mpd/mpd.conf

# Start fcitx5
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
killall fcitx5
fcitx5 &

#start dwmblocks
dwmblocks &

# wallpaper
feh --bg-scale ~/Pictures/astronaut.jpg

# start picom
picom --experimental-backends &

# auto lock screen
xautolock -time 10 -locker slock &

# Wifi(){
#   Wifi="$(cat /sys/class/net/wlp9s0/operstate)"
#   echo -e "  $Wifi"
# }

# vol(){
#   vol="$(amixer get Master | awk -F'[][]' 'END{ print $2 }')"
#   echo -e " $vol"
# }

# light(){
#   light="$(xbacklight -get)"
#   echo -e "󰛨 $light%"
# }

# dte(){
#   dte="$(date +"%A %B %d [%I:%M] %p")"
#   echo -e " $dte"
# }

# upd(){
#   upd="$(checkupdates | wc -l)"
#   echo -e " $upd/$(pacman -Q | wc -l) updates"
# }

# Bat(){
#   Bat="$(cat /sys/class/power_supply/BAT0/capacity)" 
#   echo -e "󰠠 $Bat%"
# }

# mem(){
#   mem=$(free -m | awk '/Mem/ {printf"%d Mi/%d Gi\n", $3, $2 / 1024.0}')
#   echo -e "󰍛 $mem"
# }


# Show my right status bar
# while true; do
#   xsetroot -name "$(Wifi) | $(vol) | $(light) | $(Bat) | $(mem) | $(upd) | $(dte)"
#   sleep 5s
# done &

####################################     END CONFIG     ########################################
