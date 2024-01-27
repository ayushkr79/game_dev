#include "ball.h"

Ball::Ball(float x, float y, float xlim, float ylim) : xlim(xlim), ylim(ylim)
{
    shape.setRadius(10.0f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
    velocity = sf::Vector2f(0.01, 0.01);

}

sf::FloatRect Ball::getBoundingBox() const
{
    return shape.getGlobalBounds();
}

void Ball::update()
{
    // update shape's position based on velocity
    shape.move(velocity);
    float x = shape.getPosition().x;
    float y = shape.getPosition().y;
    if ((y + 2.*shape.getRadius() > ylim) || (y < 0.f))
        velocity.y = -velocity.y;
    if ((x + 2.*shape.getRadius() > xlim) || (x < 0.f))
        shape.setPosition(xlim / 2.f, ylim / 2.f);
}


void Ball::handlePaddleCollision()
{
    velocity.x = -velocity.x;
}