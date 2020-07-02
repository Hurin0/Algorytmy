#pragma once
#include "proces.h"

class fcfs : public proces
{
    public:
        fcfs();
        int czas1;
        void procesyWKolejce(int i);
        void oczekiwanieNaProcesy(int i);
        void przygotowanie();
        void dzialaj();
};
