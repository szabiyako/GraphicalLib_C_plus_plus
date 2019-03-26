#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class Button
{
protected:
	sf::Texture *texture;
	sf::Sprite *button;
	sf::IntRect pos; //Position on texture
	sf::IntRect pos_cursor; //Position on texture when cursor is on button

	bool image; //true if text dont used

	bool isPressed;
public:
	//Graphical consructors
	Button(sf::Texture *texture, sf::IntRect Position, sf::IntRect Position_Cursor);
	Button(sf::Texture *texture, sf::IntRect Position, sf::IntRect Position_Cursor, sf::Vector2f coords);

	virtual ~Button();

	/*=================================================**
	**Button logic, return true if pressed and released**
	**=================================================*/
	bool isClicked(sf::RenderWindow &window);

	void render(sf::RenderTarget &window);
};

#endif

