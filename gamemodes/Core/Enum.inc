#define MAX_UCP_NAME				32

enum e_PLAYER_DATA
{
	ID,
	Skin,
	String:RegisterAt, // timestamp format: yyyy-mm-dd hh:mm:ss
	String:LastLogin, // sama seperti 'RegisterAt'
	Timestamp:TimePlayed,
	BirthDay,
	BirthMonth,
	BirthYear,
	Sex,
	Level,
	LevelPoint,
	Cash,
	BankAccount,
	BankMoney,
	UpdateTimer,
	Float:Hunger,
	Float:Thirsty,
	ORM:PlayerORM,
	String:UCP,
	String:Name,
	String:Password,
	Float:PX,
	Float:PY,
	Float:PZ,
	Float:PA
};


new 
	LunaPlayer[MAX_PLAYERS][e_PLAYER_DATA]
;


