#!/bin/bash

$(cat $HOME/scs/MyAppList.txt | dmenu -c  -p "App Launcher " -l 10 -g 1)
