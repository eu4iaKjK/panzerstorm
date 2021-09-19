#pragma once

#ifndef ENDGAME_H
#define ENDGAME_H
#include <ncurses.h>
#include <stdlib.h>

#define LOGO1 ":::::::::     :::     ::::    ::: ::::::::: :::::::::: :::::::::   :::::::: ::::::::::: ::::::::  :::::::::  ::::    ::::  \n"
#define LOGO2 ":+:    :+:  :+: :+:   :+:+:   :+:      :+:  :+:        :+:    :+: :+:    :+:    :+:    :+:    :+: :+:    :+: +:+:+: :+:+:+ \n"
#define LOGO3 "+:+    +:+ +:+   +:+  :+:+:+  +:+     +:+   +:+        +:+    +:+ +:+           +:+    +:+    +:+ +:+    +:+ +:+ +:+:+ +:+ \n"
#define LOGO4 "+#++:++#+ +#++:++#++: +#+ +:+ +#+    +#+    +#++:++#   +#++:++#:  +#++:++#++    +#+    +#+    +:+ +#++:++#:  +#+  +:+  +#+ \n"
#define LOGO5 "+#+       +#+     +#+ +#+  +#+#+#   +#+     +#+        +#+    +#+        +#+    +#+    +#+    +#+ +#+    +#+ +#+       +#+ \n"
#define LOGO6 "#+#       #+#     #+# #+#   #+#+#  #+#      #+#        #+#    #+# #+#    #+#    #+#    #+#    #+# #+#    #+# #+#       #+# \n"
#define LOGO7 "###       ###     ### ###    #### ######### ########## ###    ###  ########     ###     ########  ###    ### ###       ### \n"
#define START " /$$$$$$   /$$                           /$$    \n /$$__  $$ | $$                          | $$    \n| $$  \\__//$$$$$$    /$$$$$$   /$$$$$$  /$$$$$$  \n|  $$$$$$|_  $$_/   |____  $$ /$$__  $$|_  $$_/  \n \\____  $$ | $$      /$$$$$$$| $$  \\__/  | $$    \n /$$  \\ $$ | $$ /$$ /$$__  $$| $$        | $$ /$$\n|  $$$$$$/ |  $$$$/|  $$$$$$$| $$        |  $$$$/\n \\______/   \\___/   \\_______/|__/         \\___/  "
#define EXIT " /$$$$$$$$           /$$   /$$    \n| $$_____/          |__/  | $$    \n| $$       /$$   /$$ /$$ /$$$$$$  \n| $$$$$   |  $$ /$$/| $$|_  $$_/  \n| $$__/    \\  $$$$/ | $$  | $$    \n| $$        >$$  $$ | $$  | $$ /$$\n| $$$$$$$$ /$$/\\  $$| $$  |  $$$$/\n|________/|__/  \\__/|__/   \\___/  "
#define BLUE "\
 /$$$$$$$  /$$                           /$$      /$$ /$$                    \n\
| $$__  $$| $$                          | $$  /$ | $$|__/                    \n\
| $$  \\ $$| $$ /$$   /$$  /$$$$$$       | $$ /$$$| $$ /$$ /$$$$$$$   /$$$$$$$\n\
| $$$$$$$ | $$| $$  | $$ /$$__  $$      | $$/$$ $$ $$| $$| $$__  $$ /$$_____/\n\
| $$__  $$| $$| $$  | $$| $$$$$$$$      | $$$$_  $$$$| $$| $$  \\ $$|  $$$$$$ \n\
| $$  \\ $$| $$| $$  | $$| $$_____/      | $$$/ \\  $$$| $$| $$  | $$ \\____  $$\n\
| $$$$$$$/| $$|  $$$$$$/|  $$$$$$$      | $$/   \\  $$| $$| $$  | $$ /$$$$$$$/\n\
|_______/ |__/ \\______/  \\_______/      |__/     \\__/|__/|__/  |__/|_______/ "

#define RED "\
 /$$$$$$$                  /$$       /$$      /$$ /$$                    \n\
| $$__  $$                | $$      | $$  /$ | $$|__/                    \n\
| $$  \\ $$  /$$$$$$   /$$$$$$$      | $$ /$$$| $$ /$$ /$$$$$$$   /$$$$$$$\n\
| $$$$$$$/ /$$__  $$ /$$__  $$      | $$/$$ $$ $$| $$| $$__  $$ /$$_____/\n\
| $$__  $$| $$$$$$$$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$|  $$$$$$ \n\
| $$  \\ $$| $$_____/| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$ \\____  $$\n\
| $$  | $$|  $$$$$$$|  $$$$$$$      | $$/   \\  $$| $$| $$  | $$ /$$$$$$$/\n\
|__/  |__/ \\_______/ \\_______/      |__/     \\__/|__/|__/  |__/|_______/ "
#define DELAY 150000

typedef struct s_player
{
    int PlayerID;
    int xLoc;
    int yLoc;
    int FirstSpawnX;
    int FirstSpawnY;
    int dir;
    char character;
    bool IsShoting;
    int BulletX;
    int BulletY;
    int BulletDir;
}player;

typedef struct s_game
{
    int xMax;
    int yMax;
    int red_score;
    int blue_score;
    bool IsRunning;
    bool IsRestarted;
    WINDOW* currWindow;
}game;


void mvup(player *player1, player *player2, game *game);
void mvdown(player *player1, player *player2, game *game);
void mvleft(player *player1, player *player2, game *game);
void mvright(player *player1, player *player2, game *game);
void getmv(player *player1, player *player2, game *game);
void display(player *player, game *game);
void shoot(player *player1, player *player2, game *game);
void Restart(player *player1, player *player2, game *game);
WINDOW *draw_map();
int menu();


#endif
