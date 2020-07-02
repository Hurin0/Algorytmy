#include "fcfs.h"
#include "biblioteki.h"

fcfs::fcfs()
{

}

void fcfs::procesyWKolejce(int i)
{
    std::cout<<wektorProcesow[i].indeksProcesu<<" Wykonuje, czas: "<< wektorProcesow[i].czasWykonania<<std::endl;
    Sleep(wektorProcesow[i].czasWykonania*10);
    std::cout<<"Zakonczono wykonywanie procesu."<<std::endl;
    czas1+=wektorProcesow[i].czasWykonania;
    std::cout<<"Laczny czas dzialania: "<<czas1<<std::endl;
}

void fcfs::oczekiwanieNaProcesy(int i)
{
    std::cout<<"Brak procesow w kolejce, oczekuje na procesy."<<std::endl;
    Sleep((wektorProcesow[i].czasPrzyjscia-czas1)*10);
    std::cout<<"Przyszedl proces.";
    std::cout<<wektorProcesow[i].indeksProcesu<<" Wykonuje, czas: "<< wektorProcesow[i].czasWykonania<<std::endl;
    Sleep(wektorProcesow[i].czasWykonania*10);
    std::cout<<"Zakonczono wykonywanie procesu."<<std::endl;
    czas1+=wektorProcesow[i].czasWykonania+wektorProcesow[i].czasPrzyjscia-czas1;
    std::cout<<"Laczny czas dzialania: "<<czas1<<std::endl;
}

void fcfs::dzialaj()
{
    for (int i=0; i<wektorProcesow.size(); i++)
    {
        if (czas1>=wektorProcesow[i].czasPrzyjscia)
        {
            procesyWKolejce(i);
        }
        else
        {
            oczekiwanieNaProcesy(i);
        }
    }
}

