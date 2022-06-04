#include "gamer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../engine/gamer_manager.h"
#include "../engine/sprite_manager.h"

#define SPRITE_TILES_GAMER 256 + 48

// Global variable.
struct_gamer_object global_gamer_object;

void engine_gamer_manager_init(unsigned char px, unsigned char py, unsigned char vel, unsigned int tile)
{
	struct_gamer_object *go = &global_gamer_object;
	go->gamerX = px;
	go->gamerY = py;
	go->velocity = vel;
	go->tile = tile;
}

void engine_gamer_manager_update(char dx, char dy)
{
	struct_gamer_object *go = &global_gamer_object;
	go->gamerX += dx * go->velocity;
	go->gamerY += dy * go->velocity;
}

void engine_gamer_manager_draw()
{
	struct_gamer_object *go = &global_gamer_object;
	engine_sprite_manager_draw(go->gamerX, go->gamerY, SPRITE_TILES_GAMER);
}
