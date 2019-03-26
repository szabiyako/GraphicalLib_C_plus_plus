#include "Window.h"

//Initialazers
void Window::InitWindow()
{
	std::ifstream input("configs/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned short int framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (input.is_open())
	{
		std::getline(input, title);
		input >> window_bounds.width >> window_bounds.height;
		input >> framerate_limit >> vertical_sync_enabled;
	}

	input.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Window::InitSFMLevent()
{
	this->sfEvent = new sf::Event();
}

void Window::InitClock()
{
	this->dtClock = new sf::Clock();
}

void Window::InitFPS()
{
	this->fps = new FPS("resources/fonts/arial.ttf");
}

void Window::InitScene_Manager()
{
	this->scene_manager = new Scene_Manager(this->window);
}

//Constructor/destructor
Window::Window() : dt(0)
{
	this->InitWindow();
	this->InitSFMLevent();
	this->InitClock();
	this->InitFPS();
	this->InitScene_Manager();
}

//Functions
Window::~Window()
{
	delete this->window;
	delete this->dtClock;
	delete this->fps;
	delete this->sfEvent;
	delete this->scene_manager;
}

void Window::updateDt()
{
	this->dt = dtClock->restart().asSeconds();
}

void Window::updateSFMLevents()
{
	while (this->window->pollEvent(*this->sfEvent))
	{
		if (this->sfEvent->type == sf::Event::Closed)
			this->window->close();
	}
}

void Window::update()
{
	this->updateSFMLevents();
	this->scene_manager->update(this->dt);
	this->fps->setFpsSmooth(this->dt);
}

void Window::render()
{
	this->window->clear();

	//Render BEGIN

	this->scene_manager->render();

	#ifdef FPS_RENDER_ON
		this->fps->render(*this->window);
	#endif
	//Render END

	this->window->display();
}

void Window::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
