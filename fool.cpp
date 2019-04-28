#include "fool.h"
//acest tip de jucator se poate misca doar pe diagonala
fool::fool()
{
    xposition=0;
    yposition=0;
    status=0;
       }

fool::fool(int x,int y,map &harta)
{
    xposition=x;
    yposition=y;
    status=1;
    harta.matrix[x][y]='1';
}

void fool::muv(map &harta)
{
    if(xposition==0 && yposition==0)//daca este pe pozitia initiala(este prima runda)
    {
        //ii fac mutarea
        harta.matrix[xposition][yposition]='#';//hasurez pozitia pe care era inainte
        //schimb coordonatele in functie de tipul de cautator
        xposition++;
        yposition++;
        harta.matrix[xposition][yposition]='1';//marchez noua pozitie a jucatorului pe harta
        cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;//dau informatii despre mutare
        return;//termin mutarea
    }
    //urmaresc toate mutarile posibile si daca pe una din pozitiile in care pot ajunge este o comoara atunci ma deplasez acolo
    if(xposition+1<harta.rows && yposition+1<harta.cols)//daca pozitia pe care urmeaza sa ma uit nu este in afara hartii
        if(harta.matrix[xposition+1][yposition+1]=='*')//daca pe pozitia respectiva este o comoara
        {
            //atunci jucatorul respectiv a castigat si iese din joc
            status=2;//schimb statusul
            harta.matrix[xposition+1][yposition+1]='#';//hasurez positia veche
            harta.matrix[xposition][yposition]='#';//hasurez pozitia pe care a fost comoara
        cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition+1<<" "<<yposition+1<<" si a gasit comoara."<<endl;//dau info
            return;//termin mutarea
        }
    //idem ca la pozitia de sus
    if(xposition-1>=0 && yposition-1>=0)
        if(harta.matrix[xposition-1][yposition-1]=='*')
        {
            status=2;
            harta.matrix[xposition-1][yposition-1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition-1<<" "<<yposition-1<<" si a gasit comoara."<<endl;
            return;
        }
    //idem ca la pozitia de sus
    if(xposition+1<harta.rows && yposition-1>=0)
        if(harta.matrix[xposition+1][yposition-1]=='*')
        {
            status=2;
            harta.matrix[xposition+1][yposition-1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition+1<<" "<<yposition-1<<" si a gasit comoara."<<endl;
            return;
        }
    //idem ca la pozitia de sus
    if(xposition-1>=0 && yposition+1<harta.cols)
        if(harta.matrix[xposition-1][yposition+1]=='*')
        {
            status=2;
            harta.matrix[xposition-1][yposition+1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition-1<<" "<<yposition+1<<" si a gasit comoara."<<endl;
            return;
        }
    //daca nu a gasit pe nicio pozitie posibila o comoara atunci il mut
    if(xposition<harta.rows/2)//daca este in partea de sus a hartii
        {
            if(xposition+1<harta.rows && yposition+1<harta.cols)//daca pozitia pe care urmeaza sa ma uit nu este in afara hartii
                if(harta.matrix[xposition+1][yposition+1]==0)//daca pozitia este libera
            {
                //fac mutarea
                harta.matrix[xposition][yposition]='#';//hasurez poitia precedenta
                harta.matrix[xposition+1][yposition+1]='1';//marchez unde se va muta
                //schimb coordonatele
                xposition++;
                yposition++;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;//dau info despre mutare
                return;//termin tura
            }
            //daca nu s-a putut muta pe acea pozitie, incercam alta.
            else if(xposition+1<harta.rows && yposition-1>=0)
                if(harta.matrix[xposition+1][yposition-1]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition-1]='1';
                xposition++;
                yposition--;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            //daca nu s-a putut muta pe acea pozitie, incercam alta.
            else if(xposition-1>=0 && yposition+1<harta.cols)
                if(harta.matrix[xposition-1][yposition+1]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition+1]='1';
                xposition--;
                yposition++;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            //daca nu s-a putut muta pe acea pozitie, incercam alta.
            else if(xposition-1>=0 && yposition-1>=0)
                {if(harta.matrix[xposition-1][yposition-1]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition-1]='1';
                xposition--;
                yposition--;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }}
            //daca s-a ajuns aici inseamna ca jucatorul este blocat
            else
            {
                status=0;//ii facem statusul 0
                harta.matrix[xposition][yposition]='#';//hasuram pozitia pe care se afla
                cout<<"jucatorul 1 a ramas blocat si a pierdut."<<endl;//dau info
                return;//termin tura
            }
         }
    else
        {
            //idem ca in partea de sus a hartii doar ca am schimbat ordinea incercarilor de a se muta
            if(harta.matrix[xposition-1][yposition+1]==0 && xposition-1>=0 && yposition+1<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition+1]='1';
                xposition--;
                yposition++;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }

            else if(harta.matrix[xposition-1][yposition-1]==0 && xposition-1>=0 && yposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition-1]='1';
                xposition--;
                yposition--;
                return;
            }
            else if(harta.matrix[xposition+1][yposition+1]==0 && xposition+1<harta.rows && yposition+1<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition+1]='1';
                xposition++;
                yposition++;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else if(harta.matrix[xposition+1][yposition-1]==0 && xposition+1<harta.rows && yposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition-1]='1';
                xposition++;
                yposition--;
                cout<<"jucatorul 1 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 1 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }

}
