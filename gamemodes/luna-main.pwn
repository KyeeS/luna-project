#define PP_SYNTAX
#define FOREACH_I_Vehicle 0
#define SAMP_COMPAT

#include <open.mp>
#include <a_mysql>
#include <sscanf2>
#include <foreach>
#include <streamer>	 
#include <PawnPlus>
#include <Pawn.CMD>
#include <pp-bcrypt>
#include <pp-mysql>
#include <tdialogs>
#include <terminal>
#include <chrono>
#include <humanize>

#define SERVER_NAME 	"Luna Project | Development"
#define SERVER_VERSION	"LN:Beta"
#define SERVER_LANG		"EN/ID"
#define SERVER_MAP		"San Andreas"

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#include "Helper/Debug"
#include "Core/Mysql"
#include "Core/Enum"
#include "Core/ORM"
#include "Core/Colour"

#include "Visual/TextDraw"
#include "Visual/Needs"
#include "Visual/Maps/Header"
#include "Visual/Chat"

#include "Helper/Players"
#include "Helper/Notification"
#include "System/Character"
#include "System/Login"
#include "System/Saving"
#include "Commands/Players"

#include "Core\Update"


main(){}

pawn_on_init[main]
{
	pp_public_min_index(0);
	TerminalTitle("lunaproject.dev");
}

public OnGameModeInit()
{
	TerminalCommand("cls");
	TerminalCommand("luna.bat");

	if(ConnectMysql() == MYSQL_INVALID_HANDLE || mysql_errno(lunaSQL) == 0)
	{
		LunaPrint("MySQL", @("Successfully connected to the database."));
		SendRconCommand("name %s", SERVER_NAME);
		SendRconCommand("language %s", SERVER_LANG);
		SendRconCommand("game.mode %s", SERVER_VERSION);
		SendRconCommand("game.map %s", SERVER_MAP);
	}
	else
	{
		LunaPrint("MySQL", @("An error occured while connecting to database #") % mysql_errno(lunaSQL), print_critical);
		LunaPrint("MySQL", str_new(ReturnMysqlError()), print_error, .debug_mode = true);
		LunaPrint("MySQL", @("Server will closed in 5 second(s"));
		wait_ms(5000);	
		SendRconCommand("exit");
	}

	LoadGlobalTextDraw();
	LoadMapBuilding();
	return 1;
}

public OnPlayerConnect(playerid)
{
	RemoveMapBuilding(playerid);
	LoadPlayerTextDraw(playerid);
	VerifyPlayerLogin(playerid);
	return 1;
}	

public OnPlayerSpawn(playerid)
{
	ShowServerIconForPlayer(playerid);
	TogglePlayerHBE(playerid, true);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	SavePlayerData(playerid);
	ClearPlayerData(playerid);
	return 1;
}


forward OnPlayerDataLoaded(playerid);
public OnPlayerDataLoaded(playerid)
{
    ClearPlayerChat(playerid);
    NotifyShow(playerid, .message = "Successfully load your character.");
    SetPlayerName_s(playerid, LunaPlayer[playerid][Name]);
    SetPlayerColor(playerid, -1);
	SetPlayerScore(playerid, LunaPlayer[playerid][Level]);
    SetSpawnInfo(
        playerid, NO_TEAM, 
        LunaPlayer[playerid][Skin], 
        LunaPlayer[playerid][PX], LunaPlayer[playerid][PY],
		LunaPlayer[playerid][PZ], LunaPlayer[playerid][PA]	
    );

	ShowGreetings(playerid);
	TogglePlayerHBE(playerid, true);
    SpawnPlayer(playerid);
}


// misc 

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	return 1;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
	LunaPrint("OnQueryError", str_format("(Callback: %s): %s", callback, error), print_error, .debug_mode = true);
	return 1;
}

public pp_on_error(source[], message[], error_level:level, &retval)
{
	LunaPrint(source, str_new(message), PrintLevel:level);
	return 1;
}

CMD:go(playerid, const params[])
{
	new
		Float:x,
		Float:y,
		Float:z
	;
	sscanf(params, "fff", x,y,z);
	SetPlayerPos(playerid, x,y,z);
	return 1;
}