#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

class Estudiante {
private:
    string cedula;
    string apellidos;
    string nombres;
    float notaFinal;
    string carrera;
    string nivel;

public:
    Estudiante();
    Estudiante(string ced, string apell, string nom, float nota, string carr, string niv);
    
    // Getters
    string getCedula() const;
    string getApellidos() const;
    string getNombres() const;
    float getNotaFinal() const;
    string getCarrera() const;
    string getNivel() const;
    
    // Setters
    void setCedula(string ced);
    void setApellidos(string apell);
    void setNombres(string nom);
    void setNotaFinal(float nota);
    void setCarrera(string carr);
    void setNivel(string niv);
    
    // Métodos adicionales
    void mostrar() const;
    void pedirDatos();
    
    // Operadores para comparación
    bool operator<(const Estudiante& otro) const;
    bool operator>(const Estudiante& otro) const;
    bool operator==(const Estudiante& otro) const;
};

#endif