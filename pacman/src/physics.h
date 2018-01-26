#ifndef __PHYSICS_H
#define __PHYSICS_H

#include "game.h"
#include "input.h"

typedef struct {

    int x;
    int y;

}Point;

#define PACMAN_DEFAULT_SPEED 4.
#define GHOST_DEFAULT_SPEED 4.




// TO WRITE
int mod(int a,int b);

Direction shortestPath(Map *map, Point on, Point to);

int specificPoint(Pacman *pacman,int distance,Map *map);


Direction pacmanlastMove(Map *map,Pacman* pacman,Action lastAction);

Direction decidePacman(const Map* map, Pacman* pacman, Action action);


// TO WRITE
Direction decideGhost(const Map* map, Ghost* ,Pacman *pacman,Ghost *blinky);
#endif