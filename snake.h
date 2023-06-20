#include <queue>
#include <iostream>
#include <stdlib.h>
#include <ncursesw/ncurses.h>
#include "maprender.h"
#include "makeitem.h"
using namespace std;

class snake
{
    queue<int> x; //front가 tail, back이 head
    queue<int> y;
    int size;
    char direction; // l r u d 각각 LEFT RIGHT UP DOWN
    int sizechange;
    bool alive;
    public:
        snake()
        {
            x.push(14); y.push(12);
            x.push(13); y.push(12);
            x.push(12); y.push(12); //push쪽 수정
            size = 3;
            direction = 'u';
            sizechange = 0;
            alive = true;
            map[12][12] = 17;
            map[13][12] = 17;
            map[14][12] = 17;
        }
        void update(); //  main의 루프마다 작동/ 키입력부터 대부분의 작동을 처리
        void move();// collision 확인 후 이동

        bool getAlive(){return alive;}
};

void snake::update()
{
    int inputkey;
    if(kbhit())
    {
        inputkey = _getch();
        switch (inputkey)
        {
        case 75:
            if (direction != 'r')
            {
                direction = 'l';
            }
            else
                alive = false;
            break;
        case 77:
            if (direction != 'l')
            {
                direction = 'r';
            }
            else
                alive = false;
            break;
        case 72:
            if (direction != 'd')
            {
                direction = 'u';
            }
            else
                alive = false;
            break;
        case 80:
            if (direction != 'u')
            {
                direction = 'd';
            }
            else
                alive = false;
            break;
        }
    }
    int tempx = x.back();
    int tempy = y.back();
    if(size < 3){alive = false;}
    if(alive == true)
    {
        //head의 이동위치 저장
        if (direction == 'l')
        {
            tempx = x.back(); tempy = y.back()- 1;
        }
        else if (direction == 'r')
        {
            tempx = x.back(); tempy = y.back() + 1;
        }
        else if (direction == 'u')
        {
            tempx = x.back() - 1; tempy = y.back();
        }
        else if (direction == 'd')
        {
            tempx = x.back() + 1; tempy = y.back();
        }
        //새로운 head의 위치에 gate item 등이 있는지 확인
        if(map[tempx][tempy] == 0){}
        else if(map[tempx][tempy] < 3) // 1or2
        {
            alive = false;
        }
        else if(map[tempx][tempy] == 5)
        {
            //미구현 4단계 때 구현예정 gate
        }
        else if(map[tempx][tempy] == 8) //grow item
        {
            sizechange = 1;
        }
        else if(map[tempx][tempy] == 9)
        {
            sizechange = -1;
        }
        //sizechage가 0,1일때 snake의 이동 구현
        if (sizechange == 1)
        {
            size++;
            sizechange = 0;
            makeitem(8);
        }
        else
        {
            map[x.front()][y.front()] = 0;
            x.pop(); y.pop(); 
        }
        if(sizechange == -1)
        {
            size--;
            map[x.front()][y.front()] = 0;
            x.pop(); y.pop(); 
            sizechange = 0;
            makeitem(9);
        }
        x.push(tempx); y.push(tempy);
        map[tempx][tempy] = 17;
    }

}
void snake::move()
{

}