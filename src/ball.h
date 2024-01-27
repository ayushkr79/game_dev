#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(float x, float y, float xlim, float ylim);
    sf::FloatRect getBoundingBox() const;
    void update();
    sf::CircleShape getShape() const {return shape;};
    void handlePaddleCollision();
    sf::Vector2f getPosition() const {return shape.getPosition(); };

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    // window boundary
    float xlim, ylim;



};