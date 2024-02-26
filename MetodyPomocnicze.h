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
    //MetodyPomocnicze();
     static string konwersjaIntNaString(int liczba);
     static string wczytajLinie();
     static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
