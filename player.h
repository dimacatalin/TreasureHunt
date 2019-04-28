#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
class player
{
    public:
        player();//constructor nul
        player(const player&);//constructor de copiere
        player(int,int);//construcotrul cu parametrii
        virtual void muv(map &harta)=0;//functie virtuala pura pentru mutarea fiecarui tip de cautator
        int getstatus();//functie care returneaza statuul
        void makestatus(int);//functie care schimba statusul cu un mnumar dat
    protected:
        int xposition;
        int yposition;
        int status;//0=offline, 1=online, 2=winner, 3=offline
};

#endif // PLAYER_H
