#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>   

using namespace std;

class Pix {
private:
    char* brand;           
    string tipPix;         
    string culoareScris;   
    int lungime;           
    float pret;            
    bool areCapac;         

public:
    // Constructor fara parametri
    Pix() {
        this->brand = nullptr;
        this->tipPix = "Necunoscut";
        this->culoareScris = "Necunoscuta";
        this->lungime = 0;
        this->pret = 0;
        this->areCapac = false;
    }

    // Constructor cu parametri
    Pix(const char* brand, string tipPix, string culoareScris, int lungime, float pret, bool areCapac) {

        if (brand != nullptr) {
            this->brand = new char[strlen(brand) + 1];
            strcpy(this->brand, brand);
        }
        else {
            this->brand = nullptr;
        }

        this->tipPix = tipPix;
        this->culoareScris = culoareScris;
        this->lungime = lungime;
        this->pret = pret;
        this->areCapac = areCapac;
    }

    // Constructor de copiere
    Pix(const Pix& p) {

        if (p.brand != nullptr) {
            this->brand = new char[strlen(p.brand) + 1];
            strcpy(this->brand, p.brand);
        }
        else {
            this->brand = nullptr;
        }

        this->tipPix = p.tipPix;
        this->culoareScris = p.culoareScris;
        this->lungime = p.lungime;
        this->pret = p.pret;
        this->areCapac = p.areCapac;
    }

    // Destructor
    ~Pix() {
        if (this->brand != nullptr) {
            delete[] this->brand;
        }
    }


    // SET + GET 
    void setBrand(const char* brandNou) {
        if (brandNou != nullptr && strlen(brandNou) > 0) {

            if (this->brand != nullptr) {
                delete[] this->brand;
            }

            this->brand = new char[strlen(brandNou) + 1];
            strcpy(this->brand, brandNou);
        }
    }

    char* getBrand() {
        return this->brand;
    }


    void setPret(float pretNou) {
        if (pretNou > 0) {
            this->pret = pretNou;
        }
    }

    float getPret() {
        return this->pret;
    }


    // Afisare
    void afisarePix() {
        cout << endl << "Pix ";

        if (this->brand != nullptr) {
            cout << this->brand;
        }
        else {
            cout << "(Brand necunoscut)";
        }

        cout << ", tip: " << this->tipPix;
        cout << ", culoare scris: " << this->culoareScris;
        cout << ", lungime: " << this->lungime << " cm";
        cout << ", pret: " << this->pret << " lei";
        cout << ", capac: ";
        if (this->areCapac) {
            cout << "DA";
        }
        else {
            cout << "NU";
        }
    }
};

int main() {

    Pix p1;
    p1.setBrand("BIC");
    p1.setPret(5.99);
    p1.afisarePix();

    Pix p2("Faber-Castell", "Gel", "Negru", 14, 12.5, true);
    p2.afisarePix();

    Pix p3 = p2;
    p3.setBrand("Faber-Castell Premium");
    p3.setPret(19.99);
    p3.afisarePix();

    cout << endl << endl;
    return 0;
}
