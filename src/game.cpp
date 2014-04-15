#include <cmath>

#include "game.hpp"
#include "combat_state.hpp"

namespace spaceships
{
void game::run_game()
{
    active_state_ = new combat_state();
    SDL_Event e;
    bool quit = false;
    float dtime = 0.f;
    uint32_t ticks = 0;
    // temporary loop code
    while (!quit)
    {
        dtime = (SDL_GetTicks() - ticks)/1000.f;
        ticks = SDL_GetTicks();

        while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else
			{
			    active_state_->handle_events(e);
			}
		}
		active_state_->handle_logic(dtime);

		glClear(GL_COLOR_BUFFER_BIT);
		active_state_->draw();
		SDL_GL_SwapWindow(window_ptr_);
    }

    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = NULL;
    SDL_Quit();
}
game::game() :  SCREEN_WIDTH_(640),
                SCREEN_HEIGHT_(480),
                MAJOR_VERSION_(2),
                MINOR_VERSION_(1),
                FOV_(45.0f)
{
}
game::~game()
{
}
void game::init()
{
    // no error handling yet, because fuck you
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION_);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION_);

    window_ptr_ = SDL_CreateWindow("Spaceships",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH_,
                                   SCREEN_HEIGHT_,
                                   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    context_ = SDL_GL_CreateContext(window_ptr_);

    // set vsync
    SDL_GL_SetSwapInterval(1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double frustum_h = std::tan((FOV_ / 360.f) * 3.141592653589793238463) * 0.1f;
    double frustum_w = frustum_h * (static_cast<float>(SCREEN_WIDTH_)/static_cast<float>(SCREEN_HEIGHT_));
    glFrustum(-frustum_w, frustum_w, -frustum_h, frustum_h, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // assuming everything above went OK, run game
    run_game();
}
} // namespace spaceships
