#include "Ball.h"





Ball::Ball(const float &radius, const sf::Vector2f &position, const sf::Vector2f &velocity):
	sf::CircleShape(radius),
	velocity(velocity),
	startVelocity(velocity),
	startPosition(position)
{
	setPosition(position);
	setOrigin(radius, radius);
}


