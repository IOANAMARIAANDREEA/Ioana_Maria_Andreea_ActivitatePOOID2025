#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Pom {
private:
    char* specie;         
    string tipPom;        
    string culoareFrunze; 
    int inaltime;         
    float varsta;         
    bool esteFructifer;   

public:

// Constructor fara parametri
    Pom() {
        this->specie = nullptr;
        this->tipPom = "Necunoscut";
        this->culoareFrunze = "Necunoscuta";
        this->inaltime = 0;
        this->varsta = 0;
        this->esteFructifer = false;
    }

// Constructor cu parametri
    Pom(const char* specie, string tipPom, string culoareFrunze, int inaltime, float varsta, bool esteFructifer) {

        if (specie != nullptr) {
            this->specie = new char[strlen(specie) + 1];
            strcpy(this->specie, specie);
        }
        else {
            this->specie = nullptr;
        }

        this->tipPom = tipPom;
        this->culoareFrunze = culoareFrunze;
        this->inaltime = inaltime;
        this->varsta = varsta;
        this->esteFructifer = esteFructifer;
    }

// Constructor de copiere
    Pom(const Pom& p) {
        if (p.specie != nullptr) {
            this->specie = new char[strlen(p.specie) + 1];
            strcpy(this->specie, p.specie);
        }
        else {
            this->specie = nullptr;
        }

        this->tipPom = p.tipPom;
        this->culoareFrunze = p.culoareFrunze;
        this->inaltime = p.inaltime;
        this->varsta = p.varsta;
        this->esteFructifer = p.esteFructifer;
    }

// Destructor
    ~Pom() {
        if (this->specie != nullptr) {
            delete[] this->specie;
        }
    }

// SET + GET 
    void setSpecie(const char* specieNoua) {
        if (specieNoua != nullptr && strlen(specieNoua) > 0) {

            if (this->specie != nullptr) {
                delete[] this->specie;
            }

            this->specie = new char[strlen(specieNoua) + 1];
            strcpy(this->specie, specieNoua);
        }
    }

    char* getSpecie() {
        return this->specie;
    }


    void setVarsta(float varstaNoua) {
        if (varstaNoua >= 0) {
            this->varsta = varstaNoua;
        }
    }

    float getVarsta() {
        return this->varsta;
    }

// Afisare
    void afisarePom() {
        cout << endl << "Pom ";

        if (this->specie != nullptr) {
            cout << this->specie;
        }
        else {
            cout << "(Specie necunoscuta)";
        }

        cout << ", tip: " << this->tipPom;
        cout << ", culoare frunze: " << this->culoareFrunze;
        cout << ", inaltime: " << this->inaltime << " m";
        cout << ", varsta: " << this->varsta << " ani";
        cout << ", fructifer: ";
        if (this->esteFructifer) {
            cout << "DA";
        }
        else {
            cout << "NU";
        }
    }
};

int main() {

    Pom pom1;
    pom1.setSpecie("Mar");
    pom1.setVarsta(5);
    pom1.afisarePom();

    Pom pom2("Cires", "Fructifer", "Verde", 3, 2.5, true);
    pom2.afisarePom();

    Pom pom3 = pom2;
    pom3.setSpecie("Cires Japonez");
    pom3.setVarsta(4);
    pom3.afisarePom();

    cout << endl << endl;
    return 0;
}
