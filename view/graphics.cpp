#include "../entities.h"




using namespace sf;



Resource::Resource()
{
    hUp.loadFromFile("view/images/headUp.png");
    hRight.loadFromFile("view/images/headRight.png");
    hDown.loadFromFile("view/images/headDown.png");
    hLeft.loadFromFile("view/images/headLeft.png");
    tUp.loadFromFile("view/images/tailUp.png");
    tRight.loadFromFile("view/images/tailRight.png");
    tDown.loadFromFile("view/images/tailDown.png");
    tLeft.loadFromFile("view/images/tailLeft.png");
    body.loadFromFile("view/images/body1.png");
    bodyH.loadFromFile("view/images/body2.png");
    rightUp.loadFromFile("view/images/rightUp.png");
    downRight.loadFromFile("view/images/downRight.png");
    leftDown.loadFromFile("view/images/leftDown.png");
    upLeft.loadFromFile("view/images/upLeft.png");
    food.loadFromFile("view/images/food.png");
    background.loadFromFile("view/images/background.png");
    foodBack.loadFromFile("view/images/foodBack.png");
    menu.loadFromFile("view/images/menu.png");
}



void Painter::translate(Sprite *s)
{
    s->setPosition(s->getPosition().x * 20, s->getPosition().y * 20);
}




void Painter::updateMap(Coordinate *snakeBody, int len)
{
    int length = 0;
    int i = len - 1;
    head.setPosition(snakeBody[i].x, snakeBody[i].y);
    translate(&head);
    if(snakeBody[i].x == snakeBody[i-1].x){
        if(snakeBody[i].y > snakeBody[i-1].y)
            head.setTexture(resource.hDown);
        else
            head.setTexture(resource.hUp);
    } else if(snakeBody[i].y == snakeBody[i-1].y){
        if(snakeBody[i].x > snakeBody[i-1].x)
            head.setTexture(resource.hRight);
        else
            head.setTexture(resource.hLeft);
    } i--;

    for(; i > 0; i--){
        map[length].setPosition(snakeBody[i].x, snakeBody[i].y);
        translate(map+length);
        if(snakeBody[i].x == snakeBody[i+1].x && snakeBody[i].x == snakeBody[i-1].x)
            map[length].setTexture(resource.body);
        else if(snakeBody[i].y == snakeBody[i+1].y && snakeBody[i].y == snakeBody[i-1].y)
            map[length].setTexture(resource.bodyH);

        else if((snakeBody[i].y < snakeBody[i-1].y && snakeBody[i].x > snakeBody[i+1].x)
                || (snakeBody[i].y < snakeBody[i+1].y && snakeBody[i].x > snakeBody[i-1].x))
            map[length].setTexture(resource.upLeft);

        else if((snakeBody[i].y < snakeBody[i+1].y && snakeBody[i].x < snakeBody[i-1].x)
                || (snakeBody[i].y < snakeBody[i-1].y && snakeBody[i].x < snakeBody[i+1].x))
            map[length].setTexture(resource.leftDown);

        else if((snakeBody[i].y > snakeBody[i-1].y && snakeBody[i].x < snakeBody[i+1].x)
                || (snakeBody[i].y > snakeBody[i+1].y && snakeBody[i].x < snakeBody[i-1].x))
            map[length].setTexture(resource.downRight);

//      else if(snakeBody[i].y > snakeBody[i+1].y && snakeBody[i].x > snakeBody[i-1].x)
        else
            map[length].setTexture(resource.rightUp);
        length++;
    }
    tail.setPosition(snakeBody[i].x, snakeBody[i].y);
    translate(&tail);
    if(snakeBody[i].x == snakeBody[i+1].x){
        if(snakeBody[i].y > snakeBody[i+1].y)
            tail.setTexture(resource.tUp);
        else
            tail.setTexture(resource.tDown);
    } else if(snakeBody[i].y == snakeBody[i+1].y){
        if(snakeBody[i].x > snakeBody[i+1].x)
            tail.setTexture(resource.tLeft);
        else
            tail.setTexture(resource.tRight);
    }
    mapLength = length;
    length = 0;
}





void Painter::drawSnake()
{
    window->draw(head);
    window->draw(tail);
    for(int i = 0; i < mapLength; i++)
        window->draw(map[i]);
}



void Painter::drawFood(Coordinate *f)
{
    food.setPosition(f->x, f->y);
    translate(&food);
    window->draw(food);
}



void Painter::drawBackground(int foodCounter)
{
    out.str("");
    out.clear();
    out << "x " << foodCounter;
    text.setString(out.str());
    window->draw(background);
    window->draw(foodBack);
    window->draw(text);
}



void Painter::drawMenu(int externalConter)
{
    out.str("");
    out.clear();
    out << "x " << externalConter;
    text.setString(out.str());
    window->draw(foodBack);
    window->draw(text);
    window->draw(menu);
}



void Painter::draw(int externalConter, int foodCounter, bool modeFlag, Coordinate *snakeBody, int snakeLength, Coordinate *food)
{
    if(modeFlag){
        updateMap(snakeBody, snakeLength);
        drawBackground(foodCounter);
        drawSnake();
        drawFood(food);
    } else {
        drawMenu(externalConter);
    }
}



Painter::Painter(int size, RenderWindow *win)
{
    map = new Sprite[size];
    maxSnakeSize = size;
    window = win;
    food.setTexture(resource.food);
    font.loadFromFile("view/fonts/f.ttf");
    foodBack.setTexture(resource.foodBack);
    foodBack.setPosition(160, 430);
    background.setTexture(resource.background);
    background.setPosition(20, 20);
    menu.setTexture(resource.menu);
    menu.setPosition(0, 0);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Black);
    text.setPosition(225, 440);

}



Painter::~Painter()
{
    delete[] map;
}
