#!/bin/bash

$(cat $HOME/scs/MyAppList.txt | dmenu -c  -p "App Launch" -l 10 -g 1)
