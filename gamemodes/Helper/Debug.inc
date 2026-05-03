/*
* Luna Project (c) 2026
* Developed by kyomoto
* Module: Debug.inc
* Purpose: A debugging system for Luna Project
*/

enum PrintLevel {
    print_info = 0,
    print_warning = 1,
    print_error = 2,
    print_critical = 3,
    print_none = cellmax
};

static const arr_LevelStr[][35] = {
	"Info.", "Warn.",
	"Err.", "Crit.",
	"None."
};

stock LunaPrint(const source[] = "None", String:msg, 
	PrintLevel:level = print_info, bool:debug_mode =false) 
{
	new String:fmt = str_format(
		"%s%sLuna --> %s:",
		debug_mode ? "Dbg." : "",
		arr_LevelStr[_:level], 
		source
	);
	print_s(fmt + msg);
	return;
}