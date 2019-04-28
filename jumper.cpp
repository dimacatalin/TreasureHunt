#include "jumper.h"
//acest jucator se poate muta fata, spate, stanga, dreapta din 2 in 2 pozitii
//idem ca la tipul de cautatopr fool doar ca schimbarea coordonatelor este diferita
jumper::jumper()
{
    xposition=0;
    yposition=0;
    status=0;
}

jumper::jumper(int x,int y,map &harta)
{
    xposition=x;
    yposition=y;
    status=1;
    harta.matrix[x][y]='3';
}

void jumper::muv(map &harta)
{
    if(xposition==19 && yposition==0)
    {
        harta.matrix[xposition][yposition]='#';
        xposition-=2;
        cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
        harta.matrix[xposition][yposition]='3';
        return;
    }
    if(harta.matrix[xposition+2][yposition]=='*')
        {
            status=2;
            harta.matrix[xposition+2][yposition]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition+2<<" "<<yposition<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition-2][yposition]=='*')
        {
            status=2;
            harta.matrix[xposition-2][yposition]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition-2<<" "<<yposition<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition][yposition-2]=='*')
        {
            status=2;
            harta.matrix[xposition][yposition-1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition-2<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition][yposition+2]=='*')
        {
            status=2;
            harta.matrix[xposition][yposition+2]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition+2<<" si a gasit comoara."<<endl;
            return;
        }

    if(xposition<harta.rows/2)
        {
            if(harta.matrix[xposition][yposition+2]==0 && yposition+2<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition+2]='3';
                yposition+=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition+2][yposition]==0 && xposition+2<harta.rows)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+2][yposition]='3';
                xposition+=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition-2]==0 && yposition-2>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition-2]='3';
                yposition-=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition-2][yposition]==0 && xposition-2>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-2][yposition]='3';
                xposition-=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 3 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }
    else
        {
            if(harta.matrix[xposition-2][yposition]==0 && xposition-2>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-2][yposition]='3';
                xposition-=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition+2]==0 && yposition+2<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition+2]='3';
                yposition+=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition-2]==0 && yposition-2>=0)

            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition-2]='3';
                yposition-=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition+2][yposition]==0 && xposition+2<harta.rows )
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+2][yposition]='3';
                xposition+=2;
                cout<<"jucatorul 3 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 3 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }
}
