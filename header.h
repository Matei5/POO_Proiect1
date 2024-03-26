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
    Profesor(int id_contract = 0, std::string Nume = "", std::string Prenume = "", int anAngajare=0);

    friend std::ostream& operator<<(std::ostream& os, const Profesor &p);
    friend std::istream& operator>>(std::istream& is, const Profesor &p);

    ~Profesor();

private:

};

class Examen{
private:
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    float timpDeLucruInOre;
    int nrSubiecte;
public:
    Examen(int an = 0, int luna = 0, int zi = 0, int ora = 0, float timpDeLucruInOre = 0, int nrSubiecte = 0);

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
public:
    Materie(int an = 0, int semestru = 0, std::string numeMaterie = "", std::list<Student> Studenti = {}, Examen examen = Examen());

    friend std::ostream& operator<<(std::ostream& os, const Materie &m);
    friend std::istream& operator>>(std::istream& is, const Materie &m);

    ~Materie();

    void contestatie();

private:

};

#endif //PROIECT1_HEADER_H
