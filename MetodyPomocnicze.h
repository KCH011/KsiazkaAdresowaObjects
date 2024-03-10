#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze
{
public:
     MetodyPomocnicze();
     static string konwersjaIntNaString(int liczba);
     static string wczytajLinie();
     static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
     static int konwersjaStringNaInt(string liczba);
     static char wczytajZnak();
     static int wczytajLiczbeCalkowita();
     static void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
     static void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);
};

#endif
