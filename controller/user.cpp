#include "../entities.h"


Direction User::getDirection()
{
    if(mode->getModeFlag()){
        while(window->pollEvent(*event)){
            if(event->type == Event::Closed){
                window->close();
                break;
            } else if(event->type == Event::KeyPressed){
                if(event->key.code == Keyboard::Up)
                    return Direction::up;
                else if(event->key.code == Keyboard::Right)
                    return Direction::right;
                else if(event->key.code == Keyboard::Down)
                    return Direction::down;
                else if(event->key.code == Keyboard::Left)
                    return Direction::left;
                else if(event->key.code == Keyboard::Escape)
                    mode->turn();
            }
        } return Direction::Null;
    } else {
        while(window->pollEvent(*event)){
            if(event->type == Event::Closed){
                window->close();
                break;
            } else if(event->type == Event::MouseButtonPressed){
                if(event->mouseButton.button == Mouse::Left){
                    if(event->mouseButton.x >= 65 && event->mouseButton.x <= 390
                            && event->mouseButton.y >= 100 && event->mouseButton.y <= 223){
                        mode->turn();
                    }
                    else if(event->mouseButton.x >= 65 && event->mouseButton.x <= 390
                        && event->mouseButton.y >= 260 && event->mouseButton.y <= 380){
                        window->close();
                    }
                }
            }
        }
    } return Direction::Null;
}


User::User(RenderWindow *win, Event *ev, Mode *m)
{
    window = win;
    event = ev;
    mode = m;
}
