#!/bin/bash

disk=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)\n", $3, $2, $5}')
echo -e "$disk" 
