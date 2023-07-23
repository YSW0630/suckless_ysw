#!/bin/bash

if grep -q '^\s*w' /proc/net/wireless; then
    Wifi=$(awk '/^\s*w/ { print int($3 * 100 / 70) "%" }' /proc/net/wireless)
else
    Wifi="down"
fi

echo -e "$Wifi"
