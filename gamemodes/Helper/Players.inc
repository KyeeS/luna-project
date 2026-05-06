#define SendClientError(%1,%2)			SendClientMessage(%1, -1, ""E_LUNA_RED_SUN"ERROR: "E_LUNA_WHITE""%2)
#define SendClientInfo(%1,%2)			SendClientMessage(%1, -1, ""E_LUNA_LIGHT_BLUE"INFO: "E_LUNA_WHITE""%2)
#define SendClientUsage(%1,%2)			SendClientMessage(%1, -1, ""E_LUNA_GRAY"USAGE: "E_LUNA_WHITE""%2)
#define SendClientCustom(%1,%2,%3)		SendClientMessage(%1, -1, ""E_LUNA_DUSTY_PEACH""%2": "E_LUNA_WHITE""%3)

#define RP_NAME_REGEX					"^(?=.{7,24}$)[A-Z][a-z]+_[A-Z][a-z]+$"

native GetPlayerName_s(playerid, AmxString:name, len) = GetPlayerName;
native SetPlayerName_s(playerid, AmxString:name) = SetPlayerName;

stock String:ReturnPlayerName(playerid)
{
	new String:name = str_new_buf(MAX_PLAYER_NAME);
	name = str_resize(name, GetPlayerName_s(playerid, name, MAX_PLAYER_NAME));
	return name;
}

stock String:ReturnPlayerNameFromDBID(dbid)
{
	foreach(new i : Player) if(LunaPlayer[i][ID] == dbid) {
		return ReturnPlayerName(i);
	}
	return STRING_NULL;
}

stock GetPlayerID(dbid)
{
	foreach(new i : Player) if(LunaPlayer[i][ID] == dbid) {
		return i;
	}
	return INVALID_PLAYER_ID;
}

stock IsRoleplayName(String:name)
{
	if(str_match(name, RP_NAME_REGEX)) {
		return 1;
	}
	return 0;
}

stock ShowGreetings(playerid)
{
	SendClientMessage_s(playerid, -1, str_format("> Hai, %S. Selamat datang kembali di server kami "E_LUNA_COL""SERVER_NAME"", LunaPlayer[playerid][Name]));
	SendClientMessage_s(playerid, -1, str_format("> Kamu terakhir login pada %S", ReturnLastLogin(playerid)));
	return 1;
}

stock String:ReturnLastLogin(playerid)
{
	if(LunaPlayer[playerid][LastLogin] == STRING_NULL)
	{
		await mysql_aquery_s(lunaSQL, str_format("SELECT LastLogin FROM characters WHERE ID = %d", LunaPlayer[playerid][ID]));
		if(cache_num_rows())
		{
			new
				ll[32]
			;
			cache_get_value_name(0, "LastLogin", ll, 32);
			return str_new(ll);
		}
		return STRING_NULL;
	}
	return LunaPlayer[playerid][LastLogin];
}

stock DelayedKick(playerid, const timer = 400)
{
	wait_ms(timer);
	Kick(playerid);
}

stock ShowServerIconForPlayer(playerid)
{
	for(new i ; i < 9; i ++) 
	{
		TextDrawShowForPlayer(playerid, LunaIcon[i]);
	}
	return 1;
}

stock ClearPlayerChat(playerid, lines = 75)
{
	for(new i; i < lines; i ++) {
		SendClientMessage(playerid, -1, " ");
	}
}


stock ShowPlayerInfo(target, extraid = INVALID_PLAYER_ID)
{
	new String:str = str_format(
		"======= In Character (IC) =======\n\
		Name: %S",
		LunaPlayer[target][Name]
	);

	if(!IsPlayerConnected(extraid) || extraid == INVALID_PLAYER_ID)
	{
		new res = await ShowAsyncListitemIndexDialog_s(target, DIALOG_STYLE_LIST, @("Player Information"), str, "Settings", "Close");
		if(res != -1)
		{
			SendClientInfo(target, "SOON!");
		}
	}
	else
	{
		ShowPlayerDialog_s(
			extraid,
			1,
			DIALOG_STYLE_LIST, 
			str_format("%S's Information", LunaPlayer[target][Name]),
			str,
			"Close",
			""
		);
	}
	return 1;
}
