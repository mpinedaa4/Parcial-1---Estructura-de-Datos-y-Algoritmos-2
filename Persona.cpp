#include "Persona.h"

Persona::Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

std::string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

// Sobrecarga de operadores de comparación
bool Persona::operator==(const Persona& otra) const {
    //return (nombre == otra.nombre) && (edad == otra.edad);
    return (edad == otra.edad);
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}

bool Persona::operator<(const Persona& otra) const {
    /*if (nombre == otra.nombre) {
        return edad < otra.edad;
    }
    return nombre < otra.nombre;*/
    return (edad < otra.edad);
}

bool Persona::operator<=(const Persona& otra) const {
    //return (*this < otra) || (*this == otra);
    return (edad <= otra.edad);
}

bool Persona::operator>(const Persona& otra) const {
    //return !(*this <= otra);
    return (edad > otra.edad);
}

bool Persona::operator>=(const Persona& otra) const {
    //return !(*this < otra);
    return (edad >= otra.edad);
}

// Sobrecarga del operador de inserción para ostream
std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
    return os;
}

// Método to_string
std::string Persona::to_string() const {
    return "ObjPersona [Nombre: " + nombre + ", Edad: " + std::to_string(edad) + " años ]";
}
