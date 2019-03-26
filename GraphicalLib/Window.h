#ifndef WINDOW_H
#define WINDOW_H

#include "Scene_Manager.h"

//For window settings from file
#include <fstream>
#include <string>

#include "DeltaTime.h"
#include "FPS.h"

//For fps render, to turn off comment out line below
#define FPS_RENDER_ON

//To show console comment out line below
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


class Window
{
private:
	//Vars
	sf::RenderWindow *window;
	sf::Event *sfEvent;
	sf::Clock *dtClock;
	float dt;
	FPS *fps;
	Scene_Manager *scene_manager;

	//Initialazers
	void InitWindow();
	void InitSFMLevent();
	void InitClock();
	void InitFPS();
	void InitScene_Manager();
public:
	Window();
	virtual ~Window();

	//Functions
	void updateDt();
	void updateSFMLevents();
	void update();
	void render();
	void run();
};

#endif
