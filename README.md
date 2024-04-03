# Proiect 1 - POO - Subiect: Materie

## Clasa Student:

1.  Membri:
* Nume: Numele studentului.
* Prenume: Prenumele studentului.
* Nota: Nota studentului.
2. Metode publice:
* getNota(): Returnează nota studentului.
* setNota(float n): Setează nota studentului.
* operator+(float n): Creste/Scade nota studentului

## Clasa Profesor:

1. Membri:
* Nume: Numele profesorului.
* Prenume: Prenumele profesorului.
* Email: Adresa de email a profesorului.
2. Metode publice:
* getEmail(): Returnează adresa de email a profesorului.

## Clasa Examen:

1. Membri:
* Zi, Luna, An: Data examenului.
* Ora: Ora examenului (in format militar).
* TimpDeLucruInMinute: Durata examenului în minute.
* NrSubiecte: Numărul de subiecte ale examenului.
2. Metode publice:
* getAn(): Returnează anul examenului.

## Clasa Materie:

1. Membri:
* NumeMaterie: Numele materiei.
* An, Semestru: Anul și semestrul în care se desfășoară materia.
* Studenti: Vector de obiecte de tip Student care reprezintă studenții din materie.
* Examen, Restanta: Obiecte de tip Examen care reprezintă examenul și restanța materiei.
* CadruDidactic: Obiect de tip Profesor care reprezintă profesorul care preda materia.
2. Metode publice:
* getNumarStudenti(): Returnează numărul de studenți din materie.
* getEmailProfesor(): Returnează adresa de email a profesorului materiei.
* getNotaStudent(int n): Returnează nota studentului identificat de indexul n.
* getAnRestanta(): Returnează anul examenului de restanță pentru materie.
* schimbareProfesor(const Profesor &prof): Schimbă profesorul care predă materia cu un alt profesor dat.
* operator+=(const Student &s): Adaugă un nou student la lista de studenți ai materiei.
