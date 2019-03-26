#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

#include "Main_Menu.h"

class Scene_Manager
{
private:
	sf::RenderWindow *window;

	Scene *scene;
	int scene_count;
	int current_scene; //index of current scene
	int current_scene_check; //index of scene at previous frame

	bool close; //if true, closes the window
public:
	Scene_Manager(sf::RenderWindow *window);
	virtual ~Scene_Manager();

	void update(float &dt);
	void render();
};

#endif

