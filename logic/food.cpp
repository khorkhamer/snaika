#include "../entities.h"


Coordinate *Food::getCoordinate()
{
    return &coordinate;
}



void Food::setCoordinate(int x, int y)
{
    coordinate.x = x;
    coordinate.y = y;
}
