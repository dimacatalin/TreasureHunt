#include "player.h"

player::player()
{
    xposition=0;
    yposition=0;
}

player::player(const player &a)
{
    xposition=a.xposition;
    yposition=a.yposition;
}

player::player(int x,int y)
{
    xposition=x;
    yposition=y;
}

void player::makestatus(int x)
{
    status=x;
}

int player::getstatus()
{
    return status;
}


