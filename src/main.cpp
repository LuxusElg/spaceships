#include "game.hpp"

int main( int argc, char* args[] )
{
    spaceships::game* game_ptr = new spaceships::game();
    game_ptr->init();
    delete game_ptr;
	return 0;
}
