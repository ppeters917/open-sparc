#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include "video.h"

Video::Video(vec3 eye, vec3 center, vec3 up)
{
    cameye = eye;
    camcenter = center;
    camup = up;

}

void Video::draw()
{
    glClearColor( 0.0, 0.0, 0.0, 0.0 ); // Farbe zum Löschen setzen
    glClearDepth(1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );     // Aktuellen Bildpuffer löschen

    glMatrixMode(GL_MODELVIEW);

    mat4 mv = glm::lookAt(cameye,camcenter,camup);

	glLoadMatrixf(&mv[0][0]);

    glCuboid(-1,0,-1,1,5,1);

    SDL_GL_SwapBuffers();
    cameye[0] *= 1.0001;
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
