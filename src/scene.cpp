#include "scene.hpp"

namespace spaceships
{
namespace gfx
{
scene::scene()
{
}
scene::~scene()
{
    for (std::map<std::string, renderable*>::iterator it = renderables_.begin(); it != renderables_.end(); ++it)
        if(it->second != NULL)
            delete it->second;
    renderables_.clear();
}

void scene::add(const std::string& name, renderable* object)
{
    renderables_.insert(std::pair<std::string, renderable*>(name, object));
}
void scene::handle_logic(const float& dtime)
{

}
void scene::draw()
{
    for (std::map<std::string, renderable*>::iterator it = renderables_.begin(); it != renderables_.end(); ++it)
        it->second->draw();
}
} // namespace gfx
} // namespace spaceships
