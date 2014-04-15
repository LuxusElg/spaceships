#ifndef GAME_STATE_HPP_
#define GAME_STATE_HPP_

#include <SDL.h>

namespace spaceships
{
class game_state
{
private:

public:
    game_state() {};
    virtual ~game_state() {};

    virtual void handle_events(const SDL_Event& event) = 0;
    virtual void handle_logic(const float& dtime) = 0;
    virtual void draw() = 0;
};
} // namespace spaceships
#endif // GAME_STATE_HPP_
