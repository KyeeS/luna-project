CMD:info(playerid)
{
	ShowPlayerInfo(playerid);
	return 1;
}

CMD:ainfo(playerid, const params[])
{
	new 
		target
	;
	if(sscanf(params, "d", target)) 
		return NotifyShow(playerid, .message = "USAGE: /ainfo [playerid]");

	ShowPlayerInfo(target, playerid);
	return 1;
}