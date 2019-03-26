#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Scene.h"

#include "Button.h"

class Main_Menu :
	public Scene
{
private:
	sf::Texture *texture;
	sf::Sprite *background;

	Button *button_play;
	Button *button_settings;
	Button *button_exit;
public:
	void InitTexture();
	void InitBackground();
	void InitButtons();
	Main_Menu();
	virtual ~Main_Menu();

	void update(float &dt, int &current_scene, sf::RenderWindow &window);
	void render(sf::RenderTarget &window);
};

#endif