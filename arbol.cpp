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
    if (raiz == nullptr) return new Nodo(e);
    if (e.cedula < raiz->estudiante.cedula)
        raiz->izquierda = insertarEstudiante(raiz->izquierda, e);
    else if (e.cedula > raiz->estudiante.cedula)
        raiz->derecha = insertarEstudiante(raiz->derecha, e);
    else
        cout << "Ya existe un estudiante con esa cedula." << endl;
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


Nodo* minimoNodo(Nodo* nodo) {
    while (nodo->izquierda != nullptr)
        nodo = nodo->izquierda;
    return nodo;
}



Nodo* eliminarEstudiante(Nodo* raiz, string cedula) {
    if (raiz == nullptr) {
        cout << "Estudiante no encontrado." << endl;
        return nullptr;
    }

    if (cedula < raiz->estudiante.cedula) {
        raiz->izquierda = eliminarEstudiante(raiz->izquierda, cedula);

    } else if (cedula > raiz->estudiante.cedula) {
        raiz->derecha = eliminarEstudiante(raiz->derecha, cedula);

    } else {
        // Encontramos el nodo a eliminar

        // Caso 1 y 2: sin hijo izquierdo
        if (raiz->izquierda == nullptr) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        // Caso 2: sin hijo derecho
        if (raiz->derecha == nullptr) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }

        // Caso 3: tiene dos hijos
        // Buscar el sucesor (mínimo de la derecha)
        Nodo* sucesor = minimoNodo(raiz->derecha);
        // Reemplazar datos con el sucesor
        raiz->estudiante = sucesor->estudiante;
        // Eliminar el sucesor de la rama derecha
        raiz->derecha = eliminarEstudiante(raiz->derecha, sucesor->estudiante.cedula);
    }

    return raiz;
}


void recorridoInorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    recorridoInorden(raiz->izquierda);
    mostrarEstudiante(raiz->estudiante);
    recorridoInorden(raiz->derecha);
}


void recorridoPreorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    mostrarEstudiante(raiz->estudiante);
    recorridoPreorden(raiz->izquierda);
    recorridoPreorden(raiz->derecha);
}

void recorridoPostorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    recorridoPostorden(raiz->izquierda);
    recorridoPostorden(raiz->derecha);
    mostrarEstudiante(raiz->estudiante);
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
        cout << "\n      MENU     " << endl;
        cout << "1.  Insertar estudiante" << endl;
        cout << "2.  Buscar estudiante por cedula" << endl;
        cout << "3.  Eliminar estudiante" << endl;
        cout << "4.  Recorrido Inorden" << endl;
        cout << "5.  Recorrido Preorden" << endl;
        cout << "6.  Recorrido Postorden" << endl;
        cout << "14. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        if (opcion == 1) {
            Estudiante e = pedirDatos();
            raiz = insertarEstudiante(raiz, e);
            cout << "Estudiante insertado correctamente." << endl;

        } else if (opcion == 2) {
            string cedula;
            cout << "Cedula a buscar: "; cin >> cedula;
            Nodo* resultado = buscarEstudiante(raiz, cedula);
            if (resultado != nullptr)
                mostrarEstudiante(resultado->estudiante);
            else
                cout << "Estudiante no encontrado." << endl;

        } else if (opcion == 3) {
            string cedula;
            cout << "Cedula a eliminar: "; cin >> cedula;
            raiz = eliminarEstudiante(raiz, cedula);

        } else if (opcion == 4) {
            cout << "\n--- Recorrido Inorden ---" << endl;
            recorridoInorden(raiz);

        } else if (opcion == 5) {
            cout << "\n--- Recorrido Preorden ---" << endl;
            recorridoPreorden(raiz);

        } else if (opcion == 6) {
            cout << "\n--- Recorrido Postorden ---" << endl;
            recorridoPostorden(raiz);
        }

    } while (opcion != 14);

    cout << "Saliendo..." << endl;
    return 0;
}