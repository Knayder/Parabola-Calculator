#include <SFML/Graphics.hpp>
#include "ParabolaCalculator.h"

using namespace std;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tytul", sf::Style::Default, settings);

	ParabolaCalculator parabolaCalculator(window);

	parabolaCalculator.run();

	return 0;
}