#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>


using namespace sf;



enum class Direction
{
    up,
    right,
    down,
    left,
    Null
};



struct Coordinate
{
    int x;
    int y;
};



class Food
{
    private:


        Coordinate coordinate;

    public:

        Coordinate *getCoordinate();
        void setCoordinate(int x, int y);
};



class Snake
{
    private:
        Coordinate *body;
        Coordinate head;
        Direction direction;
        int maxSnakeSize;
        int snakeLength;
        bool moveFlag;

        void removeTail();
        void setHead();

    public:
        bool isThereInBody(int x, int y);
        Coordinate *getBody();
        Coordinate *getHead();
        Direction getDirection();
        void update();
        int getSnakeLength();
        bool getMoveFlag();
        Direction getCurrentDirection();
        void setDirection(Direction dir);
        bool isBittingHimself();
        void turnMoveFlag();
        void calculateHead();
        void move();
        Snake();
        ~Snake();
};



class Game
{
    private:
        int wSize;
        int hSize;

        int growFlag;
        void reduceGrowFlag();
        void setGrowFlag();
        bool isCollidingWithFood();
        bool isCollidingWithWall();
        void finishEating();

    public:

        Snake *snake;
        Food *food;
        int foodCounter = 0;
        int externalConter = 0;

        void restart();
        void generateFood();
        void turnSnake(Direction direction);
        bool isOver();
        void iterate();
        Game(int width, int height);
        ~Game();
};



class Resource
{
    public:
        Texture hUp, hRight, hDown, hLeft,
                tUp, tRight, tDown, tLeft,
                body, bodyH,
                rightUp, downRight, leftDown, upLeft,
                background, foodBack, food, menu;

        Resource();
};



class Painter
{
    private:
        std::ostringstream out;
        RenderWindow *window;
        Resource resource;
        Text text;
        Font font;
        Sprite *map;
        Sprite head;
        Sprite tail;
        Sprite food;
        Sprite background;
        Sprite foodBack;
        Sprite menu;
        int mapLength = 0;
        int maxSnakeSize;


        void translate(Sprite *s);
        void drawBackground(int foodCounter);
        void drawFood(Coordinate *food);
        void updateMap(Coordinate *snakeBody, int len);
        void drawSnake();
        void drawMenu(int externalConter);

    public:

        void draw(int externalConter, int foodCounter, bool modeFlag, Coordinate *snakeBody, int snakeLength, Coordinate *food);
        Painter(int size, RenderWindow *win);
        ~Painter();
};


class Mode
{
    private:
        RenderWindow *window;
        Game *game;
        bool modeFlag = false;


    public:


        bool getModeFlag();
        void setUserAction(Direction direction);
        void run();
        void turn();
        Mode(RenderWindow *win, Game *g);

};




class User
{
    private:
        RenderWindow *window;
        Event *event;
        Mode *mode;

    public:

        Direction getDirection();
        User(RenderWindow *win, Event *ev, Mode *m);
};
