#!/bin/bash

Bat="$(cat /sys/class/power_supply/BAT0/capacity)" 
Sts="$(cat /sys/class/power_supply/BAT0/status)"
echo -e "$Bat% ($Sts)"
