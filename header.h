#ifndef PROIECT1_HEADER_H
#define PROIECT1_HEADER_H
#include <iostream>
#include <vector>
#include <cstdlib>

class Student{
private:
    std::string Nume;
    std::string Prenume;
    float nota;
    bool restanta = areRestanta();
public:
    Student(std::string Nume = "", std::string Prenume = "", float nota_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const Student &s);
    friend std::istream& operator>>(std::istream& is, Student &s);

    float getNota() const;
    void setNota(float n);

    ~Student();

private:
    bool areRestanta() const;
};

class Profesor{
private:
    std::string Nume;
    std::string Prenume;
    std::string email;
public:
    Profesor(std::string Nume_ = "", std::string Prenume_ = "", std::string email = "");

    friend std::ostream& operator<<(std::ostream& os, const Profesor &p);
    friend std::istream& operator>>(std::istream& is,  Profesor &p);

    std::string getEmail();

    ~Profesor();

private:

};

class Examen{
private:
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    int timpDeLucruInOre;
    int nrSubiecte;
public:
    Examen(int zi_ = 0, int luna_ = 0, int an_ = 0, int ora_ = 0, int timpDeLucruInOre_ = 0, int nrSubiecte_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const Examen &e);
    friend std::istream& operator>>(std::istream& is,  Examen &e);

    ~Examen();

private:

};

class Materie{
private:
    int an;
    int semestru;
    std::string numeMaterie;
    std::vector<Student> Studenti;
    Examen examen;
    Examen restanta;
    Profesor cadruDidactic;
public:
    Materie(std::string numeMaterie_ = "", int an_ = 0, int semestru_ = 0,  std::vector<Student> Studenti_ = {},
            Examen examen_ = Examen(), Profesor profesor = Profesor());

    friend std::ostream& operator<<(std::ostream& os, const Materie &m);
    friend std::istream& operator>>(std::istream& is,  Materie &m);
    Materie operator+=(const Student &s);

    int getNumarStudenti();
    std::string getEmailProfesor();
    int getNotaStudent(int n);
    void setNotaStudent(int n,int nota2);
    void schimbareProfesor(const Profesor &prof);
    void contestatie(int nrStud);


    ~Materie();

private:

};

#endif //PROIECT1_HEADER_H
