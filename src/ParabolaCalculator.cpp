#include "ParabolaCalculator.h"
#include <thread>

#include <iostream>



ParabolaCalculator::ParabolaCalculator(sf::RenderWindow &window) :
	window(window),
	backgroundColor(37, 37, 48),
	MAX_DISPLAY_FPS(7),
	MAX_SIMULATION_FPS(240),
	GRAVITY(100),
	ball(5, {0,650}, {0,0}),
	predictBall(5, { 0,0 }),
	floor({1280, 5})

{
	ball.setFillColor(sf::Color(200, 100, 100));
	ball.setVelocity({200, -200}); //Set velocity

	floor.setPosition(ball.getStartPosition());
	floor.setFillColor(sf::Color(100, 200, 100, 100));

	predictBall.setPosition(0, ball.getStartPosition().y);
	predictBall.predictLastXPosition(ball.getStartVelocity(), GRAVITY);
	std::cout << predictBall.getPosition().x << std::endl;
	
}

void ParabolaCalculator::run() {
	while ( window.isOpen() ) {

		float deltaTime = displayClock.getElapsedTime().asSeconds();

		if (deltaTime >= 1.f / MAX_DISPLAY_FPS)
			display(deltaTime);

		deltaTime = simulationClock.getElapsedTime().asSeconds();

		if (deltaTime >= 1.f / MAX_SIMULATION_FPS)
			simulate(deltaTime);
		

	}
}

void ParabolaCalculator::input(){
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void ParabolaCalculator::display(float deltaTime) {
	input();
	window.clear(backgroundColor);

	window.draw(floor);
	window.draw(ball);
	window.draw(predictBall);

	window.display();
	displayClock.restart();
}

void ParabolaCalculator::simulate(float deltaTime) {
	ball.addToVelocity({ 0, GRAVITY * deltaTime });
	if(ball.getPosition().y < ball.getStartPosition().y || ball.getPosition().x <= ball.getStartPosition().x)
		ball.move(deltaTime);

	simulationClock.restart();
}


