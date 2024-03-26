#include "header.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>

/// ===================== Constuctori ======================

Student::Student(int nr_dosar, std::string Nume, std::string Prenume, std::list<int> note){

}
Profesor::Profesor(int id_contract, std::string Nume, std::string Prenume, int anAngajare){

}
Examen::Examen(int an, int luna, int zi, int ora, float timpDeLucruInOre, int nrSubiecte){

}
Materie::Materie(int an, int semestru, std::string numeMaterie, std::list<Student> Studenti, Examen examen){

}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Student &s){

    return os;
}
std::ostream& operator<<(std::ostream& os, const Profesor &p){

    return os;
}
std::ostream& operator<<(std::ostream& os, const Examen &e){

    return os;
}
std::ostream& operator<<(std::ostream& os, const Materie &m){

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
    std::cout << "|                   Load file? (y/n):";

    char ans;
    std::cin >> ans;

    return ans;
}

int main() {

    int an = 2004;
    char a = load();


    int option = log(); // options: 1,2,3, ,11,12,13

    if(option == 4) return 0;

    if(option == 1){

    }

    return 0;
}


/*
 git push -u origin main
*/