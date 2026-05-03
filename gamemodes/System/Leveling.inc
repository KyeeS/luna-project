#define BASE_LEVELUP_POINT        100

stock GetNeededEXP(playerid)
{
    new
        n = BASE_LEVELUP_POINT * (LunaPlayer[playerid][Level] + 1) 
    ;

    return n;
}

stock SetPlayerLevel(playerid, level)
{
    if(level <= 0)
        return 0;
    
    LunaPlayer[playerid][Level] = level;
    LunaPlayer[playerid][LevelPoint] = BASE_LEVELUP_POINT * LunaPlayer[playerid][Level];
    SetPlayerScore(playerid, LunaPlayer[playerid][Level]);
    return 1;
}

stock AddPlayerLevelPoint(playerid, point)
{
    new 
        needed = GetNeededEXP(playerid),
        old = LunaPlayer[playerid][LevelPoint]
    ;
    LunaPlayer[playerid][LevelEXP] += point;
    while(LunaPlayer[playerid][LevelPoint] >= needed)
    {
        new old_l = LunaPlayer[playerid][Level];
        LunaPlayer[playerid][Level]++;
        SetPlayerScore(playerid, LunaPlayer[playerid][Level]);
        needed = GetNeededEXP(playerid);
    }
    return 1;
}