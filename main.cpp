#include <iostream>
#include "player.h"
#include "jumper.h"
#include "fool.h"
#include "horse.h"
#include "map.h"
#include "king.h"
using namespace std;


int main()
{
    map harta(20,20);//declar o harta de 20 pe 20
    fool foo(0,0,harta);//declar un jucator de tip fool in colt stanga sus
    king kee(0,19,harta);//declar un jucator de tip king in colt dreapta sus
    jumper joo(19,0,harta);//declar un jucator de tip jumper in cont stanga jos
    horse hoo(19,19,harta);//declar un jucator de tip horse in colt dreapta jos
    int nrjucatori=4;
    int nrcomori=3;
    cout<<"START"<<endl;
    cout<<harta;
    while(nrjucatori>0 && nrcomori>0)//jocul merge pana cand nu mai sunt comori sau nu mai sunt jucatori
    {
        //pentru jucatorul de tip fool
        if(foo.getstatus()==1)//daca inca este in joc
            foo.muv(harta);//apelez functia de mutare
        else if(foo.getstatus()==2)//daca a castigat in tura trecuta
        {
            foo.makestatus(3);//schimb statusul in 3
            nrcomori--;//scad numarul de comori
            nrjucatori--;//scad numarul de jucatori
            if (nrjucatori==0 || nrcomori==0)//daca numarul de jucatori sau nuamrul de comori=0
                break;//end game
        }
        else if(foo.getstatus()==0)//daca tura trecuta jucatorul a ramas blocat
            {
            nrjucatori--;//scad numarul de jucatori
            foo.makestatus(3);//fac statusul 3
            if(nrjucatori==0)//daca nr de jucatori=0
                break;//end game
            }
        //idem ca la fool
        if(hoo.getstatus()==1)hoo.muv(harta);
        else if(hoo.getstatus()==2)
        {
            hoo.makestatus(3);
            nrcomori--;
            nrjucatori--;
            if (nrjucatori==0 || nrcomori==0)
                break;
        }
        else if(hoo.getstatus()==0)
        {
            nrjucatori--;
            hoo.makestatus(3);
            if(nrjucatori==0)
                break;
        }
        //idem ca la foo
        if(joo.getstatus()==1)joo.muv(harta);
        else if(joo.getstatus()==2)
        {
            joo.makestatus(3);
            nrcomori--;
            nrjucatori--;
            if (nrjucatori==0 || nrcomori==0)
                break;
        }
        else if(joo.getstatus()==0)
        {
            joo.makestatus(3);
            nrjucatori--;
            if(nrjucatori==0)
                break;
        }
        //idem ca la foo
        if(kee.getstatus()==1)kee.muv(harta);
        else if(kee.getstatus()==2)
        {
            kee.makestatus(3);
            nrcomori--;
            nrjucatori--;
            if (nrjucatori==0 || nrcomori==0)
                break;
        }
        else if(kee.getstatus()==0)
        {
            kee.makestatus(3);
            nrjucatori--;
            if(nrjucatori==0)
                break;
        }
        cout<<harta<<endl;
    }
    cout<<"END GAME";

}
