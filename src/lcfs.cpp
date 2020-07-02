#include "lcfs.h"

lcfs::lcfs()
{

}

void lcfs::procesyWKolejce(int i)
{
        for(size_t b=0; b<wektorProcesow.size(); b++)
        {
            if (wektorProcesow[b].czasPrzyjscia<=czas2)
            {
                wektor2.push_back(wektorProcesow[b].indeksProcesu);
                wektor3.push_back(wektorProcesow[b].czasWykonania);
                numer=b;
            }
        }
        std::cout<<std::endl;
        czas2=czas2+wektorProcesow[numer].czasWykonania;
        std::cout<<"   "<<wektor2[numer]<<"Wykonuje, czas: "<<wektorProcesow[numer].czasWykonania<<std::endl;
        Sleep(wektorProcesow[numer].czasWykonania*10);
        std::cout<<"Zakonczono wykonywanie procesu"<<std::endl;
        wektorProcesow.erase(wektorProcesow.begin()+numer);
        std::cout<<"Laczny czas dzialania: "<<czas2<<std::endl;
        wektor2.clear();
        wektor3.clear();
        i=-1;
}
void lcfs::oczekiwanieNaProcesy(int i)
{
    std::cout<<"Brak procesow w kolejce, oczekuje na procesy."<<std::endl;
    Sleep((wektorProcesow[i].czasPrzyjscia-czas2)*10);
    std::cout<<"Przyszedl proces."<<std::endl;
    std::cout<<wektorProcesow[i].indeksProcesu<<" Wykonuje, czas: "<< wektorProcesow[i].czasWykonania<<std::endl;
    Sleep(wektorProcesow[i].czasWykonania*10);
    std::cout<<"Zakonczono wykonywanie procesu."<<std::endl;
    czas2=wektorProcesow[i].czasPrzyjscia;
    std::cout<<"Laczny czas dzialania: "<<czas2<<std::endl;
    i--;
}

void lcfs::dzialaj()
{
    size_t Wsize=wektorProcesow.size();
    for (size_t i=0; i<Wsize; i++)
    {
        if (wektorProcesow.empty()==true)
        {
            break;
        }
       if (czas2>=wektorProcesow[i].czasPrzyjscia)
       {
           procesyWKolejce(i);
       }
       else
       {
           oczekiwanieNaProcesy(i);
       }
    }
}
