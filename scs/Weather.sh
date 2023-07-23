#!/bin/bash

wth=$(curl -s 'wttr.in/?format=1' | sed 's/.* //')
echo -e "$wth"
