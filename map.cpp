#include "map.h"
#include <cstdlib>
//in afara de plantarea comorilor este cam identic ca la proiectul matrice
map::map()
{
    rows=0;
    cols=0;
    matrix=NULL;
}

map::map(int row,int col)
{
    int i,j,r1,r2,r3;
    rows=row;
    cols=col;

    matrix=new char *[rows];
    for(i=0; i<rows; i++)
        matrix[i]=new char[col];

    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            matrix[i][j]=0;

    //generez 3 nuamre randon intre 0 si 396
    r1 = (rand() % (i*j-4)) + 1;
    r2 = (rand() % (i*j-4)) + 1;
    r3 = (rand() % (i*j-4)) + 1;

    int nr=0;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
        {
            if(!(i==0&&j==0)||!(i==rows&&j==0)||!(i==rows&&j==cols)||!(i==0&&j==cols))//prcurge toata matricea mai putin colturile
            {
                if(nr==r1||nr==r2||nr==r3)//daca pozitia curenta este unul din cele 3 numere generate atunci plantez o comoara
                    matrix[i][j]='*';
                nr++;
            }
        }
}

map::map(const map &a)
{
    rows=a.rows;
    cols=a.cols;
    matrix=a.matrix;
}

map::~map()
{
    int i;
    for(i=0; i<rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}


ostream& operator<<(ostream& out,const map &a)
{
    int i,j;
    for(j=0; j<a.cols*4+1; j++)
            out<<"-";
        out<<endl;
    for(i=0; i<a.rows; i++)
    {
        for(j=0; j<a.cols; j++)
            if(j!=0)out<<a.matrix[i][j]<<" | ";
                else out<<"| "<<a.matrix[i][j]<<" | ";
        out<<endl;
        for(j=0; j<a.cols*4+1; j++)
            out<<"-";
        out<<endl;
    }
    return out;
}
