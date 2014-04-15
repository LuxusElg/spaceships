#ifndef GAME_HPP_
#define GAME_HPP_

#include <SDL.h>
#include <SDL_opengl.h>

#include "game_state.hpp"

namespace spaceships
{
class game
{
private:
    const int SCREEN_WIDTH_;
    const int SCREEN_HEIGHT_;
    const int MAJOR_VERSION_;
    const int MINOR_VERSION_;
    const float FOV_;

    SDL_Window* window_ptr_;
    SDL_GLContext context_;

    game_state* active_state_;

    void run_game();

public:
    game();
    ~game();
    void init();
};
} // namespace spaceships

#endif // GAME_HPP_
