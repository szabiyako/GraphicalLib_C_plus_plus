#include "Button.h"


Button::Button(sf::Texture * texture, sf::IntRect Position, sf::IntRect Position_Cursor) : image(true), isPressed(false)
{
	this->texture = texture;
	this->button = new sf::Sprite();
	this->button->setTexture(*this->texture);
	this->pos = Position;
	this->pos_cursor = Position_Cursor;
	this->button->setTextureRect(this->pos);

	//For invisible button
	if (this->texture == nullptr)
		image = false;
}

Button::Button(sf::Texture * texture, sf::IntRect Position, sf::IntRect Position_Cursor, sf::Vector2f coords) : image(true), isPressed(false)
{
	this->texture = texture;
	this->button = new sf::Sprite();
	this->button->setTexture(*this->texture);
	this->pos = Position;
	this->pos_cursor = Position_Cursor;
	this->button->setTextureRect(this->pos);
	this->button->setPosition(coords);

	//For invisible button
	if (this->texture == nullptr)
		image = false;
}

Button::~Button()
{
	delete this->button;
}

bool Button::isClicked(sf::RenderWindow &window)
{
	sf::Vector2i cursor = sf::Mouse::getPosition(window);
	sf::FloatRect b = this->button->getGlobalBounds();

	if (cursor.x >= b.left && cursor.x <= b.width + b.left &&
		cursor.y >= b.top && cursor.y <= b.height + b.top)
	{
		this->button->setTextureRect(this->pos_cursor);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->isPressed)
			this->isPressed = true;
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isPressed)
		{
			this->isPressed = false;
			return true;
		}
	}
	else
	{
		this->isPressed = false;
		this->button->setTextureRect(this->pos);
	}

	return false;
}

void Button::render(sf::RenderTarget & window)
{
	if (this->image)
		window.draw(*this->button);
}

