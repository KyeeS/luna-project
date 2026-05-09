enum E_PLAYER_HBE
{
	PLAYER_HUNGER,
	PLAYER_THIRSTY
};

stock TogglePlayerHBE(playerid, bool:toggle)
{
	UpdatePlayerHBE(playerid);
	if(!toggle) {
		for(new i; i < 22; i++) {
			PlayerTextDrawHide(playerid, LunaHBE[playerid][i]);
		}
	} else {
		for(new i ; i < 22; i++) {
			PlayerTextDrawShow(playerid, LunaHBE[playerid][i]);
		}
	}
}
stock UpdatePlayerHBE(playerid)
{
    new Float:hunger = LunaPlayer[playerid][Hunger];
    new Float:thirsty = LunaPlayer[playerid][Thirsty];

    if(hunger > 100.0) hunger = 100.0;
    if(hunger < 0.0) hunger = 0.0;
    if(thirsty > 100.0) thirsty = 100.0;
    if(thirsty < 0.0) thirsty = 0.0;

    new 
    	full_h = floatround(hunger / 20.0, floatround_floor),
    	full_t = floatround(thirsty / 20.0, floatround_floor),
    	Float:rem_h = hunger - (full_h * 20.0),
    	Float:rem_t = thirsty - (full_t * 20.0)
    ;

    for(new i = 0; i < 5; i++)
    {
        new idx = 10 + i;
        if(i < full_h) {
            PlayerTextDrawTextSize(playerid, LunaHBE[playerid][idx], 11.0, -6.0);
            PlayerTextDrawShow(playerid, LunaHBE[playerid][idx]);
        }
        else if(i == full_h)
        {
            if(rem_h > 0.0)
            {
                new Float:h = (rem_h / 20.0) * 6.0;
                PlayerTextDrawTextSize(playerid, LunaHBE[playerid][idx], 11.0, -h);
                PlayerTextDrawShow(playerid, LunaHBE[playerid][idx]);
            }
            else PlayerTextDrawHide(playerid, LunaHBE[playerid][idx]);
        }
        else 
        {
            PlayerTextDrawHide(playerid, LunaHBE[playerid][idx]);
        }
    }

    for(new i = 0; i < 5; i++)
    {
        new idx = 15 + i;
        if(i < full_t)
        {
            PlayerTextDrawTextSize(playerid, LunaHBE[playerid][idx], 11.0, -6.0);
            PlayerTextDrawShow(playerid, LunaHBE[playerid][idx]);
        }
        else if(i == full_t)
        {
            if(rem_t > 0.0)
            {
                new Float:h = (rem_t / 20.0) * 6.0;
                PlayerTextDrawTextSize(playerid, LunaHBE[playerid][idx], 11.0, -h);
                PlayerTextDrawShow(playerid, LunaHBE[playerid][idx]);
            }
            else PlayerTextDrawHide(playerid, LunaHBE[playerid][idx]);
        }
        else 
        {
            PlayerTextDrawHide(playerid, LunaHBE[playerid][idx]);
        }
    }
    return 1;
}

stock SetPlayerHBE(playerid, Float:value, E_PLAYER_HBE:type)
{
    if(value < 0.0) value = 0.0;
    if(value > 100.0) value = 100.0;

    if(type == PLAYER_HUNGER) LunaPlayer[playerid][Hunger] = value;
    else if(type == PLAYER_THIRSTY) LunaPlayer[playerid][Thirsty] = value;
    
    UpdatePlayerHBE(playerid);
    return 1;
}