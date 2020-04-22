/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 18;       /* gap pixel between windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "FontAwesome:size=10", "Terminus:size=14" };
static const char dmenufont[]       = "Terminus:size=10";
static const unsigned int baralpha = 255;
static const unsigned int borderalpha = 255;

#include "/home/cjg/.cache/wal/colors-wal-dwm.h.nice"

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 5,       0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "thunderbird", NULL,	  NULL,	      1 << 4,	    0,		 -1 },
	{ "smtube",   NULL,	  NULL,	      1 << 8,	    0,		 -1 },
	{ "Thunar",   NULL,	  NULL,	      1 << 2,	    0,		 -1 },
	{ "Hexchat",  NULL,	  NULL,	      1 << 6,	    0,		 -1 },
	{ "Telegram",   NULL,	  NULL,	      1 << 7,	    0,		 -1 },
	{ "Code - OSS", NULL,	  NULL,	      1 << 4,	    0,		 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browser[] = { "firefox", NULL};
static const char *xmixer[] = { "xmixer", NULL };
static const char *hexchat[] = { "hexchat", NULL };
static const char *files[] = { "thunar", NULL };
static const char *upvol[]   = { "mixer", "vol", "+3",     NULL };
static const char *downvol[] = { "mixer", "vol", "-3",     NULL };
static const char *mutevol[] = { "mixer", "vol", "toggle", NULL };
static const char *gimp[] = { "gimp", NULL };
static const char *menucmd[]   = { "9menu", "-teleport", "-popup", "-iconic", "-fg", "7E7159", "-bg", "#202020", "-font", "-b&h-lucidatypewriter-medium-r-normal-sans-12-*-*-*-*-*-*-*", "-file",  "/home/cjg/.9menu", NULL };
static const char *scrot[] = { "scrot", "/home/cjg/pictures/scrot.png", NULL };
static const char *vbox[] = { "doas", "VirtualBox", NULL };
static const char *email[] = { "thunderbird", NULL };
static const char *mpcnxt[] = { "mpc", "-h", "192.168.2.30", "next", NULL};
static const char *mpctgl[] = { "mpc", "-h", "192.168.2.30", "toggle", NULL};
static const char *mpcprv[] = { "mpc", "-h", "192.168.2.30", "prev", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,			XK_s,	   spawn, 	   {.v = browser } },
	{ MODKEY,			XK_e,	   spawn,	   {.v = email } },
	{ MODKEY,			XK_g,	   spawn,	   {.v = gimp } },
	{ MODKEY,			XK_v,	   spawn,	   {.v = vbox } },
	{ MODKEY,			XK_x,	   spawn,	   {.v = hexchat } },
	{ MODKEY,			XK_f,	   spawn,	   {.v = files } },
	{ MODKEY|ShiftMask,		XK_s,	   spawn,	   {.v = scrot } },
	{ MODKEY,			XK_F9,	   spawn,	   {.v = mpcnxt } },
	{ MODKEY,			XK_F8,	   spawn,	   {.v = mpctgl } },
	{ MODKEY,			XK_F7,	   spawn,	   {.v = mpcprv } },
	{ MODKEY,	                XK_F12,    spawn,          {.v = upvol   } },
	{ MODKEY,          	        XK_F11,    spawn,          {.v = downvol } },
	{ MODKEY,	                XK_F10,    spawn,          {.v = mutevol } },
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
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },
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
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = xmixer } },
	{ ClkRootWin,		0,		Button3,	spawn,		{.v = menucmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

