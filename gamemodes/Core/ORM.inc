stock ORM:LoadPlayerORM(playerid, bool:load = true)
{
	new ORM:orm = orm_create("characters", lunaSQL);
	orm_addvar_int(orm, LunaPlayer[playerid][ID], "ID");
	orm_addvar_int(orm, LunaPlayer[playerid][Cash], "Cash");
	orm_addvar_int(orm, LunaPlayer[playerid][Level], "Level");
	orm_addvar_int(orm, _:LunaPlayer[playerid][TimePlayed], "TimePlayed");
	orm_addvar_int(orm, LunaPlayer[playerid][LevelPoint], "LevelPoint");
	orm_addvar_int(orm, LunaPlayer[playerid][BankMoney], "BankMoney");
	orm_addvar_int(orm, LunaPlayer[playerid][Skin], "Skin");
	orm_addvar_float(orm, LunaPlayer[playerid][PX], "PX");
	orm_addvar_float(orm, LunaPlayer[playerid][PY], "PY");
	orm_addvar_float(orm, LunaPlayer[playerid][PZ], "PZ");
	orm_addvar_float(orm, LunaPlayer[playerid][PA], "PA");
    orm_setkey(orm, "ID");

    if(load) orm_load(orm, "OnPlayerDataLoaded", "d", playerid);
	return orm;
}
