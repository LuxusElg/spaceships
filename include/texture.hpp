#ifndef GFX_TEXTURE_HPP_
#define GFX_TEXTURE_HPP_

#include <SDL_opengl.h>
#include <SDL_image.h>

namespace spaceships
{
namespace gfx
{
class texture;
texture* texture_from_surface(SDL_Surface* surface);

class texture
{
public:
    virtual ~texture() {}
    virtual GLuint get_id() const = 0;
    virtual int get_width() const = 0;
    virtual int get_height() const = 0;
    virtual int get_stored_width() const = 0;
    virtual int get_stored_height() const = 0;
    virtual int get_offset_x() const = 0;
    virtual int get_offset_y() const = 0;
    virtual const texture* get_parent() const = 0;

    texture* get_slice(int x, int y, int width, int height);
};

class simple_texture : public texture
{
private:
    GLuint id_;
    int width_;
    int height_;
    int stored_width_;
    int stored_height_;

public:
    simple_texture(int width, int height);
    ~simple_texture();

    GLuint get_id() const { return id_; }
    int get_width() const { return width_; }
    int get_height() const { return height_; }
    int get_stored_width() const { return stored_width_; }
    int get_stored_height() const { return stored_height_; }
    int get_offset_x() const { return 0; }
    int get_offset_y() const { return 0; }
    const texture* get_parent() const { return NULL; }
    void init_from_surface(SDL_Surface* surface);
};

class texture_slice : public texture
{
private:
    texture* parent_;
    int offset_x_;
    int offset_y_;
    int width_;
    int height_;

public:
    texture_slice(texture* parent, int x, int y, int width, int height);
    GLuint get_id() const { return parent_->get_id(); }
    int get_width() const { return width_; }
    int get_height() const { return height_; }
    int get_stored_width() const { return parent_->get_stored_width(); }
    int get_stored_height() const { return parent_->get_stored_height(); }
    int get_offset_x() const { return offset_x_; }
    int get_offset_y() const { return offset_y_; }
    const texture* get_parent() const { return parent_; }
};
} // namespace gfx
} // namespace spaceships

#endif // GFX_TEXTURE_HPP_
