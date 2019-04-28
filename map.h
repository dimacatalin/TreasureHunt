#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;

class map
{
    public:
        map();//constructorul nul
        map(int,int);//constructorul cu parametrii
        map(const map&);//constructorul de copiere
        ~map();//destructor
        friend ostream& operator<<(ostream&,const map&);//supraincarcarea operatorului de afisare
        //declar umatoarele clase ca prietene clasei map pentru a putea apela harta in interiorul lor
        friend class player;
        friend class fool;
        friend class jumper;
        friend class horse;
        friend class king;
    protected:
        int rows;//nr de linii
        int cols;//nr de coloane
        char **matrix;//harta reprezentata de o matrice
};

#endif // MAP_H
