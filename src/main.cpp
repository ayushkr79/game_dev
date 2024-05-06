#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"

int main(int argc, char const *argv[])
{
    // Render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Game");

    // define game components
    // create paddles
    Paddle paddleComp(false, window.getSize().x, window.getSize().y);
    Paddle paddlePlayer(true, window.getSize().x, window.getSize().y);
    Ball ball(window.getSize().x/2., 
              window.getSize().y/2.,
              window.getSize().x,
              window.getSize().y);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            paddlePlayer.handleEvent(event);
            paddleComp.handleEvent(event);
        }
        ball.update();
        paddleComp.update(ball.getPosition());
        if ((ball.getBoundingBox().intersects(paddleComp.getBoundingBox())) 
            || (ball.getBoundingBox().intersects(paddlePlayer.getBoundingBox())))
        {
            ball.handlePaddleCollision();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(paddleComp.getShape());
        window.draw(paddlePlayer.getShape());
        window.draw(ball.getShape());
        // end the current frame
        window.display();
    }
    return 0;
}