#! /bin/bash

####################################     MY CONFIG     #########################################

# wallpaper
feh --bg-scale ~/Downloads/dotfile/wallpapers/japanese1.png

# start picom
picom --experimental-backends &

# auto lock screen
xautolock -time 10 -locker slock &

Wifi(){
  Wifi="$(cat /sys/class/net/wlp9s0/operstate)"
  echo -e " $Wifi"
}

dte(){
  dte="$(date +"%A %B %d %I:%M %p")"
  echo -e " $dte"
}

upd(){
  upd=`checkupdates | wc -l`
  echo -e " $upd/$(pacman -Q | wc -l) updates"
}

Bat(){
  Bat="$(cat /sys/class/power_supply/BAT0/capacity)" 
  echo -e "󱐋$Bat"
}

mem(){
  mem=`free -m | awk '/Mem/ {printf"%d Mi/%d Gi\n", $3, $2 / 1024.0}'`
  echo -e "󰍛 $mem"
}


# Show my right status bar
while true; do
  xsetroot -name "$(Wifi) | $(mem) | $(Bat) | $(upd) | $(dte)"
  sleep 10s
done &

####################################     END CONFIG     ########################################
