#include <iostream>
#include <thread>
#include <ncurses.h>

#include "definitions.h"

int main() {
    initscr();
    //TODO: check if stdscr appropriate for app window dimensions

    if (not has_colors()) {
        printw("Terminal doesn't support color. Exiting...");
        refresh();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(3s);
        }

        return 1;
    }

    /* Color Pairings */

    start_color();
    init_pair(INVERTEDCOLORING, COLOR_BLACK, COLOR_WHITE);

    /***/

    int height, width, start_x, start_y;
    height = 10;
    width = 80;
    start_x = start_y = 0;

    WINDOW * win = newwin(height, width, start_y, start_x);
    WINDOW * innerbox = newwin(height - 2, width - 2, start_y + 1, start_x + 1);


#define REMINDER \
    ! Remember to insert all windows in the Windows vector !
    std::vector<WINDOW *> * Windows = new std::vector<WINDOW *>();
    Windows->push_back(win);
    Windows->push_back(innerbox);

    box(win, 0, 0);
    box(innerbox, 0, 1);
    refresh();
    int input_code;
    curs_set(0);

    while (input_code = wgetch(win)) {
        if (input_code == '\n') {
            move(1, 2);
            attron(A_STANDOUT);
            wclear(innerbox);
            box(innerbox, 0, 1);
            printw("TEST");
            attroff(A_STANDOUT);
        }
        for (auto w : *Windows) {
            wrefresh(w);
        }
    }
    endwin();
}

//TODO: learn how to do menus
//TODO: check how to move items and perform other actions on filesystems
//TODO: check online for fs wrapper
//TODO: try to think of a way to properly do argcheck and two frontends/interfaces

