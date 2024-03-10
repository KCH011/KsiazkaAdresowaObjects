#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include <vector>

class AdresatMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;



public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void wyszukajAdresatowPoImieniu();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void wyszukajAdresatowPoNazwisku();
};

#endif
