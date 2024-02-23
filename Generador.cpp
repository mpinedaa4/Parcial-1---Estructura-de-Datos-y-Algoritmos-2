#include "Generador.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

Generador::Generador(const std::string& archivoNombres, const std::string& archivoApellidos) {
    // Cargar nombres desde el archivo
    std::ifstream archivoN(archivoNombres);
    std::string nombre;
    while (std::getline(archivoN, nombre)) {
        nombres.push_back(nombre);
    }
    archivoN.close();

    // Cargar apellidos desde el archivo
    std::ifstream archivoA(archivoApellidos);
    std::string apellido;
    while (std::getline(archivoA, apellido)) {
        apellidos.push_back(apellido);
    }
    archivoA.close();

    // Inicializar la semilla para generar números aleatorios
    std::srand(std::time(0));
}

Persona Generador::generarPersona() {
    // Seleccionar un nombre y dos apellidos aleatorios
    std::string nombre = nombres[rand() % nombres.size()];
    std::string apellido1 = apellidos[rand() % apellidos.size()];
    std::string apellido2 = apellidos[rand() % apellidos.size()];

    // Formar el nombre completo
    std::string nombreCompleto = nombre + " " + apellido1 + " " + apellido2;

    // Generar una edad aleatoria
    int edad = 18 + rand() % 82;

    // Crear una persona
    return Persona(nombreCompleto, edad);
}
