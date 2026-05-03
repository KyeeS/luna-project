/*
* Luna Project (c) 2026
* Developed by kyomoto
* Module: Notificaiton.inc
* Purpose: A notification system for Luna Project
*/

#define MAX_LP_NOTIFY                   4
#define MAX_LP_NOTIFY_ROW               3
#define MAX_LP_NOTIFY_LEN               39
#define DEFAULT_NOTIFY_TIME             2000

enum lp_NotifyType
{
    notify_error,
    notify_info,
    notify_success,
    notify_usage
};

static
    p_ActiveNotify[MAX_PLAYERS][MAX_LP_NOTIFY],
    p_NotifyCounter[MAX_PLAYERS],
    p_NotifyTimer[MAX_PLAYERS][MAX_LP_NOTIFY]
;

static const Float:baseNotifyOffset = 43.0;
static PlayerText: lp_notify[MAX_PLAYERS][MAX_LP_NOTIFY][7];

forward OnNotifyHide(playerid, slot);

#if !defined strreplace
	stock strreplace(string[], const search[], const replacement[], bool:ignorecase = false, pos = 0, limit = -1, maxlength = sizeof(string)) 
    {
	    if (limit == 0) 
            return 0;

	    new 
            sublen = strlen(search), 
            replen = strlen(replacement), 
            bool:packed = ispacked(string), 
            maxlen = maxlength,
            len = strlen(string), 
            count = 0
        ;

	    if (packed) maxlen *= 4;
	    if (!sublen) return 0;

	    while (-1 != (pos = strfind(string, search, ignorecase, pos))) 
        {
	        strdel(string, pos, pos + sublen);
	        len -= sublen;
	        if (replen && len + replen < maxlen) 
            {
	            strins(string, replacement, pos, maxlength);
	            pos += replen;
	            len += replen;
	        }
	        if (limit != -1 && ++count >= limit) break;
	    }
	    return count;
	}
#endif

stock static GetNotifyHeader(lp_NotifyType:type)
{
    new str[32];
    switch(type) {
        case notify_error: str = "lunaproject/error";
        case notify_info: str = "lunaproject/info";
        case notify_success: str = "lunaproject/success";
        case notify_usage: str = "lunaproject/usage";
    }
    return str;
}

stock static GetNotifyChit(lp_NotifyType:type)
{
    new dec;
    switch(type) {
        case notify_error: dec = LUNA_RED_SUN;
        case notify_info: dec = LUNA_LIGHT_BLUE;
        case notify_success: dec = LUNA_GREEN;
        case notify_usage: dec = LUNA_GRAY;
    }
    return dec;
}


static Notify_Destroy(playerid, slot)
{
    if(p_NotifyTimer[playerid][slot] != -1) {
        KillTimer(p_NotifyTimer[playerid][slot]);
        p_NotifyTimer[playerid][slot] = -1;
    }

    for(new i; i < 7; i++) {
        if(lp_notify[playerid][slot][i] != PlayerText:INVALID_PLAYER_TEXT_DRAW) {
            PlayerTextDrawDestroy(playerid, lp_notify[playerid][slot][i]);
            lp_notify[playerid][slot][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }
    }
    p_ActiveNotify[playerid][slot] = 0;
    return 1;
}

public OnNotifyHide(playerid, slot)
{
    Notify_Destroy(playerid, slot);
    return 1;
}

stock static Notify_Create(playerid, slot, timer, lp_NotifyType:type, const msg[])
{

    new Float:offset_y = slot * baseNotifyOffset;

    lp_notify[playerid][slot][0] = CreatePlayerTextDraw(playerid, 521.000, 153.000 + offset_y, "_");
    PlayerTextDrawTextSize(playerid, lp_notify[playerid][slot][0], 114.000, 39.000);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][0], -1);
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][0], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][0], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][0], 145);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][0], false);
    PlayerTextDrawSetPreviewModel(playerid, lp_notify[playerid][slot][0], 0);
    PlayerTextDrawSetPreviewRot(playerid, lp_notify[playerid][slot][0], 0.000, 0.000, 0.000, -54.098);
    PlayerTextDrawSetPreviewVehicleColours(playerid, lp_notify[playerid][slot][0], 0, 0);

    lp_notify[playerid][slot][1] = CreatePlayerTextDraw(playerid, 521.000, 153.000 + offset_y, "_");
    PlayerTextDrawTextSize(playerid, lp_notify[playerid][slot][1], 114.000, 10.000);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][1], -1);
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][1], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][1], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][1], 145);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][1], false);
    PlayerTextDrawSetPreviewModel(playerid, lp_notify[playerid][slot][1], 0);
    PlayerTextDrawSetPreviewRot(playerid, lp_notify[playerid][slot][1], 0.000, 0.000, 0.000, -54.098);
    PlayerTextDrawSetPreviewVehicleColours(playerid, lp_notify[playerid][slot][1], 0, 0);

    lp_notify[playerid][slot][2] = CreatePlayerTextDraw(playerid, 522.000, 154.000 + offset_y, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, lp_notify[playerid][slot][2], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][2], GetNotifyChit(type));
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][2], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][2], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][2], 255);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][2], true);

    lp_notify[playerid][slot][3] = CreatePlayerTextDraw(playerid, 527.000, 154.000 + offset_y, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, lp_notify[playerid][slot][3], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][3], GetNotifyChit(type));
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][3], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][3], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][3], 255);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][3], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][3], true);

    lp_notify[playerid][slot][4] = CreatePlayerTextDraw(playerid, 532.000, 154.000 + offset_y, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, lp_notify[playerid][slot][4], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][4], GetNotifyChit(type));
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][4], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][4], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][4], 255);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][4], true);

    lp_notify[playerid][slot][5] = CreatePlayerTextDraw(playerid, 557.000, 154.000 + offset_y, GetNotifyHeader(type));
    PlayerTextDrawLetterSize(playerid, lp_notify[playerid][slot][5], 0.160, 0.699);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][5], -1);
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][5], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][5], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][5], 150);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][5], true);

    lp_notify[playerid][slot][6] = CreatePlayerTextDraw(playerid, 523.000, 163.000 + offset_y, msg);
    PlayerTextDrawLetterSize(playerid, lp_notify[playerid][slot][6], 0.160, 0.799);
    PlayerTextDrawAlignment(playerid, lp_notify[playerid][slot][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, lp_notify[playerid][slot][6], -1);
    PlayerTextDrawSetShadow(playerid, lp_notify[playerid][slot][6], 0);
    PlayerTextDrawSetOutline(playerid, lp_notify[playerid][slot][6], 0);
    PlayerTextDrawBackgroundColour(playerid, lp_notify[playerid][slot][6], 150);
    PlayerTextDrawFont(playerid, lp_notify[playerid][slot][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, lp_notify[playerid][slot][6], true);

    for(new i; i < 7; i++) PlayerTextDrawShow(playerid, lp_notify[playerid][slot][i]);
    
    p_NotifyTimer[playerid][slot] = SetTimerEx("OnNotifyHide", DEFAULT_NOTIFY_TIME*timer, false, "dd", playerid, slot);
    return 1;
}

stock NotifyShow(playerid, lp_NotifyType:type = notify_info, timer = 2, const message[])
{
    new slot = -1;
    for(new i; i < MAX_LP_NOTIFY; i++) {
        if(!p_ActiveNotify[playerid][i]) {
            slot = i;
            break;
        }
    }

    if(slot == -1) {
        slot = p_NotifyCounter[playerid];
        Notify_Destroy(playerid, slot);
        p_NotifyCounter[playerid] = (p_NotifyCounter[playerid] + 1) % MAX_LP_NOTIFY;
    }

    new 
        msg[256], 
        rows = 1
    ;

    format(msg, sizeof(msg), "%s", message);
    new len = strlen(msg);

    if(len > MAX_LP_NOTIFY_LEN)
    {
        for(new i = MAX_LP_NOTIFY_LEN; i < strlen(msg); i += (MAX_LP_NOTIFY_LEN + 3))
        {
            if(rows >= MAX_LP_NOTIFY_ROW) {
                msg[i-MAX_LP_NOTIFY_LEN] = '\0'; 
                break;
            }
            
            strins(msg, "~n~", i, sizeof(msg));
            rows++;
        }
    }

    p_ActiveNotify[playerid][slot] = 1;
    Notify_Create(playerid, slot, timer, type, msg);
    return 1;
}
