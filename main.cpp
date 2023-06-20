#include <iostream>
#include <ncursesw/ncurses.h>
#include <cstdlib>
#include "snake.h"
#include "maprender.h"
#include <unistd.h>

using namespace std;

void init()
{
    initscr();
    start_color();
    init_pair(0,COLOR_BLACK,COLOR_BLACK); //space
    init_pair(1,COLOR_WHITE,COLOR_WHITE); //wall
    init_pair(2,COLOR_RED,COLOR_RED); //imune wall
    init_pair(99,COLOR_WHITE,COLOR_BLACK); //void
    init_pair(17,COLOR_BLACK,COLOR_MAGENTA); //snkae body
}

int main()
{
    snake Snake;
    //Clock clock();
    init();
    while(true)
    {
        Snake.update();
        realtimerender();
        if(Snake.getAlive() == false)
        {
            break;
        }
        sleep(0.4);
    }
    getch();
    endwin();
    return 0;
}