#ifndef GFX_RENDERABLE_HPP_
#define GFX_RENDERABLE_HPP_

#include <SDL_opengl.h>

namespace spaceships
{
namespace gfx
{
class renderable
{
protected:
    renderable() {};

public:
    virtual ~renderable() {};
    virtual void draw() = 0;
    virtual bool init(GLuint program = 0) = 0;
};
} // namespace gfx
} // namespace spaceships

#endif // GFX_RENDERABLE_HPP_
