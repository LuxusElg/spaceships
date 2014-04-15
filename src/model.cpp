#include "model.hpp"

namespace spaceships
{
namespace gfx
{
model::model()
{
}
model::~model()
{
}

void model::add_vertices(const std::vector<vec3f>& vertices)
{
    for (std::vector<vec3f>::const_iterator it = vertices.begin(); it != vertices.end(); ++it)
        vertices_.push_back(*it);
}
void model::add_tex_coords(const std::vector<vec2f>& tex_coords)
{
    for (std::vector<vec2f>::const_iterator it = tex_coords.begin(); it != tex_coords.end(); ++it)
        tex_coords_.push_back(*it);
}
void model::load_texture(const std::string& path)
{
    SDL_Surface* img = IMG_Load(path.c_str());
    texture_ = gfx::texture_from_surface(img);
    SDL_FreeSurface(img);
}
void model::draw()
{
    glBegin(GL_QUADS);
    for (unsigned i = 0; i < vertices_.size(); ++i)
    {
        glVertex3f(vertices_[i].x, vertices_[i].y, vertices_[i].z);
    }
    glEnd();
}
bool model::init(GLuint program)
{
    return true;
}
}
}
