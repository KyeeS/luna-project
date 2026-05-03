
// terminal
native TerminalCommand(const cmd[], ...);
native TerminalTitle(const title[]);
native print_t(const string[], ...);

// r, g, b

#define SC_Foreground(%0) SColorASII(%0)
#define TERMINAL_FORE 38
#define TERMINAL_BACK 48

stock ColorASII(a, const r = 0, const g = 0, const b = 0, bool:dynamic_str = true)
{
	new 
		gsasii[25],
		String:str = STRING_NULL
	;
	format(gsasii, 25, "\x1b[%d;2;%d;%d;%dm", a, r, g, b);
	if(dynamic_str) {
		str = str_new(gsasii);
	}

	return (dynamic_str) ? str : gsasii;
}
