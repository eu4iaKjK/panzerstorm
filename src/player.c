#include <ncurses.h>
#include <stdlib.h>
#include "endgame.h"
#include <unistd.h>

void mvup(player *player1, player *player2, game *game) {
    mvwprintw(game->currWindow, player1->yLoc, player1->xLoc,"%c" ,' ');
    player1->yLoc--;
    player1->dir = 1;
    player1->character = '^';
    if(player1->yLoc < 1) {
        player1->yLoc = 1;
    }
    if((player1->yLoc == player2->yLoc && player1->xLoc == player2->xLoc) || (int)mvwinch(game->currWindow, player1->yLoc, player1->xLoc) == (int)'X') player1->yLoc++;
    display(player1, game);
    wrefresh(game->currWindow);
}

void mvdown(player *player1, player *player2, game *game) {
    mvwprintw(game->currWindow, player1->yLoc, player1->xLoc, "%c", ' ');
    player1->yLoc++;
    player1->dir = 2;
    player1->character = 'v';
    if(player1->yLoc > game->yMax - 2) {
        player1->yLoc = game->yMax - 2;
    }
    if((player1->yLoc == player2->yLoc && player1->xLoc == player2->xLoc) || (int)mvwinch(game->currWindow, player1->yLoc, player1->xLoc) == (int)'X') player1->yLoc--;
    display(player1, game);
    wrefresh(game->currWindow);
}

void mvleft(player *player1, player *player2, game *game) {
    mvwprintw(game->currWindow, player1->yLoc, player1->xLoc, "%c", ' ');
    player1->xLoc--;
    player1->dir = 3;
    player1->character = '<';
    if(player1->xLoc<1) {
        player1->xLoc = 1;
    }
    if((player1->yLoc == player2->yLoc && player1->xLoc == player2->xLoc) || (int)mvwinch(game->currWindow, player1->yLoc, player1->xLoc) == (int)'X') player1->xLoc++;
    display(player1, game);
    wrefresh(game->currWindow);
}

void mvright(player *player1, player *player2, game *game) {
    mvwprintw(game->currWindow, player1->yLoc, player1->xLoc, "%c", ' ');
    player1->xLoc++;
    player1->dir = 4;
    player1->character = '>';
    if(player1->xLoc > game->xMax - 2) {
        player1->xLoc = game->xMax - 2;
    }
    if((player1->yLoc == player2->yLoc && player1->xLoc == player2->xLoc) || (int)mvwinch(game->currWindow, player1->yLoc, player1->xLoc) == (int)'X') player1->xLoc--;
    display(player1, game);
    wrefresh(game->currWindow);
}

void Restart(player *player1, player *player2, game *game) {
    if(player1->PlayerID == 0) game->blue_score++;
    else game->red_score++;
    game->IsRestarted = true;
    if(player2->IsShoting) mvwprintw(game->currWindow, player2->BulletY, player2->BulletX ,"%c" , ' ');
    mvwprintw(game->currWindow, player1->yLoc, player1->xLoc ,"%c" , ' ');
    mvwprintw(game->currWindow, player2->yLoc, player2->xLoc ,"%c" , ' ');

    player1->IsShoting = false;
    player2->IsShoting = false;
    player1->xLoc = player1->FirstSpawnX;
    player1->yLoc = player1->FirstSpawnY;
    player2->xLoc = player2->FirstSpawnX;
    player2->yLoc = player2->FirstSpawnY;
}

void shoot(player *player1, player *player2, game *game) {
    if(player1->PlayerID == 0) wattron(game->currWindow, COLOR_PAIR(2) | A_REVERSE);
    else wattron(game->currWindow, COLOR_PAIR(3) | A_REVERSE);
    switch (player1->BulletDir)
    {
    case 1:
        player1->BulletY--;
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX) == (int)'X' || player1->BulletY == 0) {
            if((int)mvwinch(game->currWindow, player1->BulletY + 1, player1->BulletX) > 260000) mvwprintw(game->currWindow, player1->BulletY + 1, player1->BulletX ,"%c" , ' ');
            player1->IsShoting = false;
            break;
        }
        if(player1->BulletX == player2->xLoc && player1->BulletY == player2->yLoc) {
            mvwprintw(game->currWindow, player1->BulletY + 1, player1->BulletX ,"%c" , ' ');
            Restart(player1, player2, game);
            break;
        }
        mvwprintw(game->currWindow, player1->BulletY, player1->BulletX, "%c", '*');
        if((int)mvwinch(game->currWindow, player1->BulletY + 1, player1->BulletX) > 260000) mvwprintw(game->currWindow, player1->BulletY + 1, player1->BulletX ,"%c" , ' ');
        break;
    case 2:
        player1->BulletY++;
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX) == (int)'X' || player1->BulletY == game->yMax - 1) {
            if((int)mvwinch(game->currWindow, player1->BulletY - 1, player1->BulletX) > 260000) mvwprintw(game->currWindow, player1->BulletY - 1, player1->BulletX ,"%c" , ' ');
            player1->IsShoting = false;
            break;
        }
        if(player1->BulletX == player2->xLoc && player1->BulletY == player2->yLoc) {
            mvwprintw(game->currWindow, player1->BulletY - 1, player1->BulletX ,"%c" , ' ');
            Restart(player1, player2, game);
            break;
        }
        mvwprintw(game->currWindow, player1->BulletY, player1->BulletX, "%c", '*');
        if((int)mvwinch(game->currWindow, player1->BulletY - 1, player1->BulletX) > 260000) mvwprintw(game->currWindow, player1->BulletY - 1, player1->BulletX ,"%c" , ' ');
        break;
    case 3:
        player1->BulletX--;
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX) == (int)'X' || player1->BulletX == 0) {
            if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX + 1) > 260000) mvwprintw(game->currWindow, player1->BulletY, player1->BulletX + 1 ,"%c" , ' ');
            player1->IsShoting = false;
            break;
        }
        if(player1->BulletX == player2->xLoc && player1->BulletY == player2->yLoc) {
            mvwprintw(game->currWindow, player1->BulletY, player1->BulletX + 1,"%c" , ' ');
            Restart(player1, player2, game);
            break;
        }
        mvwprintw(game->currWindow, player1->BulletY, player1->BulletX, "%c", '*');
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX + 1) > 260000) mvwprintw(game->currWindow, player1->BulletY, player1->BulletX + 1,"%c" , ' ');
        break;
    case 4:
        player1->BulletX++;
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX) == (int)'X' || player1->BulletX == game->xMax - 1) {
            if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX - 1) > 260000) mvwprintw(game->currWindow, player1->BulletY, player1->BulletX - 1,"%c" , ' ');
            player1->IsShoting = false;
            break;
        }
        if(player1->BulletX == player2->xLoc && player1->BulletY == player2->yLoc) {
            mvwprintw(game->currWindow, player1->BulletY, player1->BulletX - 1,"%c" , ' ');
            Restart(player1, player2, game);
            break;
        }
        mvwprintw(game->currWindow, player1->BulletY, player1->BulletX, "%c", '*');
        if((int)mvwinch(game->currWindow, player1->BulletY, player1->BulletX - 1) > 260000) mvwprintw(game->currWindow, player1->BulletY, player1->BulletX - 1,"%c" , ' ');
        break;  
    default:
        break;
    }
    if(player1->PlayerID == 0) wattroff(game->currWindow, COLOR_PAIR(2) | A_REVERSE);
    else wattroff(game->currWindow, COLOR_PAIR(3) | A_REVERSE);
}

void getmv(player *player1, player *player2, game *game) {
    nodelay(game->currWindow, TRUE);
    int choice = wgetch(game->currWindow);
    if(choice != ERR) {
        switch(choice) {
            case (int)KEY_UP:
                mvup(player2, player1, game);
                break;
            case (int)KEY_DOWN:
                mvdown(player2, player1, game);
                break;
            case (int)KEY_LEFT:
                mvleft(player2, player1, game);
                break;
            case (int)KEY_RIGHT:
                mvright(player2, player1, game);
                break;
            case (int)'w':
                mvup(player1, player2, game);
                break;
            case (int)'s':
                mvdown(player1, player2, game);
                break;
            case (int)'a':
                mvleft(player1, player2, game);
                break;
            case (int)'d':
                mvright(player1, player2, game);
                break;
            case (int)'0':
                if(!player2->IsShoting) {
                    player2->IsShoting = true;
                    player2->BulletX = player2->xLoc;
                    player2->BulletY = player2->yLoc;
                    player2->BulletDir = player2->dir;
                }
                break;
            case (int)'f':
                if(!player1->IsShoting) {
                    player1->IsShoting = true;
                    player1->BulletX = player1->xLoc;
                    player1->BulletY = player1->yLoc;
                    player1->BulletDir = player1->dir;
                }
                break;
            case (int)'q':
                game->IsRunning = false;
                break;
            default:
                break;
        }
    }
}

void display(player *player, game *game) {
    mvwprintw(game->currWindow, player->yLoc, player->xLoc, "%c" ,player->character);
}
