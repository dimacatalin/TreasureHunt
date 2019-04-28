#include "horse.h"
//acest jucator se poate muta in forma de L la 4 posibile destinatii
//idem ca la tipul de cautatopr fool doar ca schimbarea coordonatelor este diferita
horse::horse()
{
    xposition=0;
    yposition=0;
    status=0;
}

horse::horse(int x,int y,map &harta)
{
    xposition=x;
    yposition=y;
    status=1;
    harta.matrix[x][y]='4';
}

void horse::muv(map &harta)
{
    if(xposition==19 && yposition==19)
    {
        harta.matrix[xposition][yposition]='#';
        xposition-=2;
        yposition--;
        cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
        harta.matrix[xposition][yposition]='4';
        return;
    }
    if(xposition+2<harta.rows && yposition+1<harta.cols)
        if(harta.matrix[xposition+2][yposition+1]=='*')
        {
            status=2;
            harta.matrix[xposition+2][yposition+1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition+2<<" "<<yposition+1<<" si a gasit comoara."<<endl;
            return;
        }
    if(xposition-2>=0 && yposition-1>=0)
        if(harta.matrix[xposition-2][yposition-1]=='*')
        {
            status=2;
            harta.matrix[xposition-2][yposition-1]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition-2<<" "<<yposition-1<<" si a gasit comoara."<<endl;
            return;
        }
    if(xposition-1>=0 && yposition-2>=0)
        if(harta.matrix[xposition-1][yposition-2]=='*')
        {
            status=2;
            harta.matrix[xposition-1][yposition-2]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition-1<<" "<<yposition-2<<" si a gasit comoara."<<endl;
            return;
        }
    if(xposition+1<harta.rows && yposition+2<harta.cols)
        if(harta.matrix[xposition+1][yposition+2]=='*')
        {
            status=2;
            harta.matrix[xposition+1][yposition+2]='#';
            harta.matrix[xposition][yposition]='#';
            cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition+1<<" "<<yposition+2<<" si a gasit comoara."<<endl;
            return;
        }

    if(xposition<harta.rows/2)
    {
        if(yposition+2<harta.cols && xposition+1<harta.rows)
            if(harta.matrix[xposition+1][yposition+2]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition+2]='4';
                yposition+=2;
                xposition++;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
        if(xposition+2<harta.rows && yposition+1<harta.cols )
            if(harta.matrix[xposition+2][yposition+1]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+2][yposition+1]='4';
                xposition+=2;
                yposition++;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
        if(xposition-2>=0 &&yposition-1>=0)
            if(harta.matrix[xposition-2][yposition-1]==0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-2][yposition-1]='4';
                xposition-=2;
                yposition--;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
        if(yposition-2>=0 && xposition-1>=0)
            {
                if(harta.matrix[xposition-1][yposition-2]==0)
                {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition-2]='4';
                yposition-=2;
                xposition--;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
                }
            }
        else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 4 a ramas blocat si a pierdut."<<endl;
                return;
            }
    }

    else
        {
            if(xposition-2>=0 &&yposition-1>=0)
                if(harta.matrix[xposition-2][yposition-1]==0 && xposition-2>=0 && yposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-2][yposition-1]='4';
                xposition-=2;
                yposition--;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(yposition-2>=0 && xposition-1>=0)
                if(harta.matrix[xposition-1][yposition-2]==0 && yposition-2>=0 && xposition-1>=0)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition-1][yposition-2]='4';
                yposition-=2;
                xposition--;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(yposition+2<harta.cols && xposition+1<harta.rows)
                if(harta.matrix[xposition+1][yposition+2]==0 && yposition+2<harta.cols && xposition+1<harta.rows)
            {
                harta.matrix[xposition][yposition]='#';
                harta.matrix[xposition+1][yposition+2]='4';
                yposition+=2;
                xposition++;
                cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                return;
            }
            if(xposition+2<harta.rows && yposition+1<harta.cols )
               {
                if(harta.matrix[xposition+2][yposition+1]==0 && xposition+2<harta.rows && yposition+1<harta.cols )
                {
                    harta.matrix[xposition][yposition]='#';
                    harta.matrix[xposition+2][yposition+1]='4';
                    xposition+=2;
                    yposition++;
                    cout<<"jucatorul 4 s-a mutat pe pozitia "<<xposition<<" "<<yposition<<"."<<endl;
                    return;
                }
               }
            else
            {
                status=0;
                harta.matrix[xposition][yposition]='#';
                cout<<"jucatorul 4 a ramas blocat si a pierdut."<<endl;
                return;
            }
         }
}
