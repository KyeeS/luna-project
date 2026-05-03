/*
* Luna Project (c) 2026
* Developed by kyomoto
* Module: Update.inc
* Purpose: A custom update system (per-playeri, vehicle, etc) for Luna Project
*/

forward OnServerUpdate();
forward OnPerPlayerUpdate(playerid);

public OnPerPlayerUpdate(playerid)
{
    LunaPlayer[playerid][TimePlayed] = Now();
    return 1;
}

