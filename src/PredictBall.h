#ifndef PREDICTBALL_H
#define PREDICTBALL_H

#include <SFML/Graphics.hpp>

class PredictBall : public sf::CircleShape
{
public:
	PredictBall(const float &radius, const sf::Vector2f &position);
	virtual ~PredictBall(){}

	void predictLastXPosition(const sf::Vector2f &vector, const float &GRAVITY);
};

#endif PREDICTBALL_H