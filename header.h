#ifndef PROIECT1_HEADER_H
#define PROIECT1_HEADER_H
#include <iostream>
#include <list>

class Student{
private:
    int nr_dosar;
    std::string Nume;
    std::string Prenume;
    std::list<int> note;
    int medie = mediaEste();
    int nrRestante = nrRestanteEste();
public:
    Student(int nr_dosar = 0, std::string Nume = "", std::string Prenume = "", std::list<int> note= {});

    friend std::ostream& operator<<(std::ostream& os, const Student &s);
    friend std::istream& operator>>(std::istream& is, const Student &s);

    ~Student();

private:
    float mediaEste();
    int nrRestanteEste();
};

class Profesor{
private:
    int id_contract;
    std::string Nume;
    std::string Prenume;
    int anAngajare;
public:
    Profesor(int id_contract_ = 0, std::string Nume_ = "", std::string Prenume_ = "", int anAngajare_=0);

    friend std::ostream& operator<<(std::ostream& os, const Profesor &p);
    friend std::istream& operator>>(std::istream& is, const Profesor &p);

    ~Profesor();

private:

};

class Examen{
private:
    std::string numeMaterie;
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    float timpDeLucruInOre;
    int nrSubiecte;
public:
    Examen(std::string numeMaterie = "", int an_ = 0, int luna_ = 0, int zi_ = 0, int ora_ = 0, float timpDeLucruInOre_ = 0, int nrSubiecte_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const Examen &e);
    friend std::istream& operator>>(std::istream& is, const Examen &e);

    ~Examen();

private:

};

class Materie{
private:
    int an;
    int semestru;
    std::string numeMaterie;
    std::list<Student> Studenti;
    Examen examen;
    Profesor cadruDidactic;
public:
    Materie(std::string numeMaterie_ = "", int an_ = 0, int semestru_ = 0,  std::list<Student> Studenti_ = {},
            Examen examen_ = Examen(), Profesor profesor = Profesor());

    friend std::ostream& operator<<(std::ostream& os, const Materie &m);
    friend std::istream& operator>>(std::istream& is, const Materie &m);

    ~Materie();

    void contestatie();

private:

};

#endif //PROIECT1_HEADER_H
