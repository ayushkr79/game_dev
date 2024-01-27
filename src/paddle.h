#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{

public:
    Paddle(bool isPlayer, float xlim, float ylim);

    void handleEvent(sf::Event event);
    sf::RectangleShape getShape() const {return shape;};
    sf::FloatRect getBoundingBox() const;
    void update(sf::Vector2f ballPos);


private:
    sf::RectangleShape shape;
    bool isPlayer;
    float paddleSpeed;
    // boundary of window
    float xlim;
    float ylim;

};