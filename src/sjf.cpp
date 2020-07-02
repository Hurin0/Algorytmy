#include "sjf.h"

sjf::sjf()
{

}
sjf::sjf(std::string indeks1, int przyjscie1, int wykonanie1)
{
    this->indeksProcesu=indeks1;
    this->czasPrzyjscia=przyjscie1;
    this->czasWykonania=wykonanie1;
}

void sjf::porownanie(int i)
{
            for(size_t b=0; b<wektorProcesow.size(); b++)
            {
                if (wektorProcesow[b].czasPrzyjscia<=czas3)
                {
                    wektor2.push_back(wektorProcesow[b].indeksProcesu);
                    wektor3.push_back(wektorProcesow[b].czasWykonania);
                }
            }
            std::cout<<std::endl;
            numer=0;
            najmniejszy=wektor3[0];
            for(size_t j=0; j<wektor3.size(); j++)
            {
                std::cout<<" Porownuje:     "<<wektor2[j]<<"Czas wykonywania: " <<wektor3[j]<<std::endl;
                if(wektor3[j]<najmniejszy)
                {
                    najmniejszy=wektor3[j];
                    numer=j;
                }
            }
            czas3=czas3+wektorProcesow[numer].czasWykonania;
            std::cout<<"   "<<wektor2[numer]<<"Wykonuje, czas: "<<najmniejszy<<std::endl;
            Sleep(wektorProcesow[numer].czasWykonania*10);
            std::cout<<"Zakonczono wykonywanie procesu"<<std::endl;
            wektorProcesow.erase(wektorProcesow.begin()+numer);
            std::cout<<"Laczny czas dzialania: "<<czas3<<std::endl;
            wektor2.clear();
            wektor3.clear();
            i--;

}

void sjf::oczekiwanieNaProces(int i)
{
        std::cout<<"Brak procesow w kolejce, oczekuje na procesy."<<std::endl;
        Sleep((wektorProcesow[i].czasPrzyjscia-czas3)*10);
        std::cout<<"Przyszedl proces."<<std::endl;
        std::cout<<wektorProcesow[i].indeksProcesu<<" Wykonuje, czas: "<< wektorProcesow[i].czasWykonania<<std::endl;
        Sleep(wektorProcesow[i].czasWykonania*10);
        std::cout<<"Zakonczono wykonywanie procesu."<<std::endl;
        czas3=wektorProcesow[i].czasPrzyjscia;
        std::cout<<"Laczny czas dzialania: "<<czas3<<std::endl;
        i--;
}
void sjf::dzialaj()
{
    size_t Wsize=wektorProcesow.size();
    for (size_t i=0; i<Wsize; i++)
    {
        if (wektorProcesow.empty()==true)
        {
            break;
        }
       if (czas3>=wektorProcesow[i].czasPrzyjscia)
       {
           porownanie(i);
       }
       else
       {
           oczekiwanieNaProces(i);
       }
    }
}
