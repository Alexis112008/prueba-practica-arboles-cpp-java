#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

class Nodo {
private:
    Estudiante estudiante;
    Nodo* izquierda;
    Nodo* derecha;

public:
    Nodo(Estudiante e);
    
    // Getters y Setters
    Estudiante getEstudiante() const;
    void setEstudiante(Estudiante e);
    Nodo* getIzquierda() const;
    void setIzquierda(Nodo* izq);
    Nodo* getDerecha() const;
    void setDerecha(Nodo* der);
};

#endif