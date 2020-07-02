#include "proces.h"
#include "biblioteki.h"


int ileProcesow;
proces::proces()
{

}

proces::proces(std::string indeks, int przyjscie, int wykonanie)
{
    this->indeksProcesu=indeks;
    this->czasPrzyjscia=przyjscie;
    this->czasWykonania=wykonanie;
}

void proces::stworzProcesy()
{
    srand (time (NULL));
    std::cout<<"Ile procesow utworzyc?"<<std::endl;
    std::cin>>ileProcesow;
    std::cin.get();
    std::string indeksP[ileProcesow];
    int czasP[ileProcesow];
    int czasW[ileProcesow];
    for (int i=0; i<ileProcesow; i++)
    {
        indeksP[i]="Proces ";
        czasP[i]=0;
        czasW[i]=rand()%25+1;
    }
    std::ofstream plik;
    plik.open("procesy.txt");
    for (int j=0; j<ileProcesow; j++)
    {
        plik<<"t"<<indeksP[j]<<j+1<<std::endl;
        plik<<czasP[j]<<std::endl;
        plik<<czasW[j]<<std::endl;
    }
    plik.close();
}


void proces::wczytajZPliku()
{
    std::string indeksP;
    std::string hmmm;
    int czasP;
    int czasW;
    char znak;
    std::ifstream plik;
    plik.open("procesy.txt");

    if (plik.is_open())
    {
        while (plik>>znak)
        {
            std::getline(plik, indeksP);
            plik>>czasP;
            plik>>czasW;
            std::getline(plik,hmmm);
            wektorProcesow.push_back(proces(indeksP, czasP, czasW));
        }
    } else std::cout<<"BLAD OTWARCIA PLIKU"<<std::endl;
    plik.close();
}

std::ostream& operator<< (std::ostream& wyjscie, const proces& p)
{
    return wyjscie<<"     "<<p.indeksProcesu<<"\nCzas przyjscia: "<<p.czasPrzyjscia<<"\nCzas wykonania: "<< p.czasWykonania<<std::endl;
}

void proces::wyswietlProcesy()
{
    for (unsigned i=0; i<wektorProcesow.size(); i++)
    {
        std::cout<<wektorProcesow[i];
    }
}

