#include "ArbolBinario.h"
#include <iostream>
using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

void ArbolBinario::destruirArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->getIzquierda());
        destruirArbol(nodo->getDerecha());
        delete nodo;
    }
}

Nodo* ArbolBinario::insertarRecursivo(Nodo* nodo, Estudiante e) {
    if (nodo == nullptr) {
        return new Nodo(e);
    }
    
    if (e < nodo->getEstudiante()) {
        nodo->setIzquierda(insertarRecursivo(nodo->getIzquierda(), e));
    } else if (e > nodo->getEstudiante()) {
        nodo->setDerecha(insertarRecursivo(nodo->getDerecha(), e));
    } else {
        cout << "Ya existe un estudiante con esa cedula." << endl;
    }
    
    return nodo;
}

void ArbolBinario::insertar(Estudiante e) {
    raiz = insertarRecursivo(raiz, e);
    cout << "Estudiante insertado correctamente." << endl;
}

Nodo* ArbolBinario::buscarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) return nullptr;
    
    if (cedula == nodo->getEstudiante().getCedula()) {
        return nodo;
    } else if (cedula < nodo->getEstudiante().getCedula()) {
        return buscarRecursivo(nodo->getIzquierda(), cedula);
    } else {
        return buscarRecursivo(nodo->getDerecha(), cedula);
    }
}

void ArbolBinario::buscar(string cedula) {
    Nodo* resultado = buscarRecursivo(raiz, cedula);
    if (resultado) {
        resultado->getEstudiante().mostrar();
    } else {
        cout << "Estudiante no encontrado." << endl;
    }
}

Nodo* ArbolBinario::minimoNodo(Nodo* nodo) {
    while (nodo->getIzquierda() != nullptr) {
        nodo = nodo->getIzquierda();
    }
    return nodo;
}

Nodo* ArbolBinario::eliminarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) {
        cout << "Estudiante no encontrado." << endl;
        return nullptr;
    }
    
    if (cedula < nodo->getEstudiante().getCedula()) {
        nodo->setIzquierda(eliminarRecursivo(nodo->getIzquierda(), cedula));
    } else if (cedula > nodo->getEstudiante().getCedula()) {
        nodo->setDerecha(eliminarRecursivo(nodo->getDerecha(), cedula));
    } else {
        // Caso 1: sin hijos o con un solo hijo
        if (nodo->getIzquierda() == nullptr) {
            Nodo* temp = nodo->getDerecha();
            delete nodo;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        if (nodo->getDerecha() == nullptr) {
            Nodo* temp = nodo->getIzquierda();
            delete nodo;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        
        // Caso 2: con dos hijos
        Nodo* sucesor = minimoNodo(nodo->getDerecha());
        nodo->setEstudiante(sucesor->getEstudiante());
        nodo->setDerecha(eliminarRecursivo(nodo->getDerecha(), sucesor->getEstudiante().getCedula()));
    }
    
    return nodo;
}

void ArbolBinario::eliminar(string cedula) {
    raiz = eliminarRecursivo(raiz, cedula);
}

void ArbolBinario::inordenRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    inordenRecursivo(nodo->getIzquierda());
    nodo->getEstudiante().mostrar();
    inordenRecursivo(nodo->getDerecha());
}

void ArbolBinario::recorridoInorden() {
    cout << "\n--- Recorrido Inorden ---" << endl;
    inordenRecursivo(raiz);
}

void ArbolBinario::preordenRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    nodo->getEstudiante().mostrar();
    preordenRecursivo(nodo->getIzquierda());
    preordenRecursivo(nodo->getDerecha());
}

void ArbolBinario::recorridoPreorden() {
    cout << "\n--- Recorrido Preorden ---" << endl;
    preordenRecursivo(raiz);
}

void ArbolBinario::postordenRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    postordenRecursivo(nodo->getIzquierda());
    postordenRecursivo(nodo->getDerecha());
    nodo->getEstudiante().mostrar();
}

void ArbolBinario::recorridoPostorden() {
    cout << "\n--- Recorrido Postorden ---" << endl;
    postordenRecursivo(raiz);
}

void ArbolBinario::recorridoPorNiveles() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    queue<Nodo*> cola;
    cola.push(raiz);
    int nivel = 1;
    
    while (!cola.empty()) {
        int nodosPorNivel = cola.size();
        cout << "\n--- Nivel " << nivel++ << " ---" << endl;
        
        for (int i = 0; i < nodosPorNivel; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            actual->getEstudiante().mostrar();
            
            if (actual->getIzquierda() != nullptr) cola.push(actual->getIzquierda());
            if (actual->getDerecha() != nullptr) cola.push(actual->getDerecha());
        }
    }
}

int ArbolBinario::contarRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarRecursivo(nodo->getIzquierda()) + contarRecursivo(nodo->getDerecha());
}

int ArbolBinario::contarNodos() {
    return contarRecursivo(raiz);
}

int ArbolBinario::alturaRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    int altIzq = alturaRecursivo(nodo->getIzquierda());
    int altDer = alturaRecursivo(nodo->getDerecha());
    return 1 + max(altIzq, altDer);
}

int ArbolBinario::calcularAltura() {
    return alturaRecursivo(raiz);
}

void ArbolBinario::buscarMayorNotaRecursivo(Nodo* nodo, Nodo*& mejor) {
    if (nodo == nullptr) return;
    
    if (mejor == nullptr || nodo->getEstudiante().getNotaFinal() > mejor->getEstudiante().getNotaFinal()) {
        mejor = nodo;
    }
    
    buscarMayorNotaRecursivo(nodo->getIzquierda(), mejor);
    buscarMayorNotaRecursivo(nodo->getDerecha(), mejor);
}

void ArbolBinario::estudianteMayorNota() {
    Nodo* mejor = nullptr;
    buscarMayorNotaRecursivo(raiz, mejor);
    
    if (mejor) {
        cout << "\nEstudiante con mayor nota:" << endl;
        mejor->getEstudiante().mostrar();
    } else {
        cout << "El arbol esta vacio." << endl;
    }
}

void ArbolBinario::buscarMenorNotaRecursivo(Nodo* nodo, Nodo*& menor) {
    if (nodo == nullptr) return;
    
    if (menor == nullptr || nodo->getEstudiante().getNotaFinal() < menor->getEstudiante().getNotaFinal()) {
        menor = nodo;
    }
    
    buscarMenorNotaRecursivo(nodo->getIzquierda(), menor);
    buscarMenorNotaRecursivo(nodo->getDerecha(), menor);
}

void ArbolBinario::estudianteMenorNota() {
    Nodo* menor = nullptr;
    buscarMenorNotaRecursivo(raiz, menor);
    
    if (menor) {
        cout << "\nEstudiante con menor nota:" << endl;
        menor->getEstudiante().mostrar();
    } else {
        cout << "El arbol esta vacio." << endl;
    }
}

void ArbolBinario::aprobadosRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    aprobadosRecursivo(nodo->getIzquierda());
    if (nodo->getEstudiante().getNotaFinal() >= 7.0) {
        nodo->getEstudiante().mostrar();
    }
    aprobadosRecursivo(nodo->getDerecha());
}

void ArbolBinario::mostrarAprobados() {
    cout << "\n--- Estudiantes Aprobados (nota >= 7) ---" << endl;
    aprobadosRecursivo(raiz);
}

void ArbolBinario::reprobadosRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    reprobadosRecursivo(nodo->getIzquierda());
    if (nodo->getEstudiante().getNotaFinal() < 7.0) {
        nodo->getEstudiante().mostrar();
    }
    reprobadosRecursivo(nodo->getDerecha());
}

void ArbolBinario::mostrarReprobados() {
    cout << "\n--- Estudiantes Reprobados (nota < 7) ---" << endl;
    reprobadosRecursivo(raiz);
}

bool ArbolBinario::estaVacio() {
    return raiz == nullptr;
}