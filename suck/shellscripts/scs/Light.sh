#!/bin/bash

light="$(xbacklight -get)"
echo -e "$light%"
