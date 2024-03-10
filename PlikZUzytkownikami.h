#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{
        const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
        fstream plikTekstowy;

        bool czyPlikJestPusty(fstream &plikTekstowy);
        string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
        Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    public:
        PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI (nazwaPlikuZUzytkownikami){};
        void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
        vector <Uzytkownik> wczytajUzytkownikowZPliku();

};


#endif
