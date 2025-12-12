#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Carte {
    private:  //accesibil DOAR in interorul clasei. alte functii din afara nu poate atinge acel atribut, numai metodele clasei au voie 
        const int idCarte;  // constanta
        static int nextId;  // static

    protected:  //ca private, dar cu un avantaj: este accesibil in alte clase derivate (mostenite)
        string titlu;
        string autor;
        int anAparitie;
        int nrExemplar;

    public:  //accesibil de oriunde. poti accesa acel atribut/metoda din exteriorul clasei, din main, din alte clase, din functii, de oriunde.
        
        // CONSTRUCTOR FARA PARAMETRII
        //este o functie speciala din clasa, are acelasi nume ca si clasa, nu are tip de return (nu scrii void, int, nimic) se apeleaza atomat cand creezi un obiect.

        Carte() : idCarte(++nextId) {
            titlu ="Necunoscut";
            autor ="Necunoscut";
            anAparitie = 0;
            nrExemplar = 0;
        }

        // CONSTRUCTOR CU PARAMETRII
        //este o functie speciala a clasei, are acelasi nume ca si clasa, primeste parametrii de la utilizator, initializeaza obiectul cu valori specifice, nu default.
        //daca am constanta in clasa, trebuie initializata in lista de initializare a constructorului
        //folosim this-> pentru a face diferenta intre atributul clasei si parametrul functiei (cand au acelasi nume)
        //this->numeAtribut = numeAtribut - atributul clasei (la stânga) - parametrul constructorului (la dreapta) - Atributul obiectului = valoarea primită ca parametru

        Carte(string titlu, string autor, int anAparitie, int nrExemplar) 
            : idCarte(++nextId)  //initializam const-ul
        {
            this->titlu = titlu;        //atributul clasei = parametrul constructorului
            this->autor = autor;
            this->anAparitie = anAparitie;
            this->nrExemplar = nrExemplar;
        }

        // CONSTRUCTOR DE COPIERE
        //este o functie speciala a clasei care se apeleaza atomat atunci cand cream un obiect nou din alt obiect. Copiaza toate atributele din obiectul original in cel nou 
        //are ca parametru o referinta la un obiect de acelasi tip. dacă am atribute const, se inițializează în lista de inițializare.

        Carte(const Carte& carteOriginala)
            : idCarte(++nextId)   //initializam const-ul //fiecare obiect copiat primeste un id nou
        {
            // copiez doar ce vreau
            this->titlu = carteOriginala.titlu;
            this->autor = carteOriginala.autor;
            // restul rămân special pentru obiectul nou
            this->anAparitie = 2025;
            this->nrExemplar = 6;
        }

        // DESTRUCTOR
        //este o functie speciala a clasei care se apeleaza automat atunci cand un obiect iese din scope (se termina executia in main sau iese dintr o functie)
        //are acelasi nume ca si clasa, dar cu ~ in fata, nu are parametrii si nu returneaza nimic
        //este folosit pentru a elibera memoria alocata in HEAP (daca exista pointeri in clasa)
        
        ~Carte() {
            // nu avem pointeri, nu eliberam nimic
            // destructorul este totusi necesar pentru structura proiectukui
        }
 
        // SET-ERI + GET 
        //GETTER este o funcție publică prin care CITEȘTI (obții) valoarea unui atribut privat din clasă.
        // getAtribut() const { return atribut; }
        //SETTER este o funcție publică prin care MODIFICI valoarea unui atribut privat.
        // setAtribut(tip valoareNoua) { atribut = valoareNoua; }

        //tip getAtribut() const { return atribut; }
        //void setAtribut(tip val) { this->atribut = val; }

        //GETTER & SETTER pentru TITLU

        string getTitlu() const {
            return this->titlu;
        }

        void setTitlu(string titluNou) {
            if (titluNou.length() > 0) {
                this->titlu = titluNou;
            }
        }

        //GETTER & SETTER pentru AUTOR

        string getAutor() const {
            return this->autor;
      }
      void setAutor(string autorNou) {
          if (autorNou.length() > 0) 
              this->autor = autorNou;
          }
      
        //GETTER & SETTER pentru AN APARITIE

        int getAnAparitie() const {
            return this->anAparitie;
        }

        void setAnAparitie(int anNou) {
            if (anNou > 0) {
                this->anAparitie = anNou;
            }
        }

        //GETTER & SETTER pentru NR EXEMPLARE

        int getNrExemplar() const {
            return this->nrExemplar;
        }

        void setNrExemplar(int nrNou) {
            if (nrNou >=0) {
                this->nrExemplar = nrNou;
            }
        }

        //GHETTER PENTRU ID (ATRIBUT CONSTANT)
        //Id-ul este constant, deci nu are SETTER, doar GETTER

        int getIdCarte() const {
            return this->idCarte;
        }


        //SUPRAINCARCAREA OPERATORULUI DE AFISARE
        // supraincarcarea operatorului << pentru afisarea obiectelor de tip Carte
        // functia este declarata friend pentru a avea acces la atributele private si protected
        

        friend ostream& operator<<(ostream& out, const Carte& c);

        //METODE PENTRU SALVARE SI INCARCARE BINARA

        void salveazaBinar(ofstream& out) const;
        void incarcaBinar(ifstream& in);


};
         // INITIALIZARE STATIC 
         // atribut static al clasei Carte
         // se defineste si se initializeaza in afara clasei

         int Carte::nextId = 0; // obligatoriu pentru a aloca memorie atributului static

         // DEFINITIE SUPRAINCARCARE OPERATOR <<
         // implementarea operatorului << supraincarcat
         // permite afisarea obiectelor de tip Carte folosind cout

         ostream& operator<<(ostream& out, const Carte& c) {
               out << "Carte ID: " << c.idCarte
                   << " | Titlu: " << c.titlu
                   << " | Autor: " << c.autor
                   << " | An: " << c.anAparitie
                   << " | Nr exemplare: " << c.nrExemplar;
            return out;
}

         // DEFINITIE METODE SALVARE SI INCARCARE BINARA
         
         void Carte::salveazaBinar(ofstream& out) const {
              size_t len = titlu.size();
              out.write((char*)&len, sizeof(len));
              out.write(titlu.c_str(), len);
          
              len = autor.size();
              out.write((char*)&len, sizeof(len));
              out.write(autor.c_str(), len);
          
              out.write((char*)&anAparitie, sizeof(anAparitie));
              out.write((char*)&nrExemplar, sizeof(nrExemplar));
}          

        void Carte::incarcaBinar(ifstream& in) {
            size_t len = 0;
        
            in.read((char*)&len, sizeof(len));
            titlu.resize(len);
            in.read(&titlu[0], len);
        
            in.read((char*)&len, sizeof(len));
            autor.resize(len);
            in.read(&autor[0], len);
        
            in.read((char*)&anAparitie, sizeof(anAparitie));
            in.read((char*)&nrExemplar, sizeof(nrExemplar));
        }


        int main() {

              Carte c1("Ion", "Liviu Rebreanu", 1920, 4);

              ofstream fout("carte.bin", ios::binary);
              c1.salveazaBinar(fout);
              fout.close();

              Carte c2; //alt obiect
              ifstream fin("carte.bin", ios::binary);
              c2.incarcaBinar(fin);
              fin.close();

              cout << c1 << endl;
              cout << c2 << endl;

              return 0;
}




        


