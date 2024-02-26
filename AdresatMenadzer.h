#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include <vector>

class AdresatMenadzer
{
    vector<Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;
public:
    AdresatMenadzer();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
};

#endif
