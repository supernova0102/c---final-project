#include <iostream>
#include <stdlib.h>
#include "maprender.h"
#include <ctime>


void makeitem(int index)
{
    srand(time(NULL));
    int temp = rand()%625;
    int tempx = temp/25;
    int tempy = temp%25;
    while(map[tempx+1][tempy+1] != 0)
    {
        temp = (temp + 1)%625;
        tempx = temp/25;
        tempy = temp%25;
    }
    map[tempx+1][tempy+1] = index;
}