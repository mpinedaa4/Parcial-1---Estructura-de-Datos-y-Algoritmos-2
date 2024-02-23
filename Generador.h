#ifndef GENERADOR_H
#define GENERADOR_H

#include "Persona.h"
#include <vector>

class Generador {
private:
    std::vector<std::string> nombres;
    std::vector<std::string> apellidos;

public:
    Generador(const std::string& archivoNombres, const std::string& archivoApellidos);
    Persona generarPersona();
};

#endif
