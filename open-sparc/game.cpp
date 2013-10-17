#include "video.h"
#include "game.h"

Game::Game()
{
    //ctor
}

void Game::tick(Video* video)
{
    video->lookRelative(1, LOOK_DOWN);
}

Game::~Game()
{
    //dtor
}
