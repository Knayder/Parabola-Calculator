#include "PredictBall.h"



PredictBall::PredictBall(const float &radius, const sf::Vector2f &position):
	sf::CircleShape(radius)
{
	setPosition(position);
	setOrigin(radius, radius);
}

void PredictBall::predictLastXPosition(const sf::Vector2f &vector, const float &GRAVITY)
{
	float vectorLenght = sqrt(vector.x*vector.x + vector.y*vector.y);

	float x = vectorLenght * vectorLenght * sin(
		2 * asin(abs(vector.y) / vectorLenght)
		) / GRAVITY;
	setPosition(x, getPosition().y);
}


//
//float x =
//vectorLength * vectorLength * sin(
//	2 * std::asin(std::abs(deltaMouse.y) / vectorLength)
//	)
//	/ GRAVITY;