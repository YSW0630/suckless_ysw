//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"   ", "$HOME/scs/Kernel.sh",    0,  	  9},
  {"  ",  "$HOME/scs/Wifi.sh",      5,	  	6},
  {"󰈀  ",  "$HOME/scs/Ethernet.sh",  5,	  	6},
	{"  ", "$HOME/scs/Volume.sh",     0,   	10},
	{"󰛨  ", "$HOME/scs/Light.sh",      0,   	10},
	{"  ", "$HOME/scs/Update.sh",     3600,  9},
  {"󰠠  ", "$HOME/scs/Battery.sh",    60,  	4},
	{"󰍛  ", "$HOME/scs/Memory.sh",     5,   	1},
	{"󰋊  ", "$HOME/scs/Disk.sh",       0,   	9},
	{"  ", "$HOME/scs/Clock.sh",      1,   	2},
  // {"", "$HOME/scs/Weather.sh",       3600,  3},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
