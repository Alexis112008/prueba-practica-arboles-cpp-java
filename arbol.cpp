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

    // Constructor: inicializa los punteros en null
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

int main() {
    cout << "Estructura base lista." << endl;
    return 0;
}