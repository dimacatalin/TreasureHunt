#ifndef KING_H
#define KING_H

#include <player.h>
#include "map.h"

class king : public player
{
    public:
        king();
        king(int,int,map&);
        void muv(map&);
};

#endif // KING_H
