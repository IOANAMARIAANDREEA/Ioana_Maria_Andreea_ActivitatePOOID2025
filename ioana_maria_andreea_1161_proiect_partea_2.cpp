#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// DOMENIU: IMOBILIARE (I M A) -> Ioana Maria Andreea
// Clase: Imobil, MandatImobiliar, Apartament


class Imobil;
class Apartament;
class MandatImobiliar;


float suprafataTotala(const Imobil& i, const Apartament& a);


float costTotalMandatSiIntretinere(const MandatImobiliar& m, const Apartament& a);



//  CLASA IMOBIL 

class Imobil {
private:
    const int idImobil;
    static int nextId;

    char* adresa;
    float suprafata;
    int anConstructie;

public:

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


    Imobil(const Imobil& other) : idImobil(++nextId) {
        if (other.adresa != nullptr) {
            this->adresa = new char[strlen(other.adresa) + 1];
            strcpy(this->adresa, other.adresa);
        }
        else {
            this->adresa = nullptr;
        }

        this->suprafata = other.suprafata;
        this->anConstructie = other.anConstructie;
    }


    ~Imobil() {
        if (this->adresa != nullptr) {
            delete[] this->adresa;
            this->adresa = nullptr;
        }
    }


    static int getNextId() {
        return nextId;
    }


    int getIdImobil() const {
        return idImobil;
    }

    const char* getAdresa() const {
        return adresa;
    }

    void setAdresa(const char* adresaNoua) {
        if (adresaNoua != nullptr && strlen(adresaNoua) > 0) {
            if (this->adresa != nullptr) {
                delete[] this->adresa;
            }
            this->adresa = new char[strlen(adresaNoua) + 1];
            strcpy(this->adresa, adresaNoua);
        }
    }

    float getSuprafata() const {
        return suprafata;
    }

    void setSuprafata(float suprafataNoua) {
        if (suprafataNoua >= 0) {
            this->suprafata = suprafataNoua;
        }
    }

    int getAnConstructie() const {
        return anConstructie;
    }

    void setAnConstructie(int anNou) {
        if (anNou >= 0) {
            this->anConstructie = anNou;
        }
    }


    static float calculeazaValoareEstimativa(float suprafata) {
        return suprafata * 1200.0f;
    }

    void afisare() const {
        cout << "Imobil ID: " << idImobil
            << " | Adresa: " << (adresa ? adresa : "NULL")
            << " | Suprafata: " << suprafata
            << " | An constructie: " << anConstructie << endl;
    }


    friend float suprafataTotala(const Imobil& i, const Apartament& a);
};

int Imobil::nextId = 0;



// CLASA MANDAT IMOBILIAR 

class MandatImobiliar {
private:
    const int idMandat;
    static int nextId;

    char* proprietar;
    string tipMandat;
    float comision;
    int durataZile;

public:
    MandatImobiliar() : idMandat(++nextId) {
        this->proprietar = new char[strlen("Anonim") + 1];
        strcpy(this->proprietar, "Anonim");

        this->tipMandat = "Necunoscut";
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


    MandatImobiliar(const MandatImobiliar& other) : idMandat(++nextId) {
        if (other.proprietar != nullptr) {
            this->proprietar = new char[strlen(other.proprietar) + 1];
            strcpy(this->proprietar, other.proprietar);
        }
        else {
            this->proprietar = nullptr;
        }

        this->tipMandat = other.tipMandat;
        this->comision = other.comision;
        this->durataZile = other.durataZile;
    }


    ~MandatImobiliar() {
        if (this->proprietar != nullptr) {
            delete[] this->proprietar;
            this->proprietar = nullptr;
        }
    }


    static int getNextId() {
        return nextId;
    }


    int getIdMandat() const {
        return idMandat;
    }

    const char* getProprietar() const {
        return proprietar;
    }

    void setProprietar(const char* propNou) {
        if (propNou != nullptr && strlen(propNou) > 0) {
            if (this->proprietar != nullptr) {
                delete[] this->proprietar;
            }
            this->proprietar = new char[strlen(propNou) + 1];
            strcpy(this->proprietar, propNou);
        }
    }

    string getTipMandat() const {
        return tipMandat;
    }

    void setTipMandat(string tipNou) {
        if (tipNou.length() > 0) {
            this->tipMandat = tipNou;
        }
    }

    float getComision() const {
        return comision;
    }

    void setComision(float comNou) {
        if (comNou >= 0) {
            this->comision = comNou;
        }
    }

    int getDurataZile() const {
        return durataZile;
    }

    void setDurataZile(int dNou) {
        if (dNou >= 0) {
            this->durataZile = dNou;
        }
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


    friend float costTotalMandatSiIntretinere(const MandatImobiliar& m, const Apartament& a);
};

int MandatImobiliar::nextId = 0;



// CLASA APARTAMENT 

class Apartament {
private:
    const int idApartament;
    static int nextId;

    char* tip;
    int etaj;
    bool areBalcon;
    float suprafata;

public:
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


    Apartament(const Apartament& other) : idApartament(++nextId) {
        if (other.tip != nullptr) {
            this->tip = new char[strlen(other.tip) + 1];
            strcpy(this->tip, other.tip);
        }
        else {
            this->tip = nullptr;
        }

        this->etaj = other.etaj;
        this->areBalcon = other.areBalcon;
        this->suprafata = other.suprafata;
    }


    ~Apartament() {
        if (this->tip != nullptr) {
            delete[] this->tip;
            this->tip = nullptr;
        }
    }


    static int getNextId() {
        return nextId;
    }


    int getIdApartament() const {
        return idApartament;
    }

    const char* getTip() const {
        return tip;
    }

    void setTip(const char* tipNou) {
        if (tipNou != nullptr && strlen(tipNou) > 0) {
            if (this->tip != nullptr) {
                delete[] this->tip;
            }
            this->tip = new char[strlen(tipNou) + 1];
            strcpy(this->tip, tipNou);
        }
    }

    int getEtaj() const {
        return etaj;
    }

    void setEtaj(int etajNou) {
        this->etaj = etajNou;
    }

    bool getAreBalcon() const {
        return areBalcon;
    }

    void setAreBalcon(bool balconNou) {
        this->areBalcon = balconNou;
    }

    float getSuprafata() const {
        return suprafata;
    }

    void setSuprafata(float supNoua) {
        if (supNoua >= 0) {
            this->suprafata = supNoua;
        }
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


    friend float suprafataTotala(const Imobil& i, const Apartament& a);
    friend float costTotalMandatSiIntretinere(const MandatImobiliar& m, const Apartament& a);
};

int Apartament::nextId = 0;



float suprafataTotala(const Imobil& i, const Apartament& a) {
    return i.suprafata + a.suprafata;
}

float costTotalMandatSiIntretinere(const MandatImobiliar& m, const Apartament& a) {
    float comisionPeTranzactie = MandatImobiliar::calculeazaComision(100000.0f, m.comision); // exemplu tranzactie
    float intretinere = Apartament::calculeazaIntretinere(a.suprafata);
    return comisionPeTranzactie + intretinere;
}


int main() {

    cout << "=== IMOBIL ===" << endl;
    Imobil i1;
    Imobil i2("Str. Libertatii nr. 10");
    Imobil i3("Bd. Unirii nr. 5", 85.5, 2015);

    i1.afisare();
    i2.afisare();
    i3.afisare();


    Imobil i4 = i3;
    cout << "Copie Imobil (i4): ";
    i4.afisare();


    i1.setAdresa("Str. Noua nr. 1");
    i1.setSuprafata(60.0);
    i1.setAnConstructie(2008);
    cout << "i1 prin getteri: "
        << i1.getIdImobil() << " | "
        << i1.getAdresa() << " | "
        << i1.getSuprafata() << " | "
        << i1.getAnConstructie() << endl;

    cout << "Imobil nextId (static): " << Imobil::getNextId() << endl;

    cout << "\n=== MANDAT IMOBILIAR ===" << endl;
    MandatImobiliar m1;
    MandatImobiliar m2("Popescu Ana", "Vanzare");
    MandatImobiliar m3("Ionescu Mihai", "Inchiriere", 2.5, 90);

    m1.afisare();
    m2.afisare();
    m3.afisare();


    MandatImobiliar m4 = m3;
    cout << "Copie Mandat (m4): ";
    m4.afisare();


    m1.setProprietar("Ioana Maria Andreea");
    m1.setTipMandat("Vanzare");
    m1.setComision(3.0);
    m1.setDurataZile(120);

    cout << "m1 prin getteri: "
        << m1.getIdMandat() << " | "
        << m1.getProprietar() << " | "
        << m1.getTipMandat() << " | "
        << m1.getComision() << " | "
        << m1.getDurataZile() << endl;

    cout << "Mandat nextId (static): " << MandatImobiliar::getNextId() << endl;

    cout << "\n=== APARTAMENT ===" << endl;
    Apartament a1;
    Apartament a2("Studio");
    Apartament a3("2 camere", 3, true, 52.0);

    a1.afisare();
    a2.afisare();
    a3.afisare();


    Apartament a4 = a3;
    cout << "Copie Apartament (a4): ";
    a4.afisare();


    a1.setTip("Garsoniera");
    a1.setEtaj(1);
    a1.setAreBalcon(false);
    a1.setSuprafata(34.0);

    cout << "a1 prin getteri: "
        << a1.getIdApartament() << " | "
        << a1.getTip() << " | "
        << a1.getEtaj() << " | "
        << (a1.getAreBalcon() ? "DA" : "NU") << " | "
        << a1.getSuprafata() << endl;

    cout << "Apartament nextId (static): " << Apartament::getNextId() << endl;


    cout << "\nSuprafata totala (i3 + a3): " << suprafataTotala(i3, a3) << endl;
    cout << "Cost total mandat + intretinere (m3 + a3): " << costTotalMandatSiIntretinere(m3, a3) << endl;

    return 0;
}
