#include <unistd.h>
#include "header.h"

/// ===================== Constuctori ======================

Student::Student(std::string Nume_, std::string Prenume_, float nota_) : Nume(Nume_),Prenume(Prenume_),nota(nota_){}
Profesor::Profesor(std::string Nume_, std::string Prenume_, std::string email_) : Nume(Nume_), Prenume(Prenume_), email(email_){}
Examen::Examen(int zi_, int luna_, int an_, int ora_, int timpDeLucruInOre_, int nrSubiecte_) : an(an_),
                    luna(luna_), zi(zi_),ora(ora_), timpDeLucruInOre(timpDeLucruInOre_), nrSubiecte(nrSubiecte_){}
Materie::Materie(std::string numeMaterie_, int an_, int semestru_, std::vector<Student> Studenti_, Examen examen_, Profesor profesor) : an(an_),
                    semestru(semestru_), numeMaterie(numeMaterie_), Studenti(Studenti_), examen(examen_), cadruDidactic(profesor){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Student &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
        << " // Nota: " << s.nota << " // Are restanta?: ";
    if(s.restanta) os << "Da";
    else os << "Nu";
    os << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Profesor &p){
    os << "Profesor: " << "Nume & Prenume: " << p.Nume << " " << p.Prenume << " // Email: " << p.email << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Examen &e){
    os << "Examen: " << "Data: " << e.zi << "." << e.luna << "." << e.an << " la ora " << e.ora/100 << ":" << e.ora%100
        << " // Timp de lucru: " << e.timpDeLucruInOre << " // Numar de subiecte: " << e.nrSubiecte << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Materie &m){
    os << "Materie: " << "Denumire: " << m.numeMaterie << " // An: " << m.an << "; Sem: " << m.semestru
            << "\n          // Cadru didactic: " << m.cadruDidactic
            << "\n          // Examen: " << m.examen
            << "\n          // Studenti: " ;
            for(const Student &stud: m.Studenti){
                os << stud;
            }
    return os;
}
/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, Student &s){

    std::cout << "Student: Nume:";
    is >> s.Nume;
    std::cout << "Prenume:";
    is >> s.Prenume;
    std::cout << "Nota:";
    is >> s.nota;
    return is;
}
std::istream& operator>>(std::istream& is, Profesor &p){

    std::cout << "Profesor: Nume:";
    is >> p.Nume;
    std::cout << "Prenume:";
    is >> p.Prenume;
    std::cout << "Email:";
    is >> p.email;
    return is;
}
std::istream& operator>>(std::istream& is, Examen &e){

    std::cout << "Examen: Zi:";
    is >> e.zi;
    std::cout << "Luna:";
    is >> e.luna;
    std::cout << "An:";
    is >> e.an;
    std::cout << "Ora (in format militar):";
    is >> e.ora;
    std::cout << "Minute de lucru:";
    is >> e.timpDeLucruInOre;
    std::cout << "Numar de subiecte:";
    is >> e.nrSubiecte;

    return is;
}
std::istream& operator>>(std::istream& is, Materie &m){

    std::cout << "Materie: Nume(legat):";
    is >> m.numeMaterie;
    std::cout << "An:";
    is >> m.an;
    std::cout << "Semestru:";
    is >> m.semestru;
    is >> m.cadruDidactic;
    is >> m.examen;

    int n; Student temp;
    std::cout << "Cati studenti sunt in clasa?:";
    std::cin >> n;
    std::cout << "\n";

    for(int i=0;i<n;i++){
        is >> temp;
        m.Studenti.push_back(temp);
        std::cout << "\n";
    }

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
    Studenti.clear();
}

/// ====================== Alte functii =====================

bool Student::areRestanta() const{
    bool rest = false;
    if(this->nota < 5) rest = true;
    return rest;
}

void Materie::contestatie(int nrStud) {
    float random = rand()%200;
    float prevNota = Studenti[nrStud].getNota();
    Studenti[nrStud].setNota(prevNota + (random - 100)/100);
}

int Materie::getNumarStudenti(){ return Studenti.size();}
std::string Materie::getEmailProfesor(){ return cadruDidactic.getEmail();}
int Materie::getNotaStudent(int n){ return Studenti[n].getNota();}
void Materie::setNotaStudent(int n,int nota2){ Studenti[n].setNota(nota2);}
void Materie::schimbareProfesor(const Profesor &prof) { cadruDidactic = prof;}
Materie Materie::operator+=(const Student &s) {
    Studenti.push_back(s);
    return *this;
}

std::string Profesor::getEmail(){ return email;}
float Student::getNota() const { return nota;}
void Student::setNota(float n) { nota = n; }


/// ======================== Fara legatura cu clasele =======================

void restanta(){

}

int menu(){
    std::cout << "| OPTIUNI: \n";
    std::cout << "| 1. Nota\n";
    std::cout << "| 2. Contenstatie\n";
    std::cout << "| 3. Participa la examenul de restanta\n";
    std::cout << "| 4. Email profesor\n";
    std::cout << "| 6. Schimba student\n";
    std::cout << "| 7. Print POO\n";
    std::cout << "| 8. Adauga student\n";
    std::cout << "| 9. Exit\n";
    std::cout << "|>-------------------------\n";
    std::cout << "| Introduce numarul optiunii dorite: ";

    int n;
    std::cin >> n;
    std::cout << "\n";

    return n;
}

char load(){
    std::cout << "|>-------------------------\n";
    std::cout << "| Load file? (y/n):";

    char ans;
    std::cin >> ans;
    std::cout << "\n";

    switch(ans){
        case 'y': return ans;
        case 'n': return ans;
        case 'Y': return 'y';
        case 'N': return 'n';
        default:
            std::cout << "| Error: Caracter introdus nerecunoscut\n";
            return load();
    }
}

int main() {

    int an = 2004;
    char a = load();

    Materie POO = Materie();
    if (a == 'y') {
        std::cin >> POO;
    }

    int nrStudent = -1;
    while (nrStudent == -1 && a == 'y') {
        std::cout << "|>-------------------------\n";
        std::cout << "| Introduce numarul studentului (0-" << POO.getNumarStudenti() - 1
                  << "):";

        std::cin >> nrStudent;

        if (nrStudent < 0 || nrStudent > POO.getNumarStudenti()) {
            std::cout << "| Error: Cod introdus nerecunoscut\n";
            nrStudent = -1;
        }
    }

    int option=-1;

    while (option != 9) {
        option = menu();
        switch (option) {
            case 1: {
                std::cout << "Nota studentului este: " << POO.getNotaStudent(nrStudent) << "\n";
            }
                break;
            case 2: {
                POO.contestatie(nrStudent);
                std::cout << "Nota noua: " << POO.getNotaStudent(nrStudent) << "\n";
            }
                break;
            case 3: {
                restanta();
            }
                break;
            case 4: {
                std::cout << POO.getEmailProfesor() << "\n";
            }
                break;
            case 6:{
                while (nrStudent == -1 && a == 'y') {
                    std::cout << "|>-------------------------\n";
                    std::cout << "| Introduce numarul studentului (0-" << POO.getNumarStudenti() - 1
                              << "):";

                    std::cin >> nrStudent;

                    if (nrStudent < 0 || nrStudent > POO.getNumarStudenti()) {
                        std::cout << "| Error: Cod introdus nerecunoscut\n";
                        nrStudent = -1;
                    }
                }
            }
                break;
            case 7: {
                std::cout << POO << "\n";
            }
                break;
            case 8: {
                Student newStudent = Student();
                std::cin >> newStudent;
                POO += newStudent;
            }
                break;
            case 9: {}
                break;
            default: {
                std::cout << "| Error: Numar introdus nerecunoscut\n";
                option = menu();
            }
        }

        char ans = 'a';

        while(ans == 'a'){
            std::cout << "|>-------------------------\n";
            std::cout << "| Mai doresti sa faci vreo actiune? (y/n):";
            std::cin >> ans;
            std::cout << "\n";

            switch (ans) {
                case 'y': break;
                case 'n': {
                    option = 9;
                }
                    break;
                case 'Y': break;
                case 'N': {
                    option = 9;
                }
                    break;
                default: {
                    std::cout << "| Error: Caracter introdus nerecunoscut\n";
                    ans = 'a';
                }
            }
        }
    }

    return 0;
}


/*
 git push -u origin main
*/