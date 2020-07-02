#include "biblioteki.h"
#include "proces.h"
#include "fcfs.h"
#include "sjf.h"
#include "lcfs.h"
proces p;
fcfs ef;
sjf es;
lcfs el;
bool sortowaniePoPrzyjsciu(proces const  &j, const proces &d)
{
    return j.czasPrzyjscia<d.czasPrzyjscia;
}
bool sortowaniePoWykonaniu(const proces &j, const proces &d)
{
    return j.czasWykonania<d.czasWykonania;
}

int main()
{
    int x;
    ef.stworzProcesy();
    ef.wczytajZPliku();
    sort(ef.wektorProcesow.begin(), ef.wektorProcesow.end(), sortowaniePoPrzyjsciu);
    ef.wyswietlProcesy();
    ef.dzialaj();
//    std::cout<<"Czy powtorzyc symulacje? "<<std::endl;
//    std::cin>>x;
//    if (x>1)
//    {
//        ef.czas=0;
//        ef.dzialaj();
//    }
//    es.stworzProcesy();
    es.wczytajZPliku();
    sort(es.wektorProcesow.begin(), es.wektorProcesow.end(), sortowaniePoWykonaniu);
    sort(es.wektorProcesow.begin(), es.wektorProcesow.end(), sortowaniePoPrzyjsciu);
//   // es.zapisDoWektora();
    es.wyswietlProcesy();
    es.dzialaj();
//    el.stworzProcesy();
    el.wczytajZPliku();
    sort (el.wektorProcesow.begin(), el.wektorProcesow.end(), sortowaniePoPrzyjsciu);
    el.wyswietlProcesy();
    el.dzialaj();
    return 0;
}
