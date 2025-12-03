#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>   

using namespace std;

class Medicament {
private:
    char* denumire = nullptr;
    string producator = "Necunoscut";
    float pret = 0;
    int nrComprimate = 0;
    bool esteCompensat = false;

public:
    // Constructor fara parametri
    Medicament() {
        
    }

    // Constructor cu parametri
    Medicament(const char* denumire, string producator,
        float pret, int nrComprimate, bool esteCompensat) {

        this->producator = producator;
        this->pret = pret;
        this->nrComprimate = nrComprimate;
        this->esteCompensat = esteCompensat;

        if (denumire != nullptr) {
            this->denumire = new char[strlen(denumire) + 1];
            strcpy(this->denumire, denumire);   
        }
    }

    // Destructor
    ~Medicament() {
        if (this->denumire != nullptr) {
            delete[] this->denumire;
        }
    }

    // Constructor de copiere
    Medicament(const Medicament& copie) {
        this->producator = copie.producator;
        this->pret = copie.pret;
        this->nrComprimate = copie.nrComprimate;
        this->esteCompensat = copie.esteCompensat;

        if (copie.denumire != nullptr) {
            this->denumire = new char[strlen(copie.denumire) + 1];
            strcpy(this->denumire, copie.denumire);
        }
        else {
            this->denumire = nullptr;
        }
    }

    // Metoda de afisare
    void afisareMedicament() {
        cout << endl << "Medicament: ";
        if (this->denumire != nullptr) {
            cout << this->denumire;
        }
        else {
            cout << "Necunoscut";
        }

        cout << ", producator: " << this->producator;
        cout << ", pret: " << this->pret << " lei";
        cout << ", numar comprimate: " << this->nrComprimate;
        cout << ", este compensat: ";
        if (this->esteCompensat) {
            cout << "DA";
        }
        else {
            cout << "NU";
        }
    }

    void setPret(float pretNou) {
        if (pretNou > 0) {
            this->pret = pretNou;
        }
    }

    float getPret() {
        return this->pret;
    }

    void setDenumire(const char* denumireNoua) {
        if (denumireNoua != nullptr && strlen(denumireNoua) > 0) {
            if (this->denumire != nullptr) {
                delete[] this->denumire;
            }
            this->denumire = new char[strlen(denumireNoua) + 1];
            strcpy(this->denumire, denumireNoua);
        }
    }

    char* getDenumire() {
        return this->denumire;
    }
};

int main() {

    Medicament m1;
    m1.setDenumire("Paracetamol");
    m1.setPret(12.5);      
    m1.afisareMedicament();

    Medicament m2("Nurofen", "Reckitt", 25.3, 24, true);
    m2.afisareMedicament();

    Medicament m3 = m2;
    m3.setDenumire("Nurofen Forte");
    m3.setPret(30.75);
    m3.afisareMedicament();

    cout << endl << endl;
    return 0;
}
