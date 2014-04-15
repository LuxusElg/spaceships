#ifndef COMBAT_STATE_HPP_
#define COMBAT_STATE_HPP_

#include "game_state.hpp"
#include "scene.hpp"

namespace spaceships
{
class combat_state: public game_state
{
private:
    gfx::scene* scene_;
    float rot_;

public:
    combat_state();
    ~combat_state();

    virtual void handle_events(const SDL_Event& event);
    virtual void handle_logic(const float& dtime);
    virtual void draw();
};
} // namespace spaceships
#endif // COMBAT_STATE_HPP_
