#include "../entities.h"





void Snake::removeTail()
{
    int i;
    for(i = 0; i < maxSnakeSize-1; i++)
        body[i] = body[i+1];
    body[i].x = 0;
    body[i].y = 0;
    snakeLength--;
}



void Snake::setHead()
{
    if(snakeLength >= maxSnakeSize)
        return;
    body[snakeLength].x = head.x;
    body[snakeLength].y = head.y;
    snakeLength++;
}



bool Snake::isThereInBody(int x, int y)
{
    for(int i = 0; i < snakeLength; i++){
        if(x == body[i].x && y == body[i].y)
            return true;
    } return false;
}



Coordinate *Snake::getBody()
{
    return body;
}



Coordinate *Snake::getHead()
{
    return &head;
}


Direction Snake::getDirection()
{
    return direction;
}



int Snake::getSnakeLength()
{
    return snakeLength;
}



bool Snake::getMoveFlag()
{
    return moveFlag;
}



void Snake::setDirection(Direction dir)
{
    direction = dir;
}



bool Snake::isBittingHimself()
{
    for(int i = snakeLength - 2; i >= 0; i--){
        if(head.x == body[i].x && head.y == body[i].y)
            return true;
    } return false;
}



void Snake::turnMoveFlag()
{
    if(moveFlag)
        moveFlag = false;
    else
        moveFlag = true;
}



void Snake::calculateHead()
{
    switch(direction){
        case Direction::up:
            head.y--;
            break;
        case Direction::right:
            head.x++;
            break;
        case Direction::down:
            head.y++;
            break;
        case Direction::left:
            head.x--;
        default:
            break;
    }
}


Direction Snake::getCurrentDirection()
{
    if(body[snakeLength-1].x == body[snakeLength-2].x){
        if(body[snakeLength-1].y > body[snakeLength-2].y)
            return Direction::down;
        else
            return Direction::up;
    }
    else {
        if(body[snakeLength-1].x > body[snakeLength-2].x)
            return Direction::right;
        else
            return Direction::left;
    }
}




void Snake::move()
{
    if(moveFlag)
        removeTail();
    setHead();
}


void Snake::update()
{
    direction = Direction::down;
    snakeLength = 3;
    moveFlag = true;
    head = { 6, 6 };
    body[0].x = 6;
    body[0].y = 4;
    body[1].x = 6;
    body[1].y = 5;
    body[2].x = 6;
    body[2].y = 6;
}



Snake::Snake()
{
    direction = Direction::down;
    snakeLength = 3;
    moveFlag = true;
    maxSnakeSize = 1000;
    body = new Coordinate[1000];
    head = { 6, 6 };
    body[0].x = 6;
    body[0].y = 4;
    body[1].x = 6;
    body[1].y = 5;
    body[2].x = 6;
    body[2].y = 6;
}



Snake::~Snake()
{
    delete[] body;
}
