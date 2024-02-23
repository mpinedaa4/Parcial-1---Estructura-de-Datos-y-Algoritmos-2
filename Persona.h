#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);

    std::string getNombre() const;
    int getEdad() const;

    // Sobrecarga de operadores de comparación
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
    bool operator<(const Persona& otra) const;
    bool operator<=(const Persona& otra) const;
    bool operator>(const Persona& otra) const;
    bool operator>=(const Persona& otra) const;

    // Sobrecarga del operador de inserción para ostream
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);

    // Método to_string
    std::string to_string() const;
};

#endif
#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);

    std::string getNombre() const;
    int getEdad() const;

    // Otros métodos de la clase Persona, si es necesario...
};

#endif
