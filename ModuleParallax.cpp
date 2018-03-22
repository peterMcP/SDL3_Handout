#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleParallax.h"

#include "SDL\include\SDL.h"


/*struct parallaxValues //testing
{
	int x, y;
	int speed = 3;
	int offset;
	SDL_Rect dsrect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
} p; //create default p struct at init*/

ModuleParallax::ModuleParallax() : Module()
{
	//int xPos = 0;
	//int speed = 3;
	
}

ModuleParallax::~ModuleParallax()
{
	//destructor
}

bool ModuleParallax::Init()
{
	App->textures->Load("bg.png");
	App->textures->Load("mg.png");
	App->textures->Load("fg.png");
	
	//parallaxValues* p;

	/*p.bgWidth = new int;
	p.offset = new int;
	*p.offset = 291; //clip bg*/

	//stores background width
	SDL_QueryTexture(App->textures->textures[1], nullptr, nullptr, &p.bgWidth, nullptr);
	
	//dynamic memory
	/*p.bgSpeed = new int;
	p.bgLastPosX = new int;
	p.mgSpeed = new int;
	p.mgLastPosX = new int;
	p.fgSpeed = new int;
	p.fgLastPosX = new int;*/
	//defines
	p.bgLastPosX = 0;
	p.fgLastPosX = 0;
	p.mgLastPosX = 0;
	
	//defines scroll speeds
	p.bgSpeed = 1;
	p.mgSpeed = 2;
	p.fgSpeed = 3;
	
	//defines destination Rect - testing
	dsrect = new SDL_Rect;
	dsrect->h = SCREEN_HEIGHT;
	dsrect->w = SCREEN_WIDTH;
	dsrect->x = 0;
	dsrect->y = 0;

	//defines other bg/fg/md textures positions
	//*mgSpeed = *mgLastPosX = 0;

	return true;
}


update_status ModuleParallax::Update()
{

	dsrect->x = p.bgLastPosX;
	dsrect->x -= p.bgSpeed;
	if (dsrect->x <= (-512)) dsrect->x = 0; //loop //512 = offset until texture repeats
	//textures[1,2,3] = homework | textures[0] is TODO10
	//Draw tile1 BG1
	App->render->Blit(App->textures->textures[1],dsrect->x, dsrect->y, nullptr);
	//stores last posX
	p.bgLastPosX = dsrect->x;
	//draw second tile BG2
	App->render->Blit(App->textures->textures[1], dsrect->x + (p.bgWidth - p.offset), dsrect->y, nullptr);
	
	//mg
	dsrect->x = p.mgLastPosX;
	dsrect->x -= p.mgSpeed;
	App->render->Blit(App->textures->textures[2], dsrect->x, 30, nullptr);
	p.mgLastPosX = dsrect->x;
	
	//foreground
	dsrect->x = p.fgLastPosX;
	dsrect->x -= p.fgSpeed;
	App->render->Blit(App->textures->textures[3], dsrect->x , 0, nullptr);
	p.fgLastPosX = dsrect->x;

	return update_status::UPDATE_CONTINUE;
}

bool ModuleParallax::CleanUp()
{
	//delete &p;
	//destro
	return true;
}

