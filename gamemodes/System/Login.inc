#define PASSWORD_REGEX     "(?=.*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]).{8,32}"
#define MAX_LOGIN_ATTEMPTS  3

stock CheckLoginName(playerid, login_ic)
{
    new String:player_name = ReturnPlayerName(playerid);
    foreach(new i : Player) 
    {
        if(IsPlayerSpawned(i))
        {
            if(!login_ic) 
            { 
                if(str_eq(player_name, LunaPlayer[i][UCP])) return 1;
            }
            else
            {
                await mysql_aquery_s(lunaSQL, str_format("SELECT Username FROM Characters WHERE Name = '%S'", player_name));
                if(cache_num_rows())
                {
                    new
                        tmp[MAX_UCP_NAME+1]
                    ;
                    cache_get_value_name(0, "Username", tmp);
                    if(str_eq(player_name, LunaPlayer[i][UCP])) return 1;
                }
                else Kick(playerid);
            }
        }
    }
    return 0;
}

stock VerifyPlayerLogin(playerid)
{
    new ltype = IsRoleplayName(ReturnPlayerName(playerid));
    new check = CheckLoginName(playerid, ltype);

    if(check)
    {
        SendClientError(playerid, "Akun ini sudah terlebih dahulu login di perangkat lain.");
        DelayedKick(playerid);
    }

    if(ltype)
    {
        await mysql_aquery_s(lunaSQL, str_format("SELECT ID, Username FROM Characters WHERE Name = '%S'", ReturnPlayerName(playerid)));
        if(cache_num_rows())
        {
            new
                ucp[MAX_UCP_NAME]
            ;

            cache_get_value_name(0, "Username", ucp, MAX_UCP_NAME);
            cache_get_value_int(0, "ID", LunaPlayer[playerid][ID]);
            LunaPlayer[playerid][UCP] = str_acquire(str_new(ucp));
            LunaPlayer[playerid][Name] = str_acquire(ReturnPlayerName(playerid));
            return mysql_tquery_s(
                lunaSQL, 
                str_format("SELECT Password FROM ucp WHERE Username = '%S'", LunaPlayer[playerid][UCP]),
                "ProcessLogin_IC",
                "d",
                playerid
            );
        }
        else
        {
            SendClientError(playerid, "Karakter ini tidak valid.");
            DelayedKick(playerid);
        }
    }
    else LoadPlayerUCP(playerid);
    return 1;
}

forward ProcessLogin_IC(playerid);
public ProcessLogin_IC(playerid)
{
    if(cache_num_rows())
    {
        new
            pw[BCRYPT_HASH_LENGTH]
        ;

        cache_get_value_name(0, "Password", pw);
        LunaPlayer[playerid][Password] = str_acquire(str_new(pw));
        SetPVarInt(playerid, "login_ic", 1);
        ShowLoginDialog(playerid);
    }
    return 1;
}

stock LoadPlayerUCP(playerid)
{
    await mysql_aquery_s(lunaSQL, str_format("SELECT * FROM ucp WHERE Username = '%S'", ReturnPlayerName(playerid)));
    if(cache_num_rows())
    {
        new
            ucp[MAX_UCP_NAME],
            pw[BCRYPT_HASH_LENGTH]
        ;
        cache_get_value_name(0, "Username", ucp, MAX_UCP_NAME);
        cache_get_value_name(0, "Password", pw, BCRYPT_HASH_LENGTH);
        LunaPlayer[playerid][UCP] = str_acquire(str_new(ucp));
        LunaPlayer[playerid][Password] = str_acquire(str_new(pw));
        SetPVarInt(playerid, "logonAttempts", 0);
        ShowLoginDialog(playerid);
    }
    else
    {
        SendClientInfo(playerid, "Akun ini belum terdaftar di "E_LUNA_COL""SERVER_NAME""E_LUNA_WHITE".");
        ShowRegisterDialog(playerid);
    }
    return 1;
}

stock ShowLoginDialog(playerid)
{
    new 
        attempts = GetPVarInt(playerid, "logonAttempts"),
        String:body = str_format(
            ""E_LUNA_WHITE"\
            Selamat datang kembali, "E_LUNA_DUSTY_PEACH"@%S"E_LUNA_WHITE".\n\
            Silahkan masukan password kamu dibawah ini dengan benar.\n\
            Kamu mempunyai kesempatan login sebanyak: "E_LUNA_RED_SUN"%d/%d",
            LunaPlayer[playerid][UCP],
            attempts, MAX_LOGIN_ATTEMPTS
        )
    ;
    new String:res = await_str_s ShowAsyncPasswordDialog_s(playerid, @("Login Session"), body, "Login", "Quit");
    if(res == STRING_NULL) return Kick(playerid);
    ShowLoginDialog_Handle(playerid, res);
    return 1;
}

stock ShowLoginDialog_Handle(playerid, String:input)
{
    new verify = await bcrypt_async_verify_s(input, LunaPlayer[playerid][Password]);
    if(!verify)
    {
        new attempts = GetPVarInt(playerid, "logonAttempts");
        if(++attempts > MAX_LOGIN_ATTEMPTS)
        {
            SendClientError(playerid, "Kamu telah memasukan password yang salah sebanyak "E_LUNA_RED_SUN""#MAX_LOGIN_ATTEMPTS" "E_LUNA_WHITE"kali.");
            SendClientInfo(playerid, "Jika mengalami lupa password, silahkan buat thread di offical discord kami.");
            DelayedKick(playerid); 
            return 0;
        }
        SetPVarInt(playerid, "logonAttempts", attempts);
        ShowLoginDialog(playerid);
    }
    else
    {
        if(GetPVarInt(playerid, "login_ic") == 1) 
        {
            LunaPlayer[playerid][PlayerORM] = LoadPlayerORM(playerid);
            return 1;
        }

        await mysql_aquery_s(lunaSQL, str_format("SELECT ID FROM Characters WHERE Username = '%S'", LunaPlayer[playerid][UCP]));
        new rows = cache_num_rows();
        if(rows)
        {
            for(new i ; i < rows;  i ++) 
            {
                cache_get_value_int(i, "ID", CharacterList[playerid][i][ID]);
            }
            LoadPlayerCharacter(playerid);
        }
        else ShowCharacterCreation(playerid);
    }
    return 1;
}

stock ShowRegisterDialog(playerid)
{
    new String:body = str_format(
        ""E_LUNA_WHITE"\
        Selamat datang, "E_LUNA_DUSTY_PEACH"@%S"E_LUNA_WHITE".\n\
        Akun ini belum terdaftar, silahkan buat password dibawah ini untuk melanjutkan sesi pendaftaran.\n\
        Format: Panjang pasword wajib 8-32 karakter dan setidaknya menggunakan unique symbol seperti (#, @, !, $)",
        ReturnPlayerName(playerid)
    );
    new String:res = await_str_s ShowAsyncStringInputDialog_s(playerid, @("Register Sessions"), body, "Check", "");
    if(res == STRING_NULL) return Kick(playerid);
    ShowRegisterDialog_Handle(playerid, res);
    return 1;
}

stock ShowRegisterDialog_Handle(playerid, String:input)
{
    if(!str_match(input, PASSWORD_REGEX))
    {
        SendClientError(playerid, "Kamu harus mengikuti format password yang sudah ditentukan.");
        ShowRegisterDialog(playerid);
    }
    else
    {
        new String:hash = await_str_s bcrypt_async_hash_s(input);
        LunaPlayer[playerid][UCP] = str_acquire(ReturnPlayerName(playerid));
        LunaPlayer[playerid][Password] = str_acquire(hash);

        new String:query = str_format(
            "INSERT INTO ucp (Username, Password) VALUES ('%S', '%S')",
            LunaPlayer[playerid][UCP],
            LunaPlayer[playerid][Password]
        );
        await mysql_aquery_s(lunaSQL, query);
        ShowLoginDialog(playerid);
    }
    return 1;
}