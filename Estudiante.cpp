#include "Estudiante.h"
#include <iostream>
using namespace std;

Estudiante::Estudiante() : notaFinal(0.0) {}

Estudiante::Estudiante(string ced, string apell, string nom, float nota, string carr, string niv) {
    cedula = ced;
    apellidos = apell;
    nombres = nom;
    notaFinal = nota;
    carrera = carr;
    nivel = niv;
}

string Estudiante::getCedula() const { return cedula; }
string Estudiante::getApellidos() const { return apellidos; }
string Estudiante::getNombres() const { return nombres; }
float Estudiante::getNotaFinal() const { return notaFinal; }
string Estudiante::getCarrera() const { return carrera; }
string Estudiante::getNivel() const { return nivel; }

void Estudiante::setCedula(string ced) { cedula = ced; }
void Estudiante::setApellidos(string apell) { apellidos = apell; }
void Estudiante::setNombres(string nom) { nombres = nom; }
void Estudiante::setNotaFinal(float nota) { notaFinal = nota; }
void Estudiante::setCarrera(string carr) { carrera = carr; }
void Estudiante::setNivel(string niv) { nivel = niv; }

void Estudiante::mostrar() const {
    cout << "-------------------------" << endl;
    cout << "Cedula   : " << cedula << endl;
    cout << "Nombre   : " << nombres << " " << apellidos << endl;
    cout << "Nota     : " << notaFinal << endl;
    cout << "Carrera  : " << carrera << endl;
    cout << "Nivel    : " << nivel << endl;
    cout << "-------------------------" << endl;
}

void Estudiante::pedirDatos() {
    cout << "Cedula    : "; cin >> cedula;
    cout << "Apellidos : "; cin >> apellidos;
    cout << "Nombres   : "; cin >> nombres;
    cout << "Nota Final: "; cin >> notaFinal;
    cout << "Carrera   : "; cin >> carrera;
    cout << "Nivel     : "; cin >> nivel;
}

bool Estudiante::operator<(const Estudiante& otro) const {
    return cedula < otro.cedula;
}

bool Estudiante::operator>(const Estudiante& otro) const {
    return cedula > otro.cedula;
}

bool Estudiante::operator==(const Estudiante& otro) const {
    return cedula == otro.cedula;
}