#include "endgame.h"

int menu(){
    int yMax, xMax;
    char *options[2] = {START, EXIT};
    int choice;
    int highlight = 0;
    getmaxyx(stdscr, yMax, xMax);

    mvwprintw(stdscr, 1, (xMax - 120) / 2, LOGO1);
    mvwprintw(stdscr, 2, (xMax - 120) / 2, LOGO2);
    mvwprintw(stdscr, 3, (xMax - 120) / 2, LOGO3);
    mvwprintw(stdscr, 4, (xMax - 120) / 2, LOGO4);
    mvwprintw(stdscr, 5, (xMax - 120) / 2, LOGO5);
    mvwprintw(stdscr, 6, (xMax - 120) / 2, LOGO6);
    mvwprintw(stdscr, 7, (xMax - 120) / 2, LOGO7);

    WINDOW *menuwin = newwin(50, 100, 15, (xMax - 50) / 2);
    refresh();
    keypad(menuwin, TRUE);
    wrefresh(menuwin);

    while(1)
    {
        for(int i = 0; i < 2; i++) {
            if(highlight == i) wattron(menuwin, COLOR_PAIR(4));
            mvwprintw(menuwin, i*10, 0, options[i]);
            wattroff(menuwin, COLOR_PAIR(4));            
        }
        choice = wgetch(menuwin);
        
        if(choice == KEY_UP) highlight = 0;
        else if (choice == KEY_DOWN) highlight = 1;
        else if (choice == 10) break;        
    }
        
    if(!highlight) {
        wclear(menuwin);
        wrefresh(menuwin);
        delwin(menuwin);
        return 0;    
    }
    else {
        return 1;
    }
}
