#include "../entities.h"



int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}




void Game::turnSnake(Direction direction)
{
    if(direction == Direction::up && !(snake->getCurrentDirection() == Direction::down))
        snake->setDirection(Direction::up);
    else if(direction == Direction::right && !(snake->getCurrentDirection() == Direction::left))
        snake->setDirection(Direction::right);
    else if(direction == Direction::down && !(snake->getCurrentDirection() == Direction::up))
        snake->setDirection(Direction::down);
    else if(direction == Direction::left && !(snake->getCurrentDirection() == Direction::right))
        snake->setDirection(Direction::left);
}




bool Game::isCollidingWithFood()
{
    return (snake->getHead()->x == food->getCoordinate()->x)
        && (snake->getHead()->y == food->getCoordinate()->y);
};



bool Game::isCollidingWithWall()
{
    return snake->getHead()->x < 1 || snake->getHead()->y < 1
        || snake->getHead()->x > wSize || snake->getHead()->x > hSize
        || snake->getHead()->y > wSize || snake->getHead()->y > hSize;
}



bool Game::isOver()
{
    return isCollidingWithWall() || snake->isBittingHimself();
}




void Game::finishEating()
{
    if(growFlag == 0 && !snake->getMoveFlag())
        snake->turnMoveFlag();
}



void Game::reduceGrowFlag()
{
    if(growFlag == 0)
        return;
    growFlag--;
}



void Game::setGrowFlag()
{
    growFlag = 2;
}


void Game::iterate()
{
    reduceGrowFlag();
    snake->calculateHead();
    if(isCollidingWithFood()){
        snake->turnMoveFlag();
        setGrowFlag();
        generateFood();
        foodCounter++;
    }
    snake->move();
    finishEating();
}


void Game::restart()
{
    snake->update();
    foodCounter = 0;
}



void Game::generateFood()
{
    int x = getRandomNumber(1, 20), y = getRandomNumber(1, 20);
    if(snake->isThereInBody(x, y)){
        x = abs(x - 21);
        y = abs(y - 21);
    }
    while(snake->isThereInBody(x, y)){
        x = getRandomNumber(1, 20);
        y = getRandomNumber(1, 20);
    }
    food->setCoordinate(x, y);
}




Game::Game(int width, int height)
{
    snake = new Snake();
    food = new Food();
    food->setCoordinate(19, 19);
    wSize = width;
    hSize = height;
}



Game::~Game()
{
    delete snake;
    delete food;
}
