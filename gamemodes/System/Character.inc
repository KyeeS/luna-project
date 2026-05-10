native sscanf_s(AmxString:data, const format[], {T_WEAPON, Float, _}:...) = sscanf;

#define MAX_PLAYER_CHARACTER        3
#define MAX_REGISTER_FORM           4

new 
    CCounter[MAX_PLAYERS],
    CharacterList[MAX_PLAYERS][MAX_PLAYER_CHARACTER][e_PLAYER_DATA]
;

stock LoadPlayerCharacter(playerid)
{
    mysql_tquery_s(
        lunaSQL,
        str_format("SELECT Name, RegisterAt, LastLogin, Sex, BirthDay, BirthMonth, BirthYear FROM characters WHERE Username = '%S' LIMIT "#MAX_PLAYER_CHARACTER";", LunaPlayer[playerid][UCP]),
        "OnLoadCharacterData",
        "d",
        playerid
    );
    return 1;
}

forward OnLoadCharacterData(playerid);
public OnLoadCharacterData(playerid)
{
    new rows = cache_num_rows();
    if(!rows) return ShowCharacterCreation(playerid);
    for(new i; i < rows;  i++) 
    {
        new 
            tmp[MAX_PLAYER_NAME],
            rr[32],
            ll[32]
        ;

        cache_get_value_name(i, "Name", tmp, MAX_PLAYER_NAME);
        cache_get_value_name(i, "RegisterAt", rr, 32);
        cache_get_value_name(i, "LastLogin", ll, 32);
        cache_get_value_int(i, "Sex", CharacterList[playerid][i][Sex]);
        cache_get_value_int(i, "BirthDay", CharacterList[playerid][i][BirthDay]);
        cache_get_value_int(i, "BirthMonth", CharacterList[playerid][i][BirthMonth]);
        cache_get_value_int(i, "BirthYear", CharacterList[playerid][i][BirthYear]);
        CharacterList[playerid][i][RegisterAt] = str_acquire(str_new(rr));
        CharacterList[playerid][i][LastLogin] = str_acquire(str_new(ll));
        CharacterList[playerid][i][Name] = str_acquire(str_new(tmp));
    }
    SetPVarInt(playerid, "charRows", rows);
    ShowCharacterList(playerid);
    return 1;
}

stock ShowCharacterList(playerid)
{
    new 
        String:dl = str_new("ID\tCharacter Name\tLast Login\n"),
        total = GetPVarInt(playerid, "charRows")
    ;

    pawn_guard(dl);
    for(new i ; i < total; i ++) 
    {
        if(CharacterList[playerid][i][ID])
        {
            dl = str_append(dl, str_format(
                "%d\t%S\t%S\n",
                CharacterList[playerid][i][ID], 
                CharacterList[playerid][i][Name],
                CharacterList[playerid][i][LastLogin]
            ));
        }
    }
    if(total < MAX_PLAYER_CHARACTER)
    {
        for(new i = total; i < MAX_PLAYER_CHARACTER; i++) 
        {
            dl = str_append(dl, str_format(
                ""E_LUNA_GREEN"[available slot]\t \n"
            ));
        }
    }

    new idx = await ShowAsyncListitemIndexDialog_s(playerid, DIALOG_STYLE_TABLIST_HEADERS, @("Character List(s)"), dl, "Select", "");
    if(idx == -1)  return Kick(playerid);
    if(!CharacterList[playerid][idx][ID]) return ShowCharacterCreation(playerid);

    static const empty[MAX_PLAYER_CHARACTER][e_PLAYER_DATA];
    LunaPlayer[playerid][ID] = CharacterList[playerid][idx][ID];
    LunaPlayer[playerid][LastLogin] = CharacterList[playerid][idx][LastLogin];
    LunaPlayer[playerid][RegisterAt] = CharacterList[playerid][idx][RegisterAt];
    LunaPlayer[playerid][Name] = str_acquire(CharacterList[playerid][idx][Name]);
    CharacterList[playerid] = empty;
    LunaPlayer[playerid][PlayerORM] = LoadPlayerORM(playerid);
    return 1;
}

stock String:ReturnChararcterBD(playerid)
{
    if(!LunaPlayer[playerid][BirthDay]) return STRING_NULL;
    new days = HumanizeGetDayOfWeek(
        LunaPlayer[playerid][BirthDay], 
        LunaPlayer[playerid][BirthMonth], 
        LunaPlayer[playerid][BirthYear]
    );
    new String:str = str_format(
        "%s, %s %d, %d",
        HumanizeDays(days),
        HumanizeMonths(LunaPlayer[playerid][BirthMonth]),
        LunaPlayer[playerid][BirthDay],
        LunaPlayer[playerid][BirthYear]
    );
    return str;
}

stock String:ReturnCharacterSex(playerid)
{
    if(!LunaPlayer[playerid][Sex]) return STRING_NULL;
    return str_format("%s", LunaPlayer[playerid][Sex] ? "Male" : "Female");
}

stock ShowCharacterCreation(playerid)
{
    new String:bd = ReturnChararcterBD(playerid);
    if(bd != STRING_NULL)
    {
        bd = str_append(
            bd, str_format("(%d y.o)",
                HumanizeGetAge(
                    LunaPlayer[playerid][BirthDay], 
                    LunaPlayer[playerid][BirthMonth], 
                    LunaPlayer[playerid][BirthYear]
                )
            )
        );
    }
    else
    {
        str_clear(bd);
        bd = str_new("-");
    }

    new String:dl = str_format(
        "Property\tValue\n\
        Character Name\t%S\n\
        Character Sex\t%S\n\
        Character Skin\t%d\n\
        Character Birthdate\t%S\n\
        ==> Confirmation",
        LunaPlayer[playerid][Name],
        ReturnCharacterSex(playerid),
        LunaPlayer[playerid][Skin],
        bd
    );

    new idx = await ShowAsyncListitemIndexDialog_s(playerid, DIALOG_STYLE_TABLIST_HEADERS, @("Character Creation"), dl, "Select", "");
    if(idx == -1) return Kick(playerid);
    Handle_CharacterCreation(playerid, idx);
    return 1;
}

stock static Handle_CharacterCreation(playerid, idx)
{
    switch(idx)
    {
        case 0:
        {
            new String:body = str_new(
                "Silahkan buat nama karakter roleplay kamu dibawah ini dengan mengikuti format dibawah ini\n\
                Format: Panjang harus 7-24 karakter dan memiliki underscore (_) sebagai pemisah antar Firstname_Lastname\n\
                Contoh: John_Doe, Jane_Doe, Fujino_Takashi"
            );
            new String:input = await_str_s ShowAsyncStringInputDialog_s(playerid, @("Character Creation - Name"), body, "Check", "Back");
            pawn_guard(input);
            if(input == STRING_NULL)
                return ShowCharacterCreation(playerid); 
            
            if(IsRoleplayName(input))
            {
                await mysql_aquery_s(lunaSQL, str_format("SELECT * FROM characters WHERE Name = '%S'", input));
                if(cache_num_rows())
                {
                    SendClientInfo(playerid, "Nama karakter ini sudah terdaftar di database kami.");
                }
                else
                {
                    CCounter[playerid]++;
                    LunaPlayer[playerid][Name] = str_acquire(input);
                }
            }
            else
            {
                SendClientError(playerid, "Nama karakter harus mengikuti format yang sudah ditentukan.");
            }
        }
        case 1:
        {
            new ret = await ShowAsyncListitemIndexDialog_s(playerid, DIALOG_STYLE_LIST, @("Character Creation - Sex"), @("Male\nFemale"), "Select", "Back");
            if(ret == -1)
                return ShowCharacterCreation(playerid);

            CCounter[playerid]++;
            LunaPlayer[playerid][Sex] = ret + 1;
        }
        case 2:
        {
            new skinid = await ShowAsyncNumberInputDialog(playerid, "Character Creation - Skin", "Masukan skinid", "Select", "Back");
            if(skinid == -1)
                return ShowCharacterCreation(playerid);

            if(skinid >= 1 && skinid <= 311)
            {
                CCounter[playerid]++;
                LunaPlayer[playerid][Skin] = skinid;
            }
            else
            {
                SendClientError(playerid, "ID skin yang kamu masukan tidak valid.");
            }
        }
        case 3:
        {
            new 
                String:body = str_new(
                    "Masukan tanggal lahir karakter kamu dengan formrat DD/MM/YYYY\n\
                    Contoh: 12/02/2002\n\
                    Note: Umur karakter harus berada di kisaran 17-70 tahun."
                );
                
            new String:input = await_str_s ShowAsyncStringInputDialog_s(playerid, @("Character Creation - Birthdate"), body, "Check", "Back");
            if(input == STRING_NULL)
                return ShowCharacterCreation(playerid);

            new
                day,
                month,
                year
            ;
            if(sscanf_s(input, "p</>ddd", day, month, year))
            {
                SendClientInfo(playerid, "Mohon mengikuti format yang sudah ditentukan.");
                return ShowCharacterCreation(playerid);   
            }

            if(!(1 <= day <= 31 && 1 <= month <= 12 && year > 1900))
            {
                SendClientError(playerid, "Tanggal lahir kamu tidak valid.");
                return ShowCharacterCreation(playerid);
            }

            new age = HumanizeGetAge(day, month, year);
            if(age < 17 || age > 70)
            {
                SendClientInfo(playerid, "Umur karakter harus berada di rentang 17 hingga 70 tahun.");
                return ShowCharacterCreation(playerid);
            }

            CCounter[playerid]++;
            LunaPlayer[playerid][BirthDay] = day;
            LunaPlayer[playerid][BirthMonth] = month;
            LunaPlayer[playerid][BirthYear] = year;
        }
        case 4:
        {
            if(CCounter[playerid] < MAX_REGISTER_FORM)
            {
                SendClientError(playerid, "Semua field harus di lengkapi terlebih dahulu.");
                return ShowCharacterCreation(playerid);
            }

            new String:body = str_format(
                "{ffffff}\
                Character Name: %S\n\
                Character Sex: %S\n\
                Character Skin: %d\n\
                Character Birthdate: %S\n\
                Apakah kamu sudah yakin dengan data yang kamu buat?",
                LunaPlayer[playerid][Name], 
                ReturnCharacterSex(playerid),
                LunaPlayer[playerid][Skin],
                ReturnChararcterBD(playerid)
            );
            new bool:c = bool:await ShowAsyncConfirmationDialog_s(playerid, @("Character Confirmation"), body, "Confirm", "Back");
            if(c)
            {
                return mysql_tquery_s(
                    lunaSQL,
                    str_format(
                        "INSERT INTO characters (Username, Name, Skin, Sex, BirthDay, BirthMonth, BirthYear) VALUES ('%S', '%S', %d, %d, %d, %d, %d)",
                        LunaPlayer[playerid][UCP],
                        LunaPlayer[playerid][Name], 
                        LunaPlayer[playerid][Skin],
                        LunaPlayer[playerid][Sex],
                        LunaPlayer[playerid][BirthDay],
                        LunaPlayer[playerid][BirthMonth],
                        LunaPlayer[playerid][BirthYear]
                    ),
                    "OnPlayerCreateCharacter",
                    "d",
                    playerid
                );
            }
            else return ShowCharacterCreation(playerid);
        }
        default: return Kick(playerid); // -1
    }
    return ShowCharacterCreation(playerid);
}

forward OnPlayerCreateCharacter(playerid);
public OnPlayerCreateCharacter(playerid)
{
    LunaPlayer[playerid][ID] = cache_insert_id();
    LunaPlayer[playerid][PlayerORM] = LoadPlayerORM(playerid, .load = false); // untuk fix 'invalid orm id'
    ClearPlayerChat(playerid);
    NotifyShow(playerid, .message = "Berhasil mendaftarkan karakter.");
    SetPlayerName_s(playerid, LunaPlayer[playerid][Name]);
    SetPlayerColor(playerid, -1);
    SetSpawnInfo(
        playerid, NO_TEAM, 
        LunaPlayer[playerid][Skin], 
        -1964.7767,143.5651,27.6875, 
        88.4995
    );
    SetPlayerHBE(playerid, 100.0, PLAYER_HUNGER);
    SetPlayerHBE(playerid, 100.0, PLAYER_THIRSTY);
    SpawnPlayer(playerid);
    return 1;
}