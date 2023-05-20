#!/bin/bash

vol="$(amixer get Master | awk -F'[][]' 'END{ print $2 }')"
echo -e "$vol"
