#include <iostream>
#include <queue>
#include <string>
using namespace std;


struct Estudiante {
    string cedula;
    string apellidos;
    string nombres;
    float notaFinal;
    string carrera;
    string nivel;
};


struct Nodo {
    Estudiante estudiante;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(Estudiante e) {
        estudiante = e;
        izquierda = nullptr;
        derecha = nullptr;
    }
};


void mostrarEstudiante(Estudiante e) {
    cout << "-------------------------" << endl;
    cout << "Cedula   : " << e.cedula << endl;
    cout << "Nombre   : " << e.nombres << " " << e.apellidos << endl;
    cout << "Nota     : " << e.notaFinal << endl;
    cout << "Carrera  : " << e.carrera << endl;
    cout << "Nivel    : " << e.nivel << endl;
    cout << "-------------------------" << endl;
}


Nodo* insertarEstudiante(Nodo* raiz, Estudiante e) {
    if (raiz == nullptr) {
        return new Nodo(e);
    }
    if (e.cedula < raiz->estudiante.cedula) {
        raiz->izquierda = insertarEstudiante(raiz->izquierda, e);
    } else if (e.cedula > raiz->estudiante.cedula) {
        raiz->derecha = insertarEstudiante(raiz->derecha, e);
    } else {
        cout << "Ya existe un estudiante con esa cedula." << endl;
    }
    return raiz;
}


Nodo* buscarEstudiante(Nodo* raiz, string cedula) {
    if (raiz == nullptr) return nullptr;
    if (cedula == raiz->estudiante.cedula) return raiz;
    if (cedula < raiz->estudiante.cedula)
        return buscarEstudiante(raiz->izquierda, cedula);
    else
        return buscarEstudiante(raiz->derecha, cedula);
}


Estudiante pedirDatos() {
    Estudiante e;
    cout << "Cedula    : "; cin >> e.cedula;
    cout << "Apellidos : "; cin >> e.apellidos;
    cout << "Nombres   : "; cin >> e.nombres;
    cout << "Nota Final: "; cin >> e.notaFinal;
    cout << "Carrera   : "; cin >> e.carrera;
    cout << "Nivel     : "; cin >> e.nivel;
    return e;
}


int main() {
    Nodo* raiz = nullptr;
    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Buscar estudiante por cedula" << endl;
        cout << "14. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        if (opcion == 1) {
            Estudiante e = pedirDatos();
            raiz = insertarEstudiante(raiz, e);
            cout << "Estudiante insertado correctamente." << endl;

        } else if (opcion == 2) {
            string cedula;
            cout << "Ingrese cedula a buscar: "; cin >> cedula;
            Nodo* resultado = buscarEstudiante(raiz, cedula);
            if (resultado != nullptr) {
                cout << "Estudiante encontrado:" << endl;
                mostrarEstudiante(resultado->estudiante);
            } else {
                cout << "Estudiante no encontrado." << endl;
            }
        }

    } while (opcion != 14);

    cout << "Saliendo..." << endl;
    return 0;
}