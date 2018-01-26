#include <stdlib.h>
#include <time.h>
#include "physics.h"
#include "game.h"
#include "map.h"
#include <math.h>

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
int mod(int a,int b)
{
    if(a<0)
    {
        return -1*((-1*a)%b);
    }
    else
    {
        return a%b;
    }
}

Direction shortestPath(Map *map, Point on, Point to) {
    int x = map->width;
    int y = map->height;
    Point* queue = malloc(sizeof(Point*) * x * y);
    int front = 0;
    int back = 1;
    Direction way[x][y];
    bool visited[x][y];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            visited[i][j] = map->cells[i][j] == CELL_BLOCK;
            way[i][j] = DIR_NONE;
        }
    }
    visited[on.x][on.y] = true;
    way[mod(on.x - 1,x)][on.y] = DIR_LEFT;
    way[mod(on.x + 1,x)][on.y] = DIR_RIGHT;
    way[on.x][mod(on.y - 1,y)] = DIR_UP;
    way[on.x][mod(on.y + 1,y)] = DIR_DOWN;
    queue[0] = on;
    while (back > front) {
        // success condition
        if (queue[front].x==to.x&&queue[front].y== to.y) {
            break;
        }
        // removing
        Point parent = queue[front];
        visited[parent.x][parent.y] = true;
        front++;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i * j != 0) continue;
                if (!visited[mod(parent.x + i,x)][mod(parent.y + j,y)]) {
                    Point new = {mod(parent.x + i,x), mod(parent.y + j,y)};
                    queue[back++] = new;
                    if (front > 1) {
                        int a = mod(parent.x + i,x);
                        int b = mod(parent.y + j,y);
                        way[a][b] = way[parent.x][parent.y];
                    }
                }
            }
        }
    }
    return way[queue[front].x][queue[front].y];
}

/////////////////////////////////////////////////
int specificPoint(Pacman *pacman,int distance,Map *map)
{
    int x=0,y=0;

    switch (pacman->dir) {
        case DIR_UP:{
            x=(int)pacman->x;
            y=mod((int) (pacman->y - distance), map->height);
            break;
        }
        case DIR_RIGHT:{
            y=(int)pacman->y;
            x=mod((int) (pacman->x + distance), map->width);
            break;
        }
        case DIR_DOWN:{
            x=(int)pacman->x;
            y=mod((int) (pacman->y + distance), map->height);
            break;
        }
        case DIR_LEFT:{
            y=(int)pacman->y;
            x=mod((int) (pacman->x - distance), map->width);
            break;
        }
    }
    return y*map->width+x;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



Direction pacmanlastMove(Map *map,Pacman* pacman,Action lastAction)//this function checks if one direction is not available try last move direction
{
    if(lastAction==ACTION_UP)
    {
        if(pacman->y==0&&map->cells[(int)pacman->x][map->height-1]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else if(map->cells[(int)pacman->x][(int)pacman->y-1]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else {

            pacman->dir=DIR_UP;
            return pacman->dir;
        }
    }
    else if(lastAction==ACTION_DOWN)
    {
        if(pacman->y==map->height-1&&map->cells[(int)pacman->x][0]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else if(map->cells[(int)pacman->x][(int)pacman->y+1]==CELL_BLOCK){

            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else{
            pacman->dir=DIR_DOWN;
            return pacman->dir;
        }
    }
    else if (lastAction==ACTION_LEFT)
    {
        if(pacman->x==0&&map->cells[map->width-1][(int)pacman->y]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else if(map->cells[(int)pacman->x-1][(int)pacman->y]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else{
            pacman->dir=DIR_LEFT;
            return pacman->dir;
        }
    }
    else if(lastAction==ACTION_RIGHT)
    {
        if(pacman->x==map->width-1&&map->cells[0][(int)pacman->y]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else if(map->cells[(int)pacman->x+1][(int)pacman->y]==CELL_BLOCK){
            pacman->dir=DIR_NONE;
            return pacman->dir;
        }
        else{
            pacman->dir=DIR_RIGHT;
            return pacman->dir;
        }
    }
    return pacman->dir;


}

Action lastAction;//last pacman action
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Direction decideGhost(const Map* map, Ghost* ghost,Pacman *pacman,Ghost *blinky) {


    Point ghpPoint;
    ghpPoint.x=(int)ghost->x;
    ghpPoint.y=(int)ghost->y;

    Point ghstartPoint;
    ghstartPoint.x=ghost->startX;
    ghstartPoint.y=ghost->startY;

    Point pacmanP;
    pacmanP.x=(int)pacman->x;
    pacmanP.y=(int)pacman->y;

    if(ghost->blue)/////////////////////////////////////////blue condition//////////////////////////////////////////////
    {


            return shortestPath((Map *) map, ghpPoint, ghstartPoint);

    }///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else {
        if (ghost->type == BLINKY)///////////////////////////////////////////blinky plan////////////////////////////////
        {

            return shortestPath((Map *) map, ghpPoint, pacmanP);

        } else if (ghost->type == PINKY)/////////////////////////////////////pinky plan/////////////////////////////////
        {
            Point pinkypoints[5];
            for (int i = 0; i < 5; ++i) {
                pinkypoints[i].x = specificPoint(pacman, i, (Map *) map) % map->width;
                pinkypoints[i].y = specificPoint(pacman, i, (Map *) map) / map->width;
            }
            int j;
            for (j = 0; j < 5; ++j) {
                if (map->cells[pinkypoints[j].x][pinkypoints[j].y] == CELL_BLOCK) {
                    return shortestPath((Map *) map, ghpPoint, pinkypoints[j - 1]);
                }
            }
            if (j == 5) {
                return shortestPath((Map *) map, ghpPoint, pinkypoints[4]);
            }

        } else if (ghost->type == INKY)////////////////////////////////////inky plan////////////////////////////////////
        {
            int x = specificPoint(pacman, 2, (Map *) map) % map->width;
            int y = specificPoint(pacman, 2, (Map *) map) / map->width;

            Point inkyPoints;

            inkyPoints.x = (int) (2 * x - blinky->x + map->width) % map->width;
            inkyPoints.y = (int) (2 * y - blinky->y + map->height) % map->height;

            if (map->cells[inkyPoints.x][inkyPoints.y] != CELL_BLOCK) {
                return shortestPath((Map *) map, ghpPoint, inkyPoints);
            } else {
                for (int i = 0; i < 1;) {
                    srand(time(0));
                    int randDir = rand() % 4 + 1;
                    if (randDir == DIR_RIGHT) {
                        if (map->cells[(int) (ghost->x + 1) % map->width][(int) ghost->y] != CELL_BLOCK) {
                            return DIR_RIGHT;

                        }
                    } else if (randDir == DIR_LEFT) {
                        if (map->cells[(int) (ghost->x - 1 + map->width) % map->width][(int) ghost->y] != CELL_BLOCK) {
                            return DIR_LEFT;

                        }
                    } else if (randDir == DIR_UP) {
                        if (map->cells[(int) ghost->x][(int) (ghost->y - 1 + map->height) % map->height] !=
                            CELL_BLOCK) {
                            return DIR_UP;

                        }
                    } else {
                        if (map->cells[(int) ghost->x][(int) (ghost->y + 1) % map->height] != CELL_BLOCK) {
                            return DIR_DOWN;

                        }
                    }

                }


            }
        } else//////////////////////////////////////////////////clyde plan////////////////////////////////////////////////////
        {
            if (abs((int) (ghost->x - pacman->x)) > 8) {
                return shortestPath((Map *) map, ghpPoint, pacmanP);
            } else {
                if (map->cells[0][map->height-1] != CELL_BLOCK) {

                    Point clydepoint;
                    clydepoint.x=0;
                    clydepoint.y=map->height-1;
                    return shortestPath((Map *) map, ghpPoint, clydepoint);
                } else {
                    for (int i = 0; i < 1;) {
                        srand(time(0));
                        int randDir = rand() % 4 + 1;
                        if (randDir == DIR_RIGHT) {
                            if (map->cells[(int) (ghost->x + 1) % map->width][(int) ghost->y] != CELL_BLOCK) {
                                return DIR_RIGHT;

                            }
                        } else if (randDir == DIR_LEFT) {
                            if (map->cells[(int) (ghost->x - 1 + map->width) % map->width][(int) ghost->y] !=
                                CELL_BLOCK) {
                                return DIR_LEFT;

                            }
                        } else if (randDir == DIR_UP) {
                            if (map->cells[(int) ghost->x][(int) (ghost->y - 1 + map->height) % map->height] !=
                                CELL_BLOCK) {
                                return DIR_UP;

                            }
                        } else {
                            if (map->cells[(int) ghost->x][(int) (ghost->y + 1) % map->height] != CELL_BLOCK) {
                                return DIR_DOWN;

                            }
                        }

                    }
                }

            }
        }
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




Direction decidePacman(const Map* map, Pacman* pacman, Action action) {
    // fill me


    //check all possible conditions
    if(action==ACTION_UP)
    {
        if(pacman->y==0&&map->cells[(int)pacman->x][map->height-1]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else if(map->cells[(int)pacman->x][(int)pacman->y-1]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else {
            lastAction=ACTION_UP;
            pacman->dir=DIR_UP;
            return pacman->dir;
        }
    }
    else if(action==ACTION_DOWN)
    {
        if(pacman->y==map->height-1&&map->cells[(int)pacman->x][0]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else if(map->cells[(int)pacman->x][(int)pacman->y+1]==CELL_BLOCK){

            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else{
            lastAction=ACTION_DOWN;
            pacman->dir=DIR_DOWN;
            return pacman->dir;

        }
    }
    else if (action==ACTION_LEFT)
    {
        if(pacman->x==0&&map->cells[map->width-1][(int)pacman->y]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else if(map->cells[(int)pacman->x-1][(int)pacman->y]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else{
            lastAction=ACTION_LEFT;
            pacman->dir=DIR_LEFT;
            return pacman->dir;
        }
    }
    else if(action==ACTION_RIGHT)
    {
        if(pacman->x==map->width-1&&map->cells[0][(int)pacman->y]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else if(map->cells[(int)pacman->x+1][(int)pacman->y]==CELL_BLOCK){
            return pacmanlastMove((Map *) map, pacman, lastAction);
        }
        else{
            lastAction=ACTION_RIGHT;
            pacman->dir=DIR_RIGHT;
            return pacman->dir;
        }
    }
    //check all possible conditions


    /*else if (action==ACTION_PAUSE)
    {

    }
    else if (action==ACTION_IDLE)
    {

    }
    else if (action==ACTION_EXIT)
    {

    }
     */
    return pacman->dir;


}
