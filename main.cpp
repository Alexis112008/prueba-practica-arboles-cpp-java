#include "ArbolBinario.h"
#include <iostream>
using namespace std;

int main() {
    ArbolBinario arbol;
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
                Estudiante e;
                e.pedirDatos();
                arbol.insertar(e);
                break;
            }
            case 2: {
                string cedula;
                cout << "Cedula a buscar: "; cin >> cedula;
                arbol.buscar(cedula);
                break;
            }
            case 3: {
                string cedula;
                cout << "Cedula a eliminar: "; cin >> cedula;
                arbol.eliminar(cedula);
                break;
            }
            case 4:
                arbol.recorridoInorden();
                break;
            case 5:
                arbol.recorridoPreorden();
                break;
            case 6:
                arbol.recorridoPostorden();
                break;
            case 7:
                cout << "\n--- Recorrido por Niveles (BFS) ---" << endl;
                arbol.recorridoPorNiveles();
                break;
            case 8:
                cout << "Total de estudiantes: " << arbol.contarNodos() << endl;
                break;
            case 9:
                cout << "Altura del arbol: " << arbol.calcularAltura() << endl;
                break;
            case 10:
                arbol.estudianteMayorNota();
                break;
            case 11:
                arbol.estudianteMenorNota();
                break;
            case 12:
                arbol.mostrarAprobados();
                break;
            case 13:
                arbol.mostrarReprobados();
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