#include "paddle.h"

Paddle::Paddle(bool isPlayer, float xlim, float ylim)
        : isPlayer(isPlayer), xlim(xlim), ylim(ylim),
          shape(sf::Vector2f(15.0f, 100.0f))
{
    if(isPlayer)
    {
        shape.setFillColor(sf::Color::Cyan);
        shape.setPosition(xlim - shape.getSize().x, (ylim / 2.f - shape.getSize().y));
    }
    else
    {
        shape.setFillColor(sf::Color::White);
        shape.setPosition(0.f, ylim / 2.f - shape.getSize().y);
    }
    paddleSpeed = 5.f;

}

void Paddle::handleEvent(sf::Event event)
{
    // dont do anything if this is not the plaer
    if (!isPlayer)
        return;
    if (event.type == sf::Event::KeyPressed)
    {
        // move player paddle if within bound of window
        if ((event.key.code == sf::Keyboard::Up) && (shape.getPosition().y - paddleSpeed > 0.f ))
            shape.move(0.f, -paddleSpeed);
        else if ((event.key.code == sf::Keyboard::Down) 
                && (shape.getPosition().y + shape.getSize().y + paddleSpeed < ylim))
            shape.move(0.f, paddleSpeed);
    }
}

void Paddle::update(sf::Vector2f ballPos)
{
    // update computer's paddle position based on balls position
    if ((shape.getPosition().y < ballPos.y) 
        && (shape.getPosition().y + shape.getSize().y + paddleSpeed < ylim)) {
        shape.move(0, paddleSpeed);
    } else if ((shape.getPosition().y > ballPos.y) 
        && (shape.getPosition().y - paddleSpeed > 0)) {
        shape.move(0, -paddleSpeed);
    }
}

sf::FloatRect Paddle::getBoundingBox() const
{
    return shape.getGlobalBounds();
}