#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include "video.h"

bool init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 // get screen resolution
    const SDL_VideoInfo* info = SDL_GetVideoInfo();



    if(( SDL_SetVideoMode(info->current_w, info->current_h, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_FULLSCREEN | SDL_OPENGL)) == NULL) {
        return false;
    }
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,info->current_w/(float)info->current_h,0.1,99);
	glViewport(0,0,info->current_w,info->current_h);

    return true;
}

int main ( int argc, char** argv )
{
    if ( !init() )
    {
        printf("Unable to start SDL + OPENGL: %s\n", SDL_GetError());
        return 1;
    }

    Video video = Video(vec3(0.01,1,0), vec3(0,0,0), vec3(0,1,0));

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        video.draw();

        // DRAWING ENDS HERE

        // finally, update the screen :)

    } // end main loop

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
