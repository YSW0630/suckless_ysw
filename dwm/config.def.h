/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 4;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
#define ICONSIZE bh   /* icon size */
#define ICONSPACING bh-4 /* space between icon and title */
static const char *fonts[]          = { "FantasqueSansMono Nerd Font:size=11" };
static const char dmenufont[]       = "FantasqueSansMono Nerd Font:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* My Color Scheme */                           
static const char col_dark_purple[]	  = "#282a36";
static const char col_dark_purple2[]  = "#50535c";
static const char col_light_purple[]  = "#7E00D5";
static const char col_dracula[]       = "#6272a4";
static const char col_light_blue[]    = "#5A6EFF";  

static const char *colors[][3] = {
  /*            	 fg(font)  bg(behind test)  border   */    
  [SchemeNorm]  = { col_gray3, col_dark_purple, col_gray2 },  
  [SchemeSel]   = { col_gray4, col_dracula, col_dracula },
  [SchemeTitle] = { col_light_blue, col_dark_purple, col_cyan },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};
// static const char *tags[] = { "", "", "", "", "󰇮", "", ""};
// static const char *tags[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱"};
// static const char *tags[] = { "Home", "Web", "Code", "Pcman", "Vbox", "Misc"};

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 1;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class                instance   title        tags mask  isfloating  isterminal  noswallow  monitor */         
  { "st-256color",         NULL,     NULL,           0,         0,          1,           0,        -1 },           
  { "Alacritty",           NULL,     NULL,           0,         0,          1,           0,        -1 },           
  { "kitty",               NULL,     NULL,           0,         0,          1,           0,        -1 },           
  { "xpad",                NULL,     NULL,           0,         1,          0,           1,        -1 },           
  //{ "Google-chrome",       NULL,     NULL,           1 << 1,    0,          0,           1,        -1 },           
  //{ "code-oss",            NULL,     NULL,           1 << 2,    0,          0,           1,        -1 },           
  //{ "Pcmanfm",             NULL,     NULL,           1 << 3,    1,          0,           1,        -1 },           
  //{ "VirtualBox",          NULL,     NULL,           1 << 4,    0,          0,           1,        -1 },           
  //{ "discord",             NULL,     NULL,           1 << 5,    0,          0,           1,        -1 },           
  //{ "obs",                 NULL,     NULL,           1 << 5,    0,          0,           1,        -1 },           
  { NULL,                  NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */ 
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-p", "Launch 󱓞 ", NULL };                                                                                                  
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_light_blue, "-sf", col_gray4, NULL }; 
static const char *termcmd[]  = { "alacritty", NULL };                                                                                                                  
static const char *volup[] = { "pamixer", "-ui", "2", "--allow-boost", NULL };                                                                                                
static const char *voldown[] = { "pamixer", "-ud", "2", "--allow-boost", NULL };                                                                                              
static const char *mute_vol[] = { "pamixer", "-t", NULL };                                                                                          
static const char *mute_mic[] = { "amixer", "set", "Capture", "toggle", NULL };                                                                                         
static const char *lightup[] = { "light", "-A", "2", NULL };                                                                                                     
static const char *lightdown[] = { "light", "-U", "2", NULL };                                                                                                   
static const char *lockcmd[] = { "slock", NULL};                                                                                                                        
static const char *PrtSc[] = { "flameshot", "gui", NULL};                                                                                                               
static const char *emoji[] = { "bemoji", "-P", "10",  NULL};                                                                                                                    
static const char *browser[] = { "google-chrome-stable", NULL};                                                                                                          
static const char *Kill4[] = { "pkill", "-RTMIN+4", "dwmblocks", NULL};                                                                                                  
static const char *Kill5[] = { "pkill", "-RTMIN+5", "dwmblocks", NULL};                                                                                                  
static const char *change_bg[] = { "/home/justin/scs/Change_bg.sh", NULL};                                                                                               
static const char *toggle_notification[] = { "/home/justin/scs/Notify.sh", NULL};                                                                                               
static const char *toggle_touchpad[] = { "/home/justin/scs/Touchpad.sh", NULL};                                                                                               
static const char *AppLaunch[] = { "/home/justin/scs/AppLauncher.sh", NULL};
static const char *Xpad[] = { "xpad", "-n", NULL};                                                                                               
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *ytfzfcmd[] = {"ytfzf", "-D", NULL};

#include "shiftview.c"     
#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,              XF86XK_MonBrightnessUp,  spawn,          {.v = lightup} },
	{ 0,              XF86XK_MonBrightnessDown,spawn,          {.v = lightdown} },
  { 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = volup} },
  { 0,              XF86XK_AudioLowerVolume, spawn,          {.v = voldown} },
  { 0,              XF86XK_MonBrightnessUp,  spawn,          {.v = Kill5} },
	{ 0,              XF86XK_MonBrightnessDown,spawn,          {.v = Kill5} },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = Kill4} },
	{ 0,              XF86XK_AudioLowerVolume, spawn,          {.v = Kill4} },
	{ 0,              XF86XK_AudioMute,        spawn,          {.v = Kill4} },
  { 0,              XF86XK_AudioMute,        spawn,          {.v = mute_vol} },
  { 0,              XF86XK_AudioMicMute,     spawn,          {.v = mute_mic} },
  { 0,                            XK_Print,  spawn,          {.v = PrtSc} },
	{ MODKEY|ShiftMask,      	    	XK_e,      spawn,          {.v = emoji } },
  { MODKEY|ShiftMask,      	    	XK_d,      spawn,          {.v = toggle_notification } },
  { MODKEY|ShiftMask,      	    	XK_t,      spawn,          {.v = toggle_touchpad } },
	{ MODKEY|ShiftMask,			   			XK_y,	     spawn,          {.v = ytfzfcmd} },
  { MODKEY|ShiftMask,      	    	XK_w,      spawn,          {.v = change_bg } },
  { MODKEY|ShiftMask,      	    	XK_p,      spawn,          {.v = Xpad } },
	{ MODKEY|ShiftMask,             XK_Delete, quit,           {1} }, 
  { MODKEY|ShiftMask,             XK_o,      rotatestack,    {.i = -1 } },
  { MODKEY,                       XK_o,      rotatestack,    {.i = +1 } },
  { MODKEY,                       XK_Escape, spawn,          {.v = lockcmd} },
  { MODKEY,                       XK_w,      spawn,          {.v = browser} },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                	    	XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                	    	XK_a,		 	 spawn,          {.v = AppLaunch } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,  	             		    XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,          	    		    XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                 			XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,          			   			XK_y,	     setlayout,      {0} },
	{ MODKEY, 			              	XK_g, 	   togglefloating, {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
  { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
  { MODKEY,                       XK_p,      shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,			  		  XK_q, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
