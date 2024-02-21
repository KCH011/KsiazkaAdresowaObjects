#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class PlikZUzytkownikami
{
        string nazwaPlikuZUzytkownikami;
        fstream plikTekstowy;
        bool czyPlikJestPusty();
        string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

    public:
        PlikZUzytkownikami();
            void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);

};
