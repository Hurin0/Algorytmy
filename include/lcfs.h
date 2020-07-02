#include "biblioteki.h"
#include "proces.h"

class lcfs : public proces
{
    public:
        lcfs();
        int czas2;
        void procesyWKolejce(int i);
        void oczekiwanieNaProcesy(int i);
        void dzialaj();
        int numer;
        std::vector<std::string> wektor2;
        std::vector<int> wektor3;
};
