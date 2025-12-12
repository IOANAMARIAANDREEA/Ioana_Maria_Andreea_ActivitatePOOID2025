#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// DOMENIU: IMOBILIARE (I M A) -> Ioana Maria Andreea
// Clase: Imobil, MandatImobiliar, Apartament


//  CLASA IMOBIL 

class Imobil {
public:
    const int idImobil;      
    static int nextId;       

    char* adresa;            
    float suprafata;
    int anConstructie;


    Imobil() : idImobil(++nextId) {
        this->adresa = new char[strlen("Necunoscuta") + 1];
        strcpy(this->adresa, "Necunoscuta");

        this->suprafata = 0;
        this->anConstructie = 0;
    }


    Imobil(const char* adresa) : idImobil(++nextId) {
        if (adresa != nullptr) {
            this->adresa = new char[strlen(adresa) + 1];
            strcpy(this->adresa, adresa);
        }
        else {
            this->adresa = new char[strlen("Necunoscuta") + 1];
            strcpy(this->adresa, "Necunoscuta");
        }

        this->suprafata = 0;
        this->anConstructie = 0;
    }

    Imobil(const char* adresa, float suprafata, int anConstructie) : idImobil(++nextId) {
        if (adresa != nullptr) {
            this->adresa = new char[strlen(adresa) + 1];
            strcpy(this->adresa, adresa);
        }
        else {
            this->adresa = new char[strlen("Necunoscuta") + 1];
            strcpy(this->adresa, "Necunoscuta");
        }

        this->suprafata = suprafata;
        this->anConstructie = anConstructie;
    }



    static float calculeazaValoareEstimativa(float suprafata) {
        return suprafata * 1200.0; 
    }

    void afisare() const {
        cout << "Imobil ID: " << idImobil
            << " | Adresa: " << (adresa ? adresa : "NULL")
            << " | Suprafata: " << suprafata
            << " | An constructie: " << anConstructie << endl;
    }
};


int Imobil::nextId = 0;



// CLASA MANDAT IMOBILIAR

class MandatImobiliar {
public:
    const int idMandat;
    static int nextId;

    char* proprietar;     
    string tipMandat;     
    float comision;       
    int durataZile;       

    MandatImobiliar() : idMandat(++nextId) {
        this->proprietar = new char[strlen("Anonim") + 1];
        strcpy(this->proprietar, "Anonim");

        this->tipMandat = "N/A";
        this->comision = 0;
        this->durataZile = 0;
    }

    MandatImobiliar(const char* proprietar, string tipMandat) : idMandat(++nextId) {
        if (proprietar != nullptr) {
            this->proprietar = new char[strlen(proprietar) + 1];
            strcpy(this->proprietar, proprietar);
        }
        else {
            this->proprietar = new char[strlen("Anonim") + 1];
            strcpy(this->proprietar, "Anonim");
        }

        this->tipMandat = tipMandat;
        this->comision = 0;
        this->durataZile = 0;
    }


    MandatImobiliar(const char* proprietar, string tipMandat, float comision, int durataZile)
        : idMandat(++nextId)
    {
        if (proprietar != nullptr) {
            this->proprietar = new char[strlen(proprietar) + 1];
            strcpy(this->proprietar, proprietar);
        }
        else {
            this->proprietar = new char[strlen("Anonim") + 1];
            strcpy(this->proprietar, "Anonim");
        }

        this->tipMandat = tipMandat;
        this->comision = comision;
        this->durataZile = durataZile;
    }



    static float calculeazaComision(float valoareTranzactie, float comisionProcent) {
        return (valoareTranzactie * comisionProcent) / 100.0f;
    }

    void afisare() const {
        cout << "Mandat ID: " << idMandat
            << " | Proprietar: " << (proprietar ? proprietar : "NULL")
            << " | Tip: " << tipMandat
            << " | Comision: " << comision
            << " | Durata: " << durataZile << " zile" << endl;
    }
};

int MandatImobiliar::nextId = 0;



// CLASA APARTAMENT

class Apartament {
public:
    const int idApartament;
    static int nextId;

    char* tip;           
    int etaj;
    bool areBalcon;
    float suprafata;

    Apartament() : idApartament(++nextId) {
        this->tip = new char[strlen("Nedefinit") + 1];
        strcpy(this->tip, "Nedefinit");

        this->etaj = 0;
        this->areBalcon = false;
        this->suprafata = 0;
    }


    Apartament(const char* tip) : idApartament(++nextId) {
        if (tip != nullptr) {
            this->tip = new char[strlen(tip) + 1];
            strcpy(this->tip, tip);
        }
        else {
            this->tip = new char[strlen("Nedefinit") + 1];
            strcpy(this->tip, "Nedefinit");
        }

        this->etaj = 0;
        this->areBalcon = false;
        this->suprafata = 0;
    }


    Apartament(const char* tip, int etaj, bool areBalcon, float suprafata)
        : idApartament(++nextId)
    {
        if (tip != nullptr) {
            this->tip = new char[strlen(tip) + 1];
            strcpy(this->tip, tip);
        }
        else {
            this->tip = new char[strlen("Nedefinit") + 1];
            strcpy(this->tip, "Nedefinit");
        }

        this->etaj = etaj;
        this->areBalcon = areBalcon;
        this->suprafata = suprafata;
    }



    static float calculeazaIntretinere(float suprafata) {
        return suprafata * 8.5; 
    }

    void afisare() const {
        cout << "Apartament ID: " << idApartament
            << " | Tip: " << (tip ? tip : "NULL")
            << " | Etaj: " << etaj
            << " | Balcon: " << (areBalcon ? "DA" : "NU")
            << " | Suprafata: " << suprafata << endl;
    }
};

int Apartament::nextId = 0;


int main() {

    cout << "=== IMOBIL ===" << endl;
    Imobil i1;                                
    Imobil i2("Str. Libertatii nr. 10");      
    Imobil i3("Bd. Unirii nr. 5", 85.5, 2015); 

    i1.afisare();
    i2.afisare();
    i3.afisare();
    cout << "Valoare estimativa i3: " << Imobil::calculeazaValoareEstimativa(85.5f) << endl;

    cout << "\n=== MANDAT IMOBILIAR ===" << endl;
    MandatImobiliar m1;                                 
    MandatImobiliar m2("Popescu Ana", "Vanzare");         
    MandatImobiliar m3("Ionescu Mihai", "Inchiriere", 2.5, 90); 

    m1.afisare();
    m2.afisare();
    m3.afisare();
    cout << "Comision la 100000 euro (2.5%): " << MandatImobiliar::calculeazaComision(100000, 2.5) << endl;

    cout << "\n=== APARTAMENT ===" << endl;
    Apartament a1;                                      
    Apartament a2("Studio");                            
    Apartament a3("2 camere", 3, true, 52.0);          

    a1.afisare();
    a2.afisare();
    a3.afisare();
    cout << "Intretinere estimata a3: " << Apartament::calculeazaIntretinere(52.0) << endl;

    return 0;
}
