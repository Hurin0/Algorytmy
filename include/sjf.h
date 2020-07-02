#include "biblioteki.h"
#include "proces.h"
class sjf : public proces
{
    public:
        sjf();
        sjf(std:: string indeks1, int przyjscie1, int wykonywanie1);
        int czas3;
        void porownanie(int i);
        void oczekiwanieNaProces(int i);
        void zapisDoWektora();
        void dzialaj();
        int Wsize =wektorProcesow.size();;
        int numer;
        int najmniejszy;
        std::vector <sjf> wektorZastepczy;
        std::vector<std::string> wektor2;
        std::vector<int> wektor3;
};
