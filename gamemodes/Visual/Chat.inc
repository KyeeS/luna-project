native SendClientMessage_s(playerid, colour, AmxString:msg) = SendClientMessage;
native SetPlayerChatBubble_s(playerid, AmxString:text, colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;

stock SendPlayerChat(playerid, color, Float:radius, String:text)
{
	new
		Float:px,
		Float:py,
		Float:pz
	;
	GetPlayerPos(playerid, px, py, pz);
	foreach(new i : Player) if(IsPlayerSpawned(playerid)) {
		if(i == playerid) continue;
		if(IsPlayerInRangeOfPoint(i, radius, px, py, pz)) {
			SendClientMessage_s(i, color, text);
		}
	}	
	SendClientMessage_s(playerid, color, text);
	SetPlayerChatBubble_s(playerid, text, color, radius, 4000);
	return 0;
}


public OnPlayerText(playerid, text[])
{
	if(!IsPlayerSpawned(playerid) || !strlen(text)) return 0;
	SendPlayerChat(playerid, -1, 15.0, str_format("%S says: %s", str_replace(LunaPlayer[playerid][Name], "_", " "), text));
	return 0;
}