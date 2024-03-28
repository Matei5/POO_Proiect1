#include "header.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>

/// ===================== Constuctori ======================

Student::Student(int nr_dosar_, std::string Nume_, std::string Prenume_, std::list<int> note_) : nr_dosar(nr_dosar_),
                    Nume(Nume_),Prenume(Prenume_),note(note_){}
Profesor::Profesor(int id_contract_, std::string Nume_, std::string Prenume_, int anAngajare_) : id_contract(id_contract_),
                    Nume(Nume_), Prenume(Prenume_), anAngajare(anAngajare_){}
Examen::Examen(std::string numeMaterie_, int an_, int luna_, int zi_, int ora_, float timpDeLucruInOre_, int nrSubiecte_) : an(an_),
                    numeMaterie(numeMaterie_), luna(luna_), zi(zi),ora(ora_), timpDeLucruInOre(timpDeLucruInOre_), nrSubiecte(nrSubiecte_){}
Materie::Materie(std::string numeMaterie_, int an_, int semestru_, std::list<Student> Studenti_, Examen examen_, Profesor profesor) : an(an_),
                    semestru(semestru_), numeMaterie(numeMaterie_), Studenti(Studenti_), examen(examen_), cadruDidactic(profesor){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Student &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume << " // Nr. Dosar: " << s.nr_dosar
        << "\n          // Note: ";
    for(int Nota : s.note){
        os << Nota << " ";
    }
    std:: cout << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Profesor &p){
    os << "Profesor: " << "Nume & Prenume: " << p.Nume << " " << p.Prenume << " // Id_contract: " << p.id_contract
        << "\n          // Anul in care a fost angajat: " << p.anAngajare << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Examen &e){
    os << "Examen: " << "Numele Materiei: " << e.numeMaterie << " // Data: " << e.zi << "." << e.luna << "." << e.an << " la ora " << e.ora/100 << ":" << e.ora%100
        << "\n          // Timp de lucru: " << e.timpDeLucruInOre << " // Numar de subiecte: " << e.nrSubiecte << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Materie &m){
    os << "Materie: " << "Denumire: " << m.numeMaterie << " // An: " << m.an << "; Sem: " << m.semestru
            << "\n          // Cadru didactic: " << m.cadruDidactic
            << "\n          // Examen: " << m.examen
            << "\n          // Studenti: " ;
            for(Student stud: m.Studenti){
                os << stud;
            }
    return os;
}
/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, const Student &s){

    return is;
}
std::istream& operator>>(std::istream& is, const Profesor &p){

    return is;
}
std::istream& operator>>(std::istream& is, const Examen &e){

    return is;
}
std::istream& operator>>(std::istream& is, const Materie &m){

    return is;
}


/// ===================== Destructori ======================
Student::~Student() {

}
Profesor::~Profesor() {

}
Examen::~Examen() {

}
Materie::~Materie() {

}

/// ====================== Alte functii =====================

float Student::mediaEste(){
    float medie = 0;
    int nrNote = 0;


    return medie/nrNote;
}

int Student::nrRestanteEste(){
    int nrRestante = 0;

    return nrRestante;
}

void Materie::contestatie() {

}

/// ======================== Fara legatura cu clasele =======================

void adaugare(){

}
void extragere(){

}
void schimbare(){

}

void contestatie(){

}

int admin(){
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "|     Bine ai venit in baza de date a materiilor!    |\n";
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "|===================== OPTIUNI ======================|\n";
    std::cout << "| Pentru:                 | Introduce:               |\n";
    std::cout << "| Adaugare de informatii  | 1                        |\n";
    std::cout << "| Extragere de informatii | 2                        |\n";
    std::cout << "| Schimbare de informatii | 3                        |\n";
    std::cout << "| Exit                    | 4                        |\n";
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "|\nV\n";
    int n;
    std::cin >> n;

    switch(n){
        case 1: return 11;
        case 2: return 12;
        case 3: return 13;
        case 4: return 4;
        default:
            std::cout << "\n\nError: Numar introdus nerecunoscut\n";
            return admin();
    }

}

int menu(){
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "|        Bine ai venit in meniul materiilor!         |\n";
    std::cout << "|                                                    |\n";
    std::cout << "|===================== OPTIUNI ======================|\n";
    std::cout << "| Pentru:                 | Introduce:               |\n";
    std::cout << "| Rezultate               | 1                        |\n";
    std::cout << "| Restanta                | 2                        |\n";
    std::cout << "| Contenstatie            | 3                        |\n";
    std::cout << "| Exit                    | 4                        |\n";
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "| ?= ";
    int n;
    std::cin >> n;

    switch(n){
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        default:
            std::cout << "\n\nError: Numar introdus nerecunoscut\n";
            return menu();
    }
}


int log(){

    std::cout << "|----------------------------------------------------|\n";
    std::cout << "|               Esti administrator? (y/n):";
    char ans;
    std::cin >> ans;

    if(ans == 'y' || ans == 'Y'){
        std::cout << "\n|----------------------------------------------------|\n";
        std::cout << "| Introduce pinul de 4 cifre:";
        int pin;
        std::cin >> pin;
        if(pin == 1234) {
            std::cout << "\n";
            return admin();
        }
        else{
            std::cout << "\nGresit! ---Redirectionare catre meniu\n";
            sleep(1);
            return menu();
        }
    }
    else{
        std::cout << "\n---Redirectionare catre meniu\n";
        sleep(1);
        return menu();
    }

}

char load(){
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "Load file? (y/n):";

    char ans;
    std::cin >> ans;

    return ans;
}

int main() {

    std::cout << Student();
    std::cout << Profesor();
    std::cout << Examen();
    std::cout << Materie();

//    int an = 2004;
//    char a = load();
//    std::cout << "woop woop, no loading function found\n";
//
//    int option = log(); // options: 1,2,3, ,11,12,13
//
//    if(option == 4) return 0;
//
//    if(option == 1){
//
//    }
//
//    return 0;
}


/*
 git push -u origin main
*/