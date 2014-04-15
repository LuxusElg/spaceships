#ifndef GFX_SCENE_HPP_
#define GFX_SCENE_HPP_

#include <map>
#include <string>

#include "renderable.hpp"

namespace spaceships
{
namespace gfx
{
class scene
{
private:
    std::map<std::string, renderable*> renderables_;

public:
    scene();
    ~scene();

    void add(const std::string& name, renderable* object);
    void handle_logic(const float& dtime);
    void draw();
};
} // namespace gfx
} // namespace spaceships

#endif // GFX_SCENE_HPP_
