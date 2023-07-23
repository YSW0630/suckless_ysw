#!/bin/bash

ether=$(cat /sys/class/net/e*/operstate)
echo -e "$ether"
