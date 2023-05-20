#!/bin/bash

Bat="$(cat /sys/class/power_supply/BAT0/capacity)" 
echo -e "$Bat%"
