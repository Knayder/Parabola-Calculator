#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
private:
	sf::Vector2f velocity;
	sf::Vector2f startVelocity;
	sf::Vector2f startPosition;
public:
	Ball(const float &radius, const sf::Vector2f &position,  const sf::Vector2f &velocity);
	void move(const float &deltaTime){ sf::CircleShape::move(velocity*deltaTime);}
	virtual ~Ball(){}

	sf::Vector2f getVelocity() { return velocity; }
	sf::Vector2f getStartVelocity() { return startVelocity; }
	sf::Vector2f getStartPosition() { return startPosition; }

	void addToVelocity(const sf::Vector2f &offset) { velocity += offset; }
	void setVelocity(const sf::Vector2f &value) { velocity = startVelocity = value; }
};

#endif BALL_H