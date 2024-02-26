#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa :: logowanieUzytkownika()
{
    uzytkownikMenadzer.logowanieUzytkownika();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wylogowanieUzytkownika()
{
    uzytkownikMenadzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenadzer.dodajAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
}












