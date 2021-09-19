#include "endgame.h"

WINDOW *draw_map() {
    int max_y, max_x;
    int maxwin_y, maxwin_x;
    start_color();

    getmaxyx(stdscr, max_y, max_x);

    WINDOW *wind = newwin(50, 100, 15, (max_x - 100) / 2);

    refresh();
    box(wind, 0, 0);
    getmaxyx(wind, maxwin_y, maxwin_x);
    wborder(wind, 'H', 'H', '=', '=', '+', '+', '+', '+');
                
    mvwvline(wind, 1, maxwin_x / 6, 'X', (maxwin_y / 4) + 6);
    mvwhline(wind, maxwin_y / 2, 1, 'X', maxwin_x / 2);
    mvwvline(wind, maxwin_y / 4, maxwin_x / 2, 'X', maxwin_y / 2);
    mvwhline(wind, (maxwin_y / 2) + 8, maxwin_x / 6, 'X', maxwin_x / 4);
    mvwvline(wind, (maxwin_y / 2) + 8, maxwin_x / 4, 'X', 16);
    mvwvline(wind, 1, ((maxwin_x / 2) + 8) + (maxwin_x / 6), 'X', maxwin_y / 3);
    mvwvline(wind, (maxwin_y / 2) + 4, (maxwin_x / 2) + 12, 'X', 20);
    mvwvline(wind, (maxwin_y / 2) + 4, ((maxwin_x / 2) + 8) + (maxwin_x / 6), 'X', 10);
    mvwhline(wind, (maxwin_y / 2) + 14, ((maxwin_x / 2) + 8) + (maxwin_x / 6), 'X', 25);

    return wind;
}
