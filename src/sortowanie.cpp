#include "biblioteki.h"
bool sortowaniePoPrzyjsciu(const proces &j, const proces &d)
    {
        return j.czasPrzyjscia<d.czasPrzyjscia;
    }
bool sortowaniePoWykonaniu(const proces &j, const proces &d)
    {
        return j.czasWykonania<d.czasWykonania;
    }
