#include <iostream>
#include <vector>
#include "UzytkownikMenadzer.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenadzer uzytkownikMenadzer;
public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


};
