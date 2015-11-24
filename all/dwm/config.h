/* 
 * ==================================================================
 * FILE     config.h (for dwm-6.1)
 * MACHINE  all
 * INFO     default terminal is suckless st
 *
 * DATE     24.11.2015
 * OWNER    Bischofberger
 * ==================================================================
 */


/* appearance */
static const char *fonts[] = {
    "Sans:size=10.5",
};
static const char dmenufont[]       = "monospace:size=10";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#ff6565";
static const char selbgcolor[]      = "#ff6565";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging */
static const char *tags[] = { "1:dev", "2:web", "3:mail", "4:doc", "5:dtp", "6:gui", "7:virt", "8:spare" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	/* class                     instance    title             tags mask     isfloating   monitor */
	{ "chromium",                NULL,       NULL,             1 << 1,       False,       -1 },
	{ "Firefox",                 NULL,       NULL,             1 << 1,       False,       -1 },
	{ NULL,                      NULL,       "mail",           1 << 2,       False,       -1 },
	{ NULL,                      NULL,       "LibreOffice",    1 << 3,       False,       -1 },
	{ "tabbed",                  NULL,       NULL,             1 << 3,       False,       -1 },  /* zathuratab */
	{ NULL,                      NULL,       "Drucken",        1 << 3,       True,        -1 },  /* von Zathura */
	{ "Evince",                  NULL,       NULL,             1 << 3,       False,       -1 },
	{ "Gimp",                    NULL,       NULL,             1 << 4,       True,        -1 },
	{ "Inkscape",                NULL,       NULL,             1 << 4,       True,        -1 },
	{ "Scribus",                 NULL,       NULL,             1 << 4,       True,        -1 },
	{ "Gnome-mplayer",           NULL,       NULL,             1 << 5,       True,        -1 },
	{ "Deadbeef",                NULL,       NULL,             1 << 5,       True,        -1 },
	{ "Galculator",              NULL,       NULL,             1 << 5,       True,        -1 },
	{ NULL,                      NULL,       "HandBrake",      1 << 5,       True,        -1 },
	{ "Easytag",                 NULL,       NULL,             1 << 5,       True,        -1 },
	{ "Truecrypt",               NULL,       NULL,             1 << 5,       True,        -1 },
	{ "VirtualBox",              NULL,       NULL,             1 << 6,       True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.75;  /* laptop screen */
//static const float mfact      = 0.65;  /* desktop screen */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *snippycmd[] = { "snippy", NULL };
//static const char *termcmd[]    = { "st", "-e", "tmux", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,                       XK_s,      spawn,          {.v = snippycmd } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button3,        view,           {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

