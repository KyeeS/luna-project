#include "Visual/Maps/Maps_RegSpawn"

stock RemoveMapBuilding(playerid)
{
	RemoveBuilding_RegSpawn(playerid);
	return 1;
}

stock LoadMapBuilding()
{
	LoadBuilding_RegSpawn();
	return 1;
}