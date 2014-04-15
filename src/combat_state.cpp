#include <SDL_opengl.h>
#include "combat_state.hpp"
#include "model.hpp"

namespace spaceships
{
combat_state::combat_state()
{
    gfx::model* testcube = new gfx::model();
    std::vector<gfx::vec3f> verts;
    // front
    verts.push_back(gfx::vec3f(1.0f, 1.0f, 1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, 1.0f));
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, 1.0f));
    verts.push_back(gfx::vec3f(1.0f, -1.0f, 1.0f));

    // left
    verts.push_back(gfx::vec3f(1.0f, 1.0f, -1.0f));
    verts.push_back(gfx::vec3f(1.0f, 1.0f, 1.0f));
    verts.push_back(gfx::vec3f(1.0f, -1.0f, 1.0f));
    verts.push_back(gfx::vec3f(1.0f, -1.0f, -1.0f));

    // back
    verts.push_back(gfx::vec3f(1.0f, 1.0f, -1.0f));
    verts.push_back(gfx::vec3f(1.0f, -1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, -1.0f));

    // right
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, 1.0f));
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, 1.0f));

    // bottom
    verts.push_back(gfx::vec3f(1.0f, -1.0f, 1.0f));
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, 1.0f));
    verts.push_back(gfx::vec3f(-1.0f, -1.0f, -1.0f));
    verts.push_back(gfx::vec3f(1.0f, -1.0f, -1.0f));

    // top
    verts.push_back(gfx::vec3f(1.0f, 1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, -1.0f));
    verts.push_back(gfx::vec3f(-1.0f, 1.0f, 1.0f));
    verts.push_back(gfx::vec3f(1.0f, 1.0f, 1.0f));
    testcube->add_vertices(verts);

    scene_ = new gfx::scene();
    scene_->add("testcube", testcube);

    rot_ = 0.0f;
}
combat_state::~combat_state()
{
    if (scene_ != NULL)
        delete scene_;
}
void combat_state::handle_events(const SDL_Event& event)
{

}
void combat_state::handle_logic(const float& dtime)
{
    rot_ += (90*dtime);
    scene_->handle_logic(dtime);
}
void combat_state::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rot_, 0.0f, 1.0f, 0.0f);

    scene_->draw();
}
} // namespace spaceships
