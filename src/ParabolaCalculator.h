#ifndef PARABOLACALCULATOR_H
#define PARABOLACALCULATOR_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "PredictBall.h"

class ParabolaCalculator
{
private:
	sf::RenderWindow &window;

	sf::Color backgroundColor;

	sf::Clock displayClock;
	sf::Clock simulationClock;

	unsigned const int MAX_DISPLAY_FPS;
	unsigned const int MAX_SIMULATION_FPS;

	const float GRAVITY;

	Ball ball;
	PredictBall predictBall;

	sf::RectangleShape floor;

	void display(float deltaTime);
	void simulate(float deltaTime);

public:
	ParabolaCalculator(sf::RenderWindow &window);
	virtual ~ParabolaCalculator(){}
	void run();
	void input();
};

#endif PARABOLACALCULATOR_H
