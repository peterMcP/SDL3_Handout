#ifndef __ModuleTextures_H__
#define __ModuleTextures_H__

#include "Module.h"
#include "Globals.h"

#define MAX_TEXTURES 50

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);

public:
	SDL_Texture * textures[MAX_TEXTURES] = { nullptr }; //TODO 5: initialize all values to nullptr
};

#endif // __ModuleTextures_H__