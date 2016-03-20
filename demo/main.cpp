#include "../include/age_system.h"
#include <../include/age_scene.h>
#include <../include/age_eventmgr.h>
#include <../include/age_sprite.h>
#include <../include/age_lua.h>

#include "game.h"
lua_State *L;
int main(int argc, char *argv[])
{
    ASystem::Init (argc,argv);
	Game::Init ();
    return ASystem::Go();
}
