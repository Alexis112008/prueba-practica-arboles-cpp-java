#include "Nodo.h"

Nodo::Nodo(Estudiante e) {
    estudiante = e;
    izquierda = nullptr;
    derecha = nullptr;
}

Estudiante Nodo::getEstudiante() const { return estudiante; }
void Nodo::setEstudiante(Estudiante e) { estudiante = e; }
Nodo* Nodo::getIzquierda() const { return izquierda; }
void Nodo::setIzquierda(Nodo* izq) { izquierda = izq; }
Nodo* Nodo::getDerecha() const { return derecha; }
void Nodo::setDerecha(Nodo* der) { derecha = der; }