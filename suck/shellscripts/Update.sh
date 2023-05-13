#!/bin/bash

upd="$(checkupdates | wc -l)"
echo -e "$upd/$(pacman -Q | wc -l) updates"
