#ifndef GAME_H
#define GAME_H

#include "video.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void tick(Video* video);
    protected:
    private:
};

#endif // GAME_H
