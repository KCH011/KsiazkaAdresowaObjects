#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
        //fstream plikTekstowy;
        plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

        if (plikTekstowy.good() == true)
        {
            liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

            if (czyPlikJestPusty() == true)
            {
                plikTekstowy << liniaZDanymiAdresata;
            }
            else
            {
                plikTekstowy << endl << liniaZDanymiAdresata ;
            }
            plikTekstowy.close();
        }
        else
        {
            cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        }
        system("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.wczytajId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.wczytajIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.wczytajImie() + '|';
    liniaZDanymiAdresata += adresat.wczytajNazwisko() + '|';
    liniaZDanymiAdresata += adresat.wczytajNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.wczytajEmail() + '|';
    liniaZDanymiAdresata += adresat.wczytajAdres() + '|';

    return liniaZDanymiAdresata;
}

bool PlikZAdresatami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
