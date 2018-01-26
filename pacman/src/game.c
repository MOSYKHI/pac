#include <stdio.h>
#include "game.h"
#include "physics.h"


void initiateGame(char* filename, Map* outMap, Game* outGame, Pacman* outPacman, Ghost* outGhosts) {
    // fill me
    outGame->ghosts=4;//initialize ghost numbers
    outPacman->dir=DIR_NONE;//define first state of pacman:not moving !!!
    outGame->cheeses=0;//first initialization
    outGame->cherries=0;//first initialization
    outGame->pineapples=0;//first initialization
    FILE *my_file=fopen("/home/mosy/Desktop/96106088/pacman/cmake-build-debug/res/map.txt","r");//set the file address

    fscanf(my_file,"%d%d\n",&outMap->height,&outMap->width);//scan width and height of map


    //scanning the map
    fscanf(my_file,"\n");
    for (int i = 0; i < outMap->height ; ++i) {
        for (int j = 0; j < outMap->width; ++j) {
            fscanf(my_file,"%c",&outMap->cells[j][i]);

            switch (outMap->cells[j][i]) {
                case CELL_CHEESE: {
                    outGame->cheeses++;
                    break;
                }
                case CELL_CHERRY:{
                    outGame->cherries++;
                    break;}
                case CELL_PINEAPPLE:{
                    outGame->pineapples++;
                    break;
                }

            }

        }
        fscanf(my_file,"\n");
    }//scanning the map




    fscanf(my_file,"%d",&outGame->score);//scan the score

    fscanf(my_file,"%*s %d %d (%d,%d) (%lf,%lf)",&outPacman->dir,&outPacman->health,&outPacman->startX,&outPacman->startY,&outPacman->x,&outPacman->y);//scan pacman information


    outGhosts[0].type=BLINKY;//set first ghost type
    outGhosts[1].type=PINKY;//set second ghost type
    outGhosts[2].type=CLYDE;//set third ghost type
    outGhosts[3].type=INKY;//set fourth ghost type



//set ghosts information
    for (int k = 0; k <MAX_GHOST_COUNT; ++k) {
        outGhosts[k].blueCounterDown=0;
        fscanf(my_file,"%*s %d %d ",&outGhosts[k].dir,&outGhosts[k].blue);

        if (outGhosts[k].blue==true){fscanf(my_file,"%lld ",&outGhosts[k].blueCounterDown);outGhosts[k].blueCounterDown*=CYCLES_PER_SEC;}


        fscanf(my_file," (%d,%d) (%lf,%lf)",&outGhosts[k].startX,&outGhosts[k].startY,&outGhosts[k].x,&outGhosts[k].y);


        outGhosts[k].speed=GHOST_DEFAULT_SPEED;

    }//set ghosts information




    outPacman->speed=PACMAN_DEFAULT_SPEED;
    fclose(my_file);
}//end initiateGame function


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//checkEatables : check for eatable objects in each cycle.....
void checkEatables(Map* map, Game* outGame, Pacman* outPacman, Ghost* outGhosts) {
    // fill me

    if ((outPacman->x-(int)outPacman->x)*(outPacman->x-(int)outPacman->x)<0.25&&(outPacman->y-(int)outPacman->y)*(outPacman->y-(int)outPacman->y)<0.25) {
        if (map->cells[(int) outPacman->x][(int) outPacman->y] == CELL_CHEESE) {
            map->cells[(int) outPacman->x][(int) outPacman->y] = CELL_EMPTY;
            outGame->score += CHEESE_SCORE;
            outGame->cheeses--;
        } else if (map->cells[(int) outPacman->x][(int) outPacman->y] == CELL_CHERRY) {
            map->cells[(int) outPacman->x][(int) outPacman->y] = CELL_EMPTY;
            outGame->score += CHERRY_SCORE;
            outGame->cherries--;
        } else if (map->cells[(int) outPacman->x][(int) outPacman->y] == CELL_PINEAPPLE) {
            map->cells[(int) outPacman->x][(int) outPacman->y] = CELL_EMPTY;
            outGame->score += PINEAPPLE_SCORE;
            outGame->pineapples--;
            for (int i = 0; i < MAX_GHOST_COUNT; ++i) {
                if (outGhosts[i].blue == true) {
                    outGhosts[i].blueCounterDown = BLUE_DURATION * 2;

                } else {
                    outGhosts[i].blue = true;
                    outGhosts[i].blueCounterDown = BLUE_DURATION;

                }
            }

        }

    }
}
//end of checkEatables function


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//begin of checkghostcollison : check the possible results for facing pacman and a ghost
void checkGhostCollision(Pacman* outPacman, Ghost* outGhost) {
    // fill me
  if ((outGhost->x-outPacman->x)*(outGhost->x-outPacman->x)+(outGhost->y-outPacman->y)*(outGhost->y-outPacman->y)<=0.25)
  {
      if (outGhost->blue==true)
      {
          outGhost->x=outGhost->startX;
          outGhost->y=outGhost->startY;
          //missing the score of eating ghost
          outGhost->blue=false;
      }
      else
      {
          outPacman->x=outPacman->startX;
          outPacman->y=outPacman->startY;
          outPacman->health--;
          outPacman->dir=DIR_NONE;
      }
  }
}
//end of checkghostcollison func


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//begin of isgamefinished : check the end of game
bool isGameFinished(Game* game, Pacman* pacman) {

    if (pacman->health==0||(game->cheeses==0&&game->cherries==0))
    {
        return true;
    }
    else {
        return false;
    }

}
//end of isgamefinished func


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//begin of checkghoststate : check and update ghosts state
void checkGhostState(Ghost* ghost) {

    // fill me
    if(ghost->blueCounterDown>0)
    {
        ghost->blueCounterDown--;
    }
    else
    {
        ghost->blue=false;
    }

}
//end of checkghoststate func
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

