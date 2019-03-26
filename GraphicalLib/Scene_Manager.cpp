#include "Scene_Manager.h"



Scene_Manager::Scene_Manager(sf::RenderWindow *window) : scene_count(1), current_scene(0), current_scene_check(0), close(false)
{
	this->window = window;
	this->scene = new Main_Menu();
}


Scene_Manager::~Scene_Manager()
{
	if (this->scene != nullptr && !this->close)
		delete this->scene;
}

void Scene_Manager::update(float & dt)
{
	if (this->current_scene != this->current_scene_check)
	{
		if (this->scene != nullptr)
			delete this->scene;
		if (this->current_scene >= 0 && this->current_scene < this->scene_count)
			this->current_scene_check = this->current_scene;
		else
			close = true;
	}
	else
		this->scene->update(dt, this->current_scene, *this->window);
}

void Scene_Manager::render()
{
	if (close)
		this->window->close();
	else
		this->scene->render(*this->window);
}
