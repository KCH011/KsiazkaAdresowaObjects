#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):NAZWA_PLIKU_Z_ADRESATAMI(NAZWAPLIKUZADRESATAMI)
{
    idOstatniegoAdresata=0;
}

bool PlikZAdresatami :: czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    else
    return false;
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


vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector<Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze :: konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami :: pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::wczytajIdOstatniegoAdresata(int Id)
{
    idOstatniegoAdresata=Id;
}

void PlikZAdresatami::usunAdresataZPliku(int idAdresata)
{
    //bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    int numerUsuwanejLinii =0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy,tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami="temp.txt";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                //czyIstniejeAdresat = true;
                //plikTekstowy.close();
                //return numerLiniiWPlikuTekstowym;
            }
            else if(numerLiniiWPlikuTekstowym==1)
                tymczasowyPlikTekstowy <<daneJednegoAdresataOddzielonePionowymiKreskami;
            else if (numerUsuwanejLinii==1)
                tymczasowyPlikTekstowy <<daneJednegoAdresataOddzielonePionowymiKreskami;
            else
                tymczasowyPlikTekstowy<<endl<<daneJednegoAdresataOddzielonePionowymiKreskami;

          numerLiniiWPlikuTekstowym++;
          numerUsuwanejLinii++;
                }
      /*  if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }*/
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        MetodyPomocnicze::usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        MetodyPomocnicze::zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);

    }
  //  return 0;
}

void PlikZAdresatami::edytujAdresataWPliku(Adresat adresat)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy,tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami="temp.txt";


    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && adresat.wczytajId() != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(adresat.wczytajId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)&&numerLiniiWPlikuTekstowym==1)
            {
                czyIstniejeAdresat = true;
                tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
                //plikTekstowy.close();
                //return numerLiniiWPlikuTekstowym;
            }
            else if(adresat.wczytajId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)&&numerLiniiWPlikuTekstowym>1)
            {
                czyIstniejeAdresat = true;
                tymczasowyPlikTekstowy <<endl<< zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
            }
            else if(numerLiniiWPlikuTekstowym==1)
                tymczasowyPlikTekstowy <<daneJednegoAdresataOddzielonePionowymiKreskami;
            else if(numerLiniiWPlikuTekstowym>1)
                tymczasowyPlikTekstowy <<endl<<daneJednegoAdresataOddzielonePionowymiKreskami;

         numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            //return 0;
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        MetodyPomocnicze::usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        MetodyPomocnicze::zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
    //return 0;
}

/*void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (numerWczytanejLinii == numerEdytowanejLinii)
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunOdczytywanyPlik(nazwaPlikuZAdresatami);
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, nazwaPlikuZAdresatami);
    }
}*/
