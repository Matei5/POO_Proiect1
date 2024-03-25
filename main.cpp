/*
 git push -u origin main
*/
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <unistd.h>

class Student{
private:
    int nr_dosar;
    std::string Nume;
    std::string Prenume;
    std::string InitialaTatalui;
    std::list<int> note;
    int medie;
    int nrRestante;
public:

    friend std::ostream& operator<<(std::ostream& os, const Student &s){

    }

private:

};

class Profesor{
private:
    int id_contract;
    std::string Nume;
    std::string Prenume;
    int anAngajare;
public:

private:

};

class Examen{
private:
    bool restanta;
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    float timpDeLucruInOre;
    int numarSubiecte;
public:

private:

};

class Materie{
private:
    std::string numeMaterie;
    std::list<Student> Studenti;
    Examen examen;
public:

    void contestatie(){

    }

private:

};

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
    std::cout << "|               Esti administrator? y/n:";
    char ans;
    std::cin >> ans;

    if(ans == 'y' || ans == 'Y'){
        std::cout << "\n|----------------------------------------------------|\n";
        std::cout << "| Introduce pinul de 4 cifre:\t";
        int pin;
        std::cin >> pin;
        if(pin == 1234) {
            std::cout << "\n";
            return admin();
        }
        else{
            std::cout << "\nGresit! ---Redirectionare catre meniu\n";
            sleep(2);
            return menu();
        }
    }
    else{
        std::cout << "\n---Redirectionare catre meniu\n";
        sleep(2);
        return menu();
    }

}

char load(){
    std::cout << "|----------------------------------------------------|\n";
    std::cout << "| Load file? (y/n): ";

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
