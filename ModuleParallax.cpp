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
	
	bgWidth = new int;
	offset = new int;
	*offset = 291; //clip bg

	//stores background width
	SDL_QueryTexture(App->textures->textures[1], nullptr, nullptr, bgWidth, nullptr);
	
	//dynamic memory
	bgSpeed = new int;
	bgLastPosX = new int;
	mgSpeed = new int;
	mgLastPosX = new int;
	fgSpeed = new int;
	fgLastPosX = new int;
	//defines
	*fgLastPosX = 0;
	*mgLastPosX = 0;
	
	//defines scroll speeds
	*bgSpeed = 1;
	*mgSpeed = 2;
	*fgSpeed = 3;
	
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
	dsrect->x = *bgLastPosX;
	dsrect->x -= *bgSpeed;
	if (dsrect->x <= (-512)) dsrect->x = 0; //loop //512 = offset until texture repeats
	//textures[1] = homework | textures[0] is TODO10
	//Draw tile1 BG1
	App->render->Blit(App->textures->textures[1],dsrect->x, dsrect->y, nullptr);
	//stores last posX
	*bgLastPosX = dsrect->x;
	//draw second tile BG2
	App->render->Blit(App->textures->textures[1], dsrect->x + (*bgWidth - *offset), dsrect->y, nullptr);
	
	//mg
	dsrect->x = *mgLastPosX;
	dsrect->x -= *mgSpeed;
	App->render->Blit(App->textures->textures[2], dsrect->x, 30, nullptr);
	*mgLastPosX = dsrect->x;
	
	//foreground
	dsrect->x = *fgLastPosX;
	dsrect->x -= *fgSpeed;
	App->render->Blit(App->textures->textures[3], dsrect->x , 0, nullptr);
	*fgLastPosX = dsrect->x;

	return update_status::UPDATE_CONTINUE;
}

