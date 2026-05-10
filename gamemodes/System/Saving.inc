stock SavePlayerData(playerid)
{
    if(IsPlayerSpawned(playerid))
    {
        new
            Float:x, Float:y, Float:z,
            Float:a
        ;
        GetPlayerPos(playerid, x,y,z);
        GetPlayerFacingAngle(playerid, a);

        LunaPlayer[playerid][PX] = x;
        LunaPlayer[playerid][PY] = y;
        LunaPlayer[playerid][PZ] = z;
        LunaPlayer[playerid][PA] = a;
        orm_save(LunaPlayer[playerid][PlayerORM], "OnSavePlayerData", "d", playerid);
        orm_destroy(LunaPlayer[playerid][PlayerORM]);
    }
    return 1;
}

stock ClearPlayerData(playerid)
{
    if(str_valid(LunaPlayer[playerid][UCP]) && str_valid(LunaPlayer[playerid][Name]) && str_valid(LunaPlayer[playerid][Password]))
    {
        str_release(LunaPlayer[playerid][UCP]);
        str_release(LunaPlayer[playerid][Name]);
        str_release(LunaPlayer[playerid][Password]);
    }
    static const empty[e_PLAYER_DATA];
    LunaPlayer[playerid] = empty;
    LunaPrint("ClearPlayerData", 
        str_format("%S, data has been cleared properly ", ReturnPlayerName(playerid)),
        .debug_mode = true
    );
    return 1;
}


forward OnSavePlayerData(playerid);
public OnSavePlayerData(playerid)
{
    LunaPrint("OnSavePlayerData", str_format("%S, data has been updated properly", ReturnPlayerName(playerid)), .debug_mode = true);
    return 1;
}