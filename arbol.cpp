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
    if (cedula < raiz->estudiante.cedula)
        raiz->izquierda = eliminarEstudiante(raiz->izquierda, cedula);
    else if (cedula > raiz->estudiante.cedula)
        raiz->derecha = eliminarEstudiante(raiz->derecha, cedula);
    else {
        if (raiz->izquierda == nullptr) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        if (raiz->derecha == nullptr) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        Nodo* sucesor = minimoNodo(raiz->derecha);
        raiz->estudiante = sucesor->estudiante;
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


void recorridoPorNiveles(Nodo* raiz) {
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
            mostrarEstudiante(actual->estudiante);

            if (actual->izquierda != nullptr) cola.push(actual->izquierda);
            if (actual->derecha  != nullptr) cola.push(actual->derecha);
        }
    }
}


int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}


int calcularAltura(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    int altIzq = calcularAltura(raiz->izquierda);
    int altDer = calcularAltura(raiz->derecha);
    return 1 + max(altIzq, altDer);
}


void buscarNotaMayor(Nodo* raiz, Nodo*& mejor) {
    if (raiz == nullptr) return;
    if (mejor == nullptr || raiz->estudiante.notaFinal > mejor->estudiante.notaFinal)
        mejor = raiz;
    buscarNotaMayor(raiz->izquierda, mejor);
    buscarNotaMayor(raiz->derecha, mejor);
}


void buscarNotaMenor(Nodo* raiz, Nodo*& mejor) {
    if (raiz == nullptr) return;
    if (mejor == nullptr || raiz->estudiante.notaFinal < mejor->estudiante.notaFinal)
        mejor = raiz;
    buscarNotaMenor(raiz->izquierda, mejor);
    buscarNotaMenor(raiz->derecha, mejor);
}


void mostrarAprobados(Nodo* raiz) {
    if (raiz == nullptr) return;
    mostrarAprobados(raiz->izquierda);
    if (raiz->estudiante.notaFinal >= 7.0)
        mostrarEstudiante(raiz->estudiante);
    mostrarAprobados(raiz->derecha);
}


void mostrarReprobados(Nodo* raiz) {
    if (raiz == nullptr) return;
    mostrarReprobados(raiz->izquierda);
    if (raiz->estudiante.notaFinal < 7.0)
        mostrarEstudiante(raiz->estudiante);
    mostrarReprobados(raiz->derecha);
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
        cout << "\n      SISTEMA DE ESTUDIANTES FISEI    " << endl;
        cout << " 1.  Insertar estudiante" << endl;
        cout << " 2.  Buscar estudiante por cedula" << endl;
        cout << " 3.  Eliminar estudiante" << endl;
        cout << " 4.  Recorrido Inorden" << endl;
        cout << " 5.  Recorrido Preorden" << endl;
        cout << " 6.  Recorrido Postorden" << endl;
        cout << " 7.  Recorrido por niveles (BFS)" << endl;
        cout << " 8.  Contar estudiantes" << endl;
        cout << " 9.  Calcular altura del arbol" << endl;
        cout << " 10. Estudiante con mayor nota" << endl;
        cout << " 11. Estudiante con menor nota" << endl;
        cout << " 12. Mostrar aprobados" << endl;
        cout << " 13. Mostrar reprobados" << endl;
        cout << " 14. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: {
                Estudiante e = pedirDatos();
                raiz = insertarEstudiante(raiz, e);
                cout << "Estudiante insertado correctamente." << endl;
                break;
            }
            case 2: {
                string cedula;
                cout << "Cedula a buscar: "; cin >> cedula;
                Nodo* res = buscarEstudiante(raiz, cedula);
                if (res) mostrarEstudiante(res->estudiante);
                else cout << "Estudiante no encontrado." << endl;
                break;
            }
            case 3: {
                string cedula;
                cout << "Cedula a eliminar: "; cin >> cedula;
                raiz = eliminarEstudiante(raiz, cedula);
                break;
            }
            case 4:
                cout << "\n--- Recorrido Inorden ---" << endl;
                recorridoInorden(raiz);
                break;
            case 5:
                cout << "\n--- Recorrido Preorden ---" << endl;
                recorridoPreorden(raiz);
                break;
            case 6:
                cout << "\n--- Recorrido Postorden ---" << endl;
                recorridoPostorden(raiz);
                break;
            case 7:
                cout << "\n--- Recorrido por Niveles (BFS) ---" << endl;
                recorridoPorNiveles(raiz);
                break;
            case 8:
                cout << "Total de estudiantes: " << contarNodos(raiz) << endl;
                break;
            case 9:
                cout << "Altura del arbol: " << calcularAltura(raiz) << endl;
                break;
            case 10: {
                Nodo* mejor = nullptr;
                buscarNotaMayor(raiz, mejor);
                if (mejor) { cout << "\nEstudiante con mayor nota:" << endl; mostrarEstudiante(mejor->estudiante); }
                else cout << "El arbol esta vacio." << endl;
                break;
            }
            case 11: {
                Nodo* menor = nullptr;
                buscarNotaMenor(raiz, menor);
                if (menor) { cout << "\nEstudiante con menor nota:" << endl; mostrarEstudiante(menor->estudiante); }
                else cout << "El arbol esta vacio." << endl;
                break;
            }
            case 12:
                cout << "\n--- Estudiantes Aprobados (nota >= 7) ---" << endl;
                mostrarAprobados(raiz);
                break;
            case 13:
                cout << "\n--- Estudiantes Reprobados (nota < 7) ---" << endl;
                mostrarReprobados(raiz);
                break;
            case 14:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 14);

    return 0;
}