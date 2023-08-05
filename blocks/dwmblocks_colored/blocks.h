// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"^c#5A99F7^   ", "$HOME/scs/Kernel.sh", 0, 9},
    // {  ",  "$HOME/scs/Wifi.sh",      5,	  	6},
    // {󰈀  ",  "$HOME/scs/Ethernet.sh",  5,	  	6},
    {"^c#98c379^   ", "$HOME/scs/Volume.sh", 0, 10},
    {"^c#E8B94D^ 󰛨  ", "$HOME/scs/Light.sh", 0, 10},
    {"^c#F24F4F^   ", "$HOME/scs/Update.sh", 1800, 9},
    // {󰠠  ", "$HOME/scs/Battery.sh",    10,  	4},
    {"^c#DDADF6^ 󰍛  ", "$HOME/scs/Memory.sh", 5, 1},
    {"^c#98c379^ 󰋊  ", "$HOME/scs/Disk.sh", 0, 9},
    {"^c#5A99F7^   ", "$HOME/scs/Clock.sh", 1, 2},
};

// sets delimeter between status commands. NULL character ('\0') means no
// delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
