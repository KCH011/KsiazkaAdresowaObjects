#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa :: logowanieUzytkownika()
{
    int loginId = uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer = new AdresatMenadzer (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    }
    return loginId;
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wylogowanieUzytkownika()
{
    uzytkownikMenadzer.wylogowanieUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

void KsiazkaAdresowa :: dodajAdresata()
{
    //adresatMenadzer.dodajAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> dodajAdresata();
    }
    else{
      cout << "Aby dodac adresata, nalezy sie zalogowac" << endl;
      system("pause");
    }
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow()
{
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> wyswietlWszystkichAdresatow();
    }

}

void KsiazkaAdresowa :: wczytajAdresatowZPliku()
{
    adresatMenadzer -> wczytajAdresatowZPliku(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
}

bool KsiazkaAdresowa :: czyUzytkownikJestZalogowany()
{
    return uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa :: wyszukajAdresatowPoImieniu()
{
    adresatMenadzer -> wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa :: wyszukajAdresatowPoNazwisku()
{
    adresatMenadzer -> wyszukajAdresatowPoNazwisku();
}





