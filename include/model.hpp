#ifndef GFX_MODEL_HPP_
#define GFX_MODEL_HPP_

#include <vector>
#include <string>
#include "renderable.hpp"
#include "texture.hpp"

namespace spaceships
{
namespace gfx
{
struct vec3f
{
    float x, y, z;
    vec3f(float xval, float yval, float zval) : x(xval), y(yval), z(zval) {};
};
struct vec2f
{
    float x, y;
    vec2f(float xval, float yval) : x(xval), y(yval) {};
};
class model : public renderable
{
private:
    std::vector<vec3f> vertices_;
    std::vector<vec2f> tex_coords_;
    gfx::texture* texture_;

public:
    model();
    ~model();

    // temporary functions until model loading gets implemented
    void add_vertices(const std::vector<vec3f>& vertices);
    void add_tex_coords(const std::vector<vec2f>& tex_coords);

    void load_texture(const std::string& path);

    virtual void draw();
    virtual bool init(GLuint program = 0);
};
} // namespace gfx
} // namespace spaceships

#endif // GFX_MODEL_HPP_
