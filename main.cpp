#include "entities.h"



using namespace sf;



int main()
{
    srand(static_cast<unsigned int>(time(0)));
    RenderWindow window(VideoMode(440, 500), "Snaika", Style::Titlebar | Style::Close);
    Event event;
    float timer = 0, delay = 155.5, time;
    Clock clock;
    Game game(20, 20);
    Mode mode(&window, &game);
    Painter painter(400, &window);
    User user(&window, &event, &mode);
    window.setFramerateLimit(60);
    while(window.isOpen()){
        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        timer += time;
        window.clear(Color::Cyan);
        mode.setUserAction(user.getDirection());                                                    //controller
        painter.draw(game.externalConter, game.foodCounter, mode.getModeFlag(),
                game.snake->getBody(), game.snake->getSnakeLength(), game.food->getCoordinate());   //view
        window.display();
        if(timer > delay){
            mode.run();                                                                             //logic
            timer = 0;
        }


    }
    return 0;
}
