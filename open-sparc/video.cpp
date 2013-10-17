#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include <cmath>
#include "video.h"

Video::Video(vec3 eye, vec3 center, vec3 up)
{
    _cameye = eye;
    _camcenter = center;
    _camup = up;

}

void Video::draw()
{
    glClearColor( 0.0, 0.0, 0.0, 0.0 ); // Farbe zum Löschen setzen
    glClearDepth(1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );     // Aktuellen Bildpuffer löschen

    glMatrixMode(GL_MODELVIEW);

    if(_viewdir.y > -0.02)
    {
        int i = 0;
    }
    mat4 mv = glm::lookAt(_cameye, _camcenter, _camup);

	glLoadMatrixf(&mv[0][0]);

    glCuboid(-1,0,-1,1,1,5);

    SDL_GL_SwapBuffers();
}

void Video::setViewMode(int mode)
{
    _viewmode = mode;
}
void Video::setViewPosition(vec3 pos)
{
    _viewpos = pos;
    switch(_viewmode)
    {
    case VIEW_EGO:
        _cameye = pos;
        _camcenter = pos + _viewdir;
        break;

    case VIEW_THIRD:
        _cameye = pos - (_viewdir * _viewdist);
        _camcenter = pos;
        break;
    }
}
void Video::setViewDir(vec3 dir)
{
    _viewdir = glm::normalize(dir);
    switch(_viewmode)
    {
    case VIEW_EGO:
        _camcenter = _viewpos + dir;
        break;

    case VIEW_THIRD:
        _cameye = _viewpos - (dir * _viewdist);
        break;
    }
}

void Video::setViewDistance(float dist)
{
    _viewdist = dist;
    switch(_viewmode)
    {
    case VIEW_EGO:
        break;

    case VIEW_THIRD:
        _cameye = _viewpos - (_viewdir * dist);
        break;
    }
}

void Video::moveRelative(float amount, int dir)
{
    vec3 newpos = vec3(0);
    vec3 temp;
    switch(dir)
    {
    case MOVE_FORWARD:
        newpos = _viewpos + amount * _viewdir;
        break;

    case MOVE_BACKWARD:
        newpos = _viewpos - amount * _viewdir;
        break;

    case MOVE_LEFT:
        temp = vec3(_viewdir.z, 0, -_viewdir.x);
        newpos = _viewpos + amount * temp;
        break;

    case MOVE_RIGHT:
        temp = vec3(_viewdir.z, 0, -_viewdir.x);
        newpos = _viewpos - amount * temp;
        break;
    }
    setViewPosition(newpos);
}

void Video::lookRelative(float amount, int dir)
{
    double r = sqrt(_viewdir.x* _viewdir.x + _viewdir.y* _viewdir.y + _viewdir.z* _viewdir.z);
    double phi = atan2(_viewdir.y, _viewdir.x);
    double theta = (_viewdir.x < 0  ? -1 : 1) * /*2*M_PI - acos(_viewdir.z/r) : */acos(_viewdir.z/r) ;
    double degree;
    switch(dir)
    {
    case LOOK_UP:
        degree = theta * 180 / M_PI;
        theta = fmod((degree - amount + 360), 360.0)* M_PI/180;
        break;

    case LOOK_RIGHT:
        degree = phi * 180 / M_PI;
        phi = fmod((degree - amount + 360), 360.0)* M_PI/180;
        break;

    case LOOK_DOWN:
        degree = fmod(((theta * 180 / M_PI) + amount), 360.0);
        if(degree > 179.9 && degree < 180.1)
        {
            degree += 1;
            degree *= -1.0;
        }
        theta = degree * M_PI/180;
        break;

    case LOOK_LEFT:
        degree = phi * 180 / M_PI;
        phi = fmod((degree + amount), 360.0)* M_PI/180;
        break;
    }
    setViewDir(vec3(r*sin(theta)*cos(phi), r*sin(theta)*sin(phi), r*cos(theta)));
}

void Video::glCuboid(float x1, float y1, float z1, float x2, float y2, float z2)
{
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y1, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y2, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y1, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y2, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y1, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y2, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y1, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y2, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y2, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y1, z1);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y1, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y1, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y1, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y1, z1);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y2, z1);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x1, y2, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y2, z2);
        glColor3f(1.0f, 1.0f, 1.0f);   glVertex3f(x2, y2, z1);
    glEnd();
}

Video::~Video()
{
    //dtor
}
