#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void update(float &dt, int &current_scene, sf::RenderWindow &window) = 0;
	virtual void render(sf::RenderTarget &window) = 0;
};

#endif

