native orm_addvar_string_s(ORM:ormid, AmxString:var, var_maxlen, const columnname[]) = orm_addvar_string;

new MySQL:lunaSQL = MYSQL_INVALID_HANDLE;


stock ReturnMysqlError()
{
	new error[128];
	mysql_error(error);
	return error;
}

stock MySQL:ConnectMysql() 
{
	lunaSQL = mysql_connect_file();
	return lunaSQL;
}

