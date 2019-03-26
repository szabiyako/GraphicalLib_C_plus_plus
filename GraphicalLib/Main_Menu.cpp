#include "Main_Menu.h"



void Main_Menu::InitTexture()
{
	this->texture = new sf::Texture();
	this->texture->loadFromFile("resources/textures/Main_Menu/Main_Menu_MegaTexture.png");
}

void Main_Menu::InitBackground()
{
	this->background = new sf::Sprite();
	this->background->setTexture(*this->texture);
	this->background->setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->background->setPosition(0.f, 0.f);
}

void Main_Menu::InitButtons()
{
	this->button_play = new Button(this->texture, sf::IntRect(1280, 0, 370, 60), sf::IntRect(1280, 60, 370, 60), sf::Vector2f(75.f, 250.f));
	this->button_settings = new Button(this->texture, sf::IntRect(1280, 120, 370, 60), sf::IntRect(1280, 180, 370, 60), sf::Vector2f(75.f, 350.f));
	this->button_exit = new Button(this->texture, sf::IntRect(1280, 240, 370, 60), sf::IntRect(1280, 300, 370, 60), sf::Vector2f(75.f, 450.f));
}

Main_Menu::Main_Menu()
{
	this->InitTexture();
	this->InitBackground();
	this->InitButtons();
}


Main_Menu::~Main_Menu()
{
	delete this->background;

	delete this->button_play;
	delete this->button_settings;
	delete this->button_exit;

	delete this->texture;
}

void Main_Menu::update(float & dt, int &current_scene, sf::RenderWindow &window)
{
	if (this->button_play->isClicked(window))
		current_scene++;

	this->button_settings->isClicked(window);

	if (this->button_exit->isClicked(window))
		current_scene--;
}

void Main_Menu::render(sf::RenderTarget & window)
{
	window.draw(*this->background);
	this->button_play->render(window);
	this->button_settings->render(window);
	this->button_exit->render(window);
}
