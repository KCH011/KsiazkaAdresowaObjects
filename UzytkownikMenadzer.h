#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenadzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

private:
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami (nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void  logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();


};
