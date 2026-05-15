#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"
#include <queue>
using namespace std;

class ArbolBinario {
private:
    Nodo* raiz;
    
    // Métodos privados para recursión
    Nodo* insertarRecursivo(Nodo* nodo, Estudiante e);
    Nodo* buscarRecursivo(Nodo* nodo, string cedula);
    Nodo* eliminarRecursivo(Nodo* nodo, string cedula);
    Nodo* minimoNodo(Nodo* nodo);
    void inordenRecursivo(Nodo* nodo);
    void preordenRecursivo(Nodo* nodo);
    void postordenRecursivo(Nodo* nodo);
    int contarRecursivo(Nodo* nodo);
    int alturaRecursivo(Nodo* nodo);
    void buscarMayorNotaRecursivo(Nodo* nodo, Nodo*& mejor);
    void buscarMenorNotaRecursivo(Nodo* nodo, Nodo*& menor);
    void aprobadosRecursivo(Nodo* nodo);
    void reprobadosRecursivo(Nodo* nodo);
    void destruirArbol(Nodo* nodo);

public:
    ArbolBinario();
    ~ArbolBinario();
    
    // Métodos públicos
    void insertar(Estudiante e);
    void buscar(string cedula);
    void eliminar(string cedula);
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void recorridoPorNiveles();
    int contarNodos();
    int calcularAltura();
    void estudianteMayorNota();
    void estudianteMenorNota();
    void mostrarAprobados();
    void mostrarReprobados();
    bool estaVacio();
};

#endif