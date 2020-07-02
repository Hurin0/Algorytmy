#pragma once
#include "biblioteki.h"
class proces
{
    public:
        proces();
        proces(std::string indeks, int przyjscie, int wykonanie);

        std::string indeksProcesu;
        int czasPrzyjscia;
        int czasWykonania;
        void stworzProcesy();
        void wczytajZPliku();
        void wyswietlProcesy();
        std::vector <proces> wektorProcesow;
        friend std::ostream& operator<< (std::ostream& wyjscie, const proces& p);
};
