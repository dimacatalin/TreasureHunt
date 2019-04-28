#ifndef JUMPER_H
#define JUMPER_H

#include <player.h>
#include "map.h"

class jumper : public player
{
    public:
        jumper();
        jumper(int,int,map&);
        void muv(map&);
};

#endif // JUMPER_H
