#ifndef FOOL_H
#define FOOL_H

#include "player.h"
#include "map.h"

class fool : public player
{
    public:
        fool();//constructorul nul
        fool(int,int,map&);//constructorul cu parametrii
        void muv(map&);//functia de mutare
};

#endif // FOOL_H
