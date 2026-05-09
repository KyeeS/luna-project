new PlayerText: LunaHBE[MAX_PLAYERS][22];
new Text: LunaIcon[9];

stock LoadPlayerTextDraw(playerid)
{
    /*
        Index:
        10 - 14 : hunger
        15 - 19 : thirsty
    */
    LunaHBE[playerid][0] = CreatePlayerTextDraw(playerid, 623.000, 427.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][0], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][0], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][0], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][0], true);

    LunaHBE[playerid][1] = CreatePlayerTextDraw(playerid, 623.000, 419.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][1], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][1], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][1], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][1], true);

    LunaHBE[playerid][2] = CreatePlayerTextDraw(playerid, 623.000, 411.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][2], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][2], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][2], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][2], true);

    LunaHBE[playerid][3] = CreatePlayerTextDraw(playerid, 623.000, 403.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][3], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][3], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][3], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][3], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][3], true);

    LunaHBE[playerid][4] = CreatePlayerTextDraw(playerid, 623.000, 395.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][4], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][4], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][4], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][4], true);

    LunaHBE[playerid][5] = CreatePlayerTextDraw(playerid, 607.000, 427.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][5], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][5], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][5], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][5], true);

    LunaHBE[playerid][6] = CreatePlayerTextDraw(playerid, 607.000, 419.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][6], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][6], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][6], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][6], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][6], true);

    LunaHBE[playerid][7] = CreatePlayerTextDraw(playerid, 607.000, 411.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][7], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][7], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][7], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][7], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][7], true);

    LunaHBE[playerid][8] = CreatePlayerTextDraw(playerid, 607.000, 403.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][8], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][8], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][8], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][8], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][8], true);

    LunaHBE[playerid][9] = CreatePlayerTextDraw(playerid, 607.000, 395.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][9], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][9], 127);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][9], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][9], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][9], true);

    LunaHBE[playerid][10] = CreatePlayerTextDraw(playerid, 623.000, 433.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][10], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][10], -558331905);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][10], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][10], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][10], true);

    LunaHBE[playerid][11] = CreatePlayerTextDraw(playerid, 623.000, 425.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][11], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][11], -558331905);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][11], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][11], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][11], true);

    LunaHBE[playerid][12] = CreatePlayerTextDraw(playerid, 623.000, 417.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][12], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][12], -558331905);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][12], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][12], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][12], true);

    LunaHBE[playerid][13] = CreatePlayerTextDraw(playerid, 623.000, 409.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][13], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][13], -558331905);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][13], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][13], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][13], true);

    LunaHBE[playerid][14] = CreatePlayerTextDraw(playerid, 623.000, 401.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][14], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][14], -558331905);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][14], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][14], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][14], true);

    LunaHBE[playerid][15] = CreatePlayerTextDraw(playerid, 607.000, 433.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][15], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][15], -1343295745);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][15], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][15], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][15], true);

    LunaHBE[playerid][16] = CreatePlayerTextDraw(playerid, 607.000, 425.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][16], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][16], -1343295745);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][16], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][16], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][16], true);

    LunaHBE[playerid][17] = CreatePlayerTextDraw(playerid, 607.000, 417.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][17], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][17], -1343295745);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][17], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][17], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][17], true);

    LunaHBE[playerid][18] = CreatePlayerTextDraw(playerid, 607.000, 409.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][18], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][18], -1343295745);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][18], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][18], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][18], true);

    LunaHBE[playerid][19] = CreatePlayerTextDraw(playerid, 607.000, 401.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LunaHBE[playerid][19], 11.000, -6.000);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][19], -1343295745);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][19], 255);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][19], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][19], true);

    LunaHBE[playerid][20] = CreatePlayerTextDraw(playerid, 624.000, 382.000, "H");
    PlayerTextDrawLetterSize(playerid, LunaHBE[playerid][20], 0.280, 1.199);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][20], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][20], 1);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][20], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][20], 150);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][20], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][20], true);

    LunaHBE[playerid][21] = CreatePlayerTextDraw(playerid, 608.000, 382.000, "T");
    PlayerTextDrawLetterSize(playerid, LunaHBE[playerid][21], 0.280, 1.199);
    PlayerTextDrawAlignment(playerid, LunaHBE[playerid][21], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, LunaHBE[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, LunaHBE[playerid][21], 1);
    PlayerTextDrawSetOutline(playerid, LunaHBE[playerid][21], 0);
    PlayerTextDrawBackgroundColour(playerid, LunaHBE[playerid][21], 150);
    PlayerTextDrawFont(playerid, LunaHBE[playerid][21], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, LunaHBE[playerid][21], true);
}

stock LoadGlobalTextDraw()
{
    LunaIcon[0] = TextDrawCreate(303.000, 2.000, "/");
    TextDrawLetterSize(LunaIcon[0], 0.650, 1.399);
    TextDrawAlignment(LunaIcon[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[0], 1520156671);
    TextDrawSetShadow(LunaIcon[0], 0);
    TextDrawSetOutline(LunaIcon[0], 0);
    TextDrawBackgroundColour(LunaIcon[0], 150);
    TextDrawFont(LunaIcon[0], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[0], true);

    LunaIcon[1] = TextDrawCreate(303.000, 2.000, "/");
    TextDrawLetterSize(LunaIcon[1], 0.650, 1.399);
    TextDrawAlignment(LunaIcon[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[1], 1520156671);
    TextDrawSetShadow(LunaIcon[1], 0);
    TextDrawSetOutline(LunaIcon[1], 0);
    TextDrawBackgroundColour(LunaIcon[1], 150);
    TextDrawFont(LunaIcon[1], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[1], true);

    LunaIcon[2] = TextDrawCreate(303.000, 2.000, "/");
    TextDrawLetterSize(LunaIcon[2], 0.650, 1.399);
    TextDrawAlignment(LunaIcon[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[2], 1520156671);
    TextDrawSetShadow(LunaIcon[2], 0);
    TextDrawSetOutline(LunaIcon[2], 0);
    TextDrawBackgroundColour(LunaIcon[2], 150);
    TextDrawFont(LunaIcon[2], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[2], true);

    LunaIcon[3] = TextDrawCreate(303.000, 2.000, "/");
    TextDrawLetterSize(LunaIcon[3], 0.650, 1.399);
    TextDrawAlignment(LunaIcon[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[3], 1520156671);
    TextDrawSetShadow(LunaIcon[3], 0);
    TextDrawSetOutline(LunaIcon[3], 0);
    TextDrawBackgroundColour(LunaIcon[3], 150);
    TextDrawFont(LunaIcon[3], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[3], true);

    LunaIcon[4] = TextDrawCreate(303.000, 2.000, "/");
    TextDrawLetterSize(LunaIcon[4], 0.650, 1.399);
    TextDrawAlignment(LunaIcon[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[4], 1520156671);
    TextDrawSetShadow(LunaIcon[4], 0);
    TextDrawSetOutline(LunaIcon[4], 0);
    TextDrawBackgroundColour(LunaIcon[4], 150);
    TextDrawFont(LunaIcon[4], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[4], true);

    LunaIcon[5] = TextDrawCreate(297.000, 4.000, "LD_BEAT:chit");
    TextDrawTextSize(LunaIcon[5], 7.000, 8.000);
    TextDrawAlignment(LunaIcon[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[5], 1520156671);
    TextDrawSetShadow(LunaIcon[5], 0);
    TextDrawSetOutline(LunaIcon[5], 0);
    TextDrawBackgroundColour(LunaIcon[5], 255);
    TextDrawFont(LunaIcon[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(LunaIcon[5], true);

    LunaIcon[6] = TextDrawCreate(315.000, 3.000, "una");
    TextDrawLetterSize(LunaIcon[6], 0.290, 1.399);
    TextDrawAlignment(LunaIcon[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[6], -1);
    TextDrawSetShadow(LunaIcon[6], 0);
    TextDrawSetOutline(LunaIcon[6], 0);
    TextDrawBackgroundColour(LunaIcon[6], 150);
    TextDrawFont(LunaIcon[6], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(LunaIcon[6], true);

    LunaIcon[7] = TextDrawCreate(305.000, 12.000, "LD_SPAC:white");
    TextDrawTextSize(LunaIcon[7], 9.000, 3.000);
    TextDrawAlignment(LunaIcon[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[7], 1520156671);
    TextDrawSetShadow(LunaIcon[7], 0);
    TextDrawSetOutline(LunaIcon[7], 0);
    TextDrawBackgroundColour(LunaIcon[7], 255);
    TextDrawFont(LunaIcon[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(LunaIcon[7], true);

    LunaIcon[8] = TextDrawCreate(297.000, 20.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(LunaIcon[8], 41.000, -4.000);
    TextDrawAlignment(LunaIcon[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(LunaIcon[8], 1520156671);
    TextDrawSetShadow(LunaIcon[8], 0);
    TextDrawSetOutline(LunaIcon[8], 0);
    TextDrawBackgroundColour(LunaIcon[8], 255);
    TextDrawFont(LunaIcon[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(LunaIcon[8], true);

    return 1;
}

// stock LoadPlayerTextDraw(playerid) return 1;