#include "king.h"
//acest jucator se poate muta fata, spate, stanga, dreapta
//idem ca la tipul de cautatopr fool doar ca schimbarea coordonatelor este diferita
king::king()
{
    xposition=0;
    yposition=0;
    status=0;
}

king::king(int x,int y,map &harta)
{
    xposition=x;
    yposition=y;
    status=1;
    harta.matrix[x][y]='2';
}

void king::muv(map &harta)
{
    if(xposition==0 && yposition==19)
    {
        harta.matrix[xposition][yposition]='#';
        xposition++;
        cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
        harta.matrix[xposition][yposition]='2';
        return;
    }
    if(harta.matrix[xposition+1][yposition]=='*')
        {
            status=2;
            harta.matrix[xposition+1][yposition]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition+1<<" "<<yposition<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition-1][yposition]=='*')
        {
            status=2;
            harta.matrix[xposition-1][yposition]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition-1<<" "<<yposition<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition][yposition-1]=='*')
        {
            status=2;
            harta.matrix[xposition][yposition-1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition-1<<" si a gasit comoara."<<endl;
            return;
        }
    if(harta.matrix[xposition][yposition+1]=='*')
        {
            status=2;
            harta.matrix[xposition][yposition+1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition+1<<" si a gasit comoara."<<endl;
            return;
        }

    if(xposition<harta.rows/2)
        {
            if(harta.matrix[xposition+1][yposition]==0 && xposition+1<harta.rows)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition]='2';
                xposition++;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition-1]==0 && yposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition-1]='2';
                yposition--;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition-1][yposition]==0 && xposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition]='2';
                xposition--;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition+1]==0 && yposition+1<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition+1]='2';
                yposition++;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 2 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }
    else
        {
            if(harta.matrix[xposition][yposition-1]==0 && yposition-1>=0)

            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition-1]='2';
                yposition--;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition-1][yposition]==0 && xposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition]='2';
                xposition--;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition][yposition+1]==0 && yposition+1<harta.cols)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition][yposition+1]='2';
                yposition++;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(harta.matrix[xposition+1][yposition]==0 && xposition+1<harta.rows )
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition]='2';
                xposition++;
                cout<<"jucatorul 2 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 2 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }

}

