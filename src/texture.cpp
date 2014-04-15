#include <cassert>
#include "texture.hpp"

namespace spaceships
{
namespace gfx
{
template<typename T>
T next_power_of_two(T value)
{
    if((value & (value-1)) == 0)
        return value;
    value -= 1;
    for (size_t i = 1; i < sizeof(T) * 8; i <<= 1)
        value = value | value >> i;
    return value + 1;
}

texture* texture_from_surface(SDL_Surface* surface)
{
    simple_texture* tex = new simple_texture(surface->w, surface->h);
    tex->init_from_surface(surface);
    return tex;
}

texture* texture::get_slice(int x, int y, int width, int height)
{
    return new texture_slice(this, x, y, width, height);
}

simple_texture::simple_texture(int width, int height)
{
    id_ = 0;
    width_ = width;
    height_ = height;

    if (SDL_GL_ExtensionSupported("GL_ARB_texture_non_power_of_two"))
    {
        stored_width_ = width_;
        stored_height_ = height_;
    }
    else
    {
        stored_width_ = next_power_of_two(width_);
        stored_height_ = next_power_of_two(height_);
    }
}

simple_texture::~simple_texture()
{
    if (id_)
        glDeleteTextures(1, &id_);
}

void simple_texture::init_from_surface(SDL_Surface* surface)
{
    assert(surface->w == width_ && surface->h == height_);

    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    GLenum format;
    switch (surface->format->BytesPerPixel)
    {
    case 4:
        format = (surface->format->Rmask == 0x000000ff) ? GL_RGBA : GL_BGRA;
        break;
    case 3:
        format = (surface->format->Rmask == 0x000000ff) ? GL_RGB : GL_BGR;
        break;
    default:
        assert(false);
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, stored_width_, stored_height_,
                 0, format, GL_UNSIGNED_BYTE, surface->pixels);
}

texture_slice::texture_slice(texture* parent, int x, int y, int width, int height)
{
    parent_ = parent;
    offset_x_ = x;
    offset_y_ = y;
    width_ = width;
    height_ = height;
}
} // namespace gfx
} // namespace spaceships
