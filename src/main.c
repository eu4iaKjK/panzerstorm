#include "endgame.h"

int main() {
	initscr();
	curs_set(0);

	start_color();
	init_pair(2, COLOR_BLACK, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_RED, COLOR_BLACK);

	noecho();
	int max_y;
	int max_x;
	int count1 = 0;
	int count2 = 0;
	int win = 0;
	int choice = 0;
	getmaxyx(stdscr, max_y, max_x);
ENTER:

	if(menu() == 1) {
		endwin();
		exit(0);
		return 1;
	}

	WINDOW *playwin = draw_map();
	game game = {100, 50, 0, 0, true, false, playwin};
	player player1 = {0, 4, 5, 4, 5, 1, '^', false};
	player player2 = {1, 10, 15, 10, 15, 1, '^', false};
	refresh();
	keypad(playwin, TRUE);
	display(&player1, &game);
	wrefresh(playwin);
	win = 0;
	
	while(game.IsRunning) {
		getmv(&player1, &player2, &game);
		if(count1 == 1000) {
			if(player1.IsShoting) {
				shoot(&player1, &player2, &game);
			}
			count1 = 0;
		}
		if(count2 == 1000) {
			if(player2.IsShoting) {
				shoot(&player2, &player1, &game);
			}
			count2 = 0;
		}
		wattron(playwin, COLOR_PAIR(2));
		display(&player1, &game);
		wattroff(playwin, COLOR_PAIR(2));
		wattron(playwin, COLOR_PAIR(3));	
		display(&player2, &game);
		wattroff(playwin, COLOR_PAIR(3));
		wrefresh(playwin);
		count1++;
		count2++;

		if(game.blue_score == 5) { win = 1; break; }
		else if(game.red_score == 5) { win = 2; break; }

		wattron(playwin, COLOR_PAIR(2));
		mvwprintw(playwin, 0, 0, "%d", game.blue_score);
		wattroff(playwin, COLOR_PAIR(2));
		wattron(playwin, COLOR_PAIR(3));
		mvwprintw(playwin, 0, 99, "%d", game.red_score);
		wattroff(playwin, COLOR_PAIR(3));
	}
	if(win == 0) {
		wclear(playwin);
		wrefresh(playwin);
		delwin(playwin);
		goto ENTER;
	}
	else if(win == 1) {
		wclear(playwin);
		wrefresh(playwin);
		delwin(playwin);
		WINDOW *wind = newwin(50, 100, 15, (max_x - 80) / 2);
		wattron(wind, COLOR_PAIR(2) | A_REVERSE);
		mvwprintw(wind, 0, 0, BLUE);
		wattroff(wind, COLOR_PAIR(2) | A_REVERSE);
		wrefresh(wind);
		while(choice != (int)'q') {
			choice = getch();
		}
		choice = 0;
		wclear(wind);
		wrefresh(wind);
		delwin(wind);
		goto ENTER;
	}
	else if(win == 2) {
		wclear(playwin);
		wrefresh(playwin);
		delwin(playwin);
		WINDOW *wind = newwin(50, 100, 15, (max_x - 80) / 2);
		wattron(wind, COLOR_PAIR(3) | A_REVERSE);
		mvwprintw(wind, 0, 0, RED);
		wattroff(wind, COLOR_PAIR(3) | A_REVERSE);
		wrefresh(wind);
		while(choice != (int)'q') {
			choice = getch();
		}
		choice = 0;
		wclear(wind);
		wrefresh(wind);
		delwin(wind);
		goto ENTER;
	}

	return 1337;
}
