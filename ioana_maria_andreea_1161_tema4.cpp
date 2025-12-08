#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Pisica {
private:
    char* nume;        
    string rasa;       
    string culoare;    
    int varsta;        
    float greutate;    
    bool esteSterilizata;

public:

// CONSTRUCTOR FARA PARAMETRI
    Pisica() {
        this->nume = nullptr;
        this->rasa = "Necunoscuta";
        this->culoare = "Indefinita";
        this->varsta = 0;
        this->greutate = 0.0f;
        this->esteSterilizata = false;
    }

// CONSTRUCTOR CU PARAMETRI
    Pisica(const char* nume, string rasa, string culoare,
           int varsta, float greutate, bool sterila) 
    {
        if (nume != nullptr) {
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);
        } else {
            this->nume = nullptr;
        }

        this->rasa = rasa;
        this->culoare = culoare;
        this->varsta = varsta;
        this->greutate = greutate;
        this->esteSterilizata = sterila;
    }

// CONSTRUCTOR DE COPIERE
    Pisica(const Pisica& p) {

        if (p.nume != nullptr) {
            this->nume = new char[strlen(p.nume) + 1];
            strcpy(this->nume, p.nume);
        } else {
            this->nume = nullptr;
        }

        this->rasa = p.rasa;
        this->culoare = p.culoare;
        this->varsta = p.varsta;
        this->greutate = p.greutate;
        this->esteSterilizata = p.esteSterilizata;
    }

// DESTRUCTOR
    ~Pisica() {
        if (this->nume != nullptr) {
            delete[] this->nume;
        }
    }

// SET-ERI + GET
    void setNume(const char* numeNou) {
        if (numeNou != nullptr && strlen(numeNou) > 0) {

            if (this->nume != nullptr) {
                delete[] this->nume;
            }

            this->nume = new char[strlen(numeNou) + 1];
            strcpy(this->nume, numeNou);
        }
    }

    char* getNume() {
        return this->nume;
    }

    void setGreutate(float gNoua) {
        if (gNoua > 0) {
            this->greutate = gNoua;
        }
    }

    float getGreutate() {
        return this->greutate;
    }

// METODA DE AFISARE
    void afisarePisica() {
        cout << endl << "Pisica ";

        if (this->nume != nullptr) {
            cout << "'" << this->nume << "'";
        } else {
            cout << "(fara nume)";
        }

        cout << " | Rasa: " << this->rasa;
        cout << " | Culoare: " << this->culoare;
        cout << " | Varsta: " << this->varsta << " ani";
        cout << " | Greutate: " << this->greutate << " kg";
        cout << " | Sterilizata: " << (this->esteSterilizata ? "Da" : "Nu");
    }
};

int main() {


    Pisica c1;
    c1.setNume("Tom");
    c1.setGreutate(4.2);
    c1.afisarePisica();


    Pisica c2("Sacu", "Scottish Fold", "Tigrat", 6, 5, true);
    c2.afisarePisica();


    Pisica c3 = c2;
    c3.setNume("Tomita");
    c3.setGreutate(3.8);
    c3.afisarePisica();

    cout << endl << endl;
    return 0;
}
