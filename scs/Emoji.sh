dmenu-emoji | dmenu -i -l 10 | awk '{print $1}' | tr -d '\n' | xclip -selection clipboard
