#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class PlikZUzytkownikami
{
        string nazwaPlikuZUzytkownikami;
        fstream plikTekstowy;
        bool czyPlikJestPusty();
        string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
        Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    public:
        PlikZUzytkownikami();
        void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
        void wczytajUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy);

};
