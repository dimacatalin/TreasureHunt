#ifndef HORSE_H
#define HORSE_H

#include <player.h>
#include "map.h"

class horse : public player
{
    public:
        horse();
        horse(int,int,map&);
        void muv(map&);
};

#endif // HORSE_H
