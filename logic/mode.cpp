#include "../entities.h"



bool Mode::getModeFlag()
{
    return modeFlag;
}



void Mode::setUserAction(Direction direction)
{
    game->turnSnake(direction);
}



void Mode::run()
{
    if(modeFlag){
        game->iterate();
        if(game->isOver()){
            turn();
            game->externalConter = game->foodCounter;
            game->restart();
        }
    }
}


void Mode::turn()
{
    if(modeFlag)
        modeFlag = false;
    else
        modeFlag = true;
}



Mode::Mode(RenderWindow *win, Game *g)
{
    window = win;
    game = g;
}
