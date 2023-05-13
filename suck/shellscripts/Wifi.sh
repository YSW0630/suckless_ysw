#!/bin/bash

Wifi="$(cat /sys/class/net/wlp9s0/operstate)"
echo -e "$Wifi"
