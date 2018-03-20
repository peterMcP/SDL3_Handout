#pragma once
#ifndef __ModuleParallax_H__
#define __ModuleParallax_H__

#include "Module.h"

struct SDL_Rect;

class ModuleParallax : public Module
{
public:

	int* bgSpeed = nullptr;
	int* bgLastPosX = nullptr;
	int* bgWidth = nullptr;
	int* mgSpeed = nullptr;
	int* mgLastPosX = nullptr;
	int* fgSpeed = nullptr;
	int* fgLastPosX = nullptr;
	int* offset = nullptr;

	//struct parallaxValues;

	ModuleParallax();
	~ModuleParallax();

	bool Init();
	update_status Update();

public:
	SDL_Rect* dsrect = nullptr;
};

#endif // !__ModuleParallax_H__

