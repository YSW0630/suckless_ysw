#!/bin/bash

vol="$(pamixer --get-volume-human)"
echo -e "$vol"
