#!/bin/bash
if grep -q '^\s*w' /proc/net/wireless; then
    Wifi=$(awk '/^\s*w/ { print int($3 * 100 / 70) "%" }' /proc/net/wireless)
else
    Wifi="down"
fi

echo -e "$Wifi"
# Wifi=$(awk '/^\s*w/ { print int($3 * 100 / 70) "%" }' /proc/net/wireless)
# echo -e "$Wifi"

# Show wifi 📶 and percent strength or 📡 if none.
# Show 🌐 if connected to ethernet or ❎ if none.

# if grep -xq 'up' /sys/class/net/w*/operstate 2>/dev/null ; then
	# wifiicon="$(awk '/^\s*w/ { print "📶", int($3 * 100 / 70) "% " }' /proc/net/wireless)"
# elif grep -xq 'down' /sys/class/net/w*/operstate 2>/dev/null ; then
	# grep -xq '0x1003' /sys/class/net/w*/flags && wifiicon="📡 " || wifiicon="❌ "
# fi

# printf "%s%s%s\n" "$wifiicon" "$(sed "s/down/❎/;s/up/🌐/" /sys/class/net/e*/operstate 2>/dev/null)"
