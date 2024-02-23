#include <iostream>
#include "Persona.h"
#include "Lista.h"
#include "Generador.h"
#include <chrono>

int main(){

    int n;

    std::cout << "Ingrese el número de personas que desea generar: ";
    std::cin >> n;

    // Crea un generador con archivos de nombres y apellidos
    Generador generadorNombres("nombres.txt", "apellidos.txt");

    // Crea una lista y agrega n elementos generados aleatoriamente
    Lista lista;

    for (int i = 0; i < n; ++i) {
        Persona persona = generadorNombres.generarPersona();
        lista.agregarElemento(persona);
    }

    // Presenta la lista en desorden
    std::cout << "Lista en desorden:" << std::endl;
    lista.listar();

    int respuesta;

    std::cout << "Elija el método de ordenamiento:\n1. Quick Sort\n2. Merge Sort\n3. Bubble Sort\nIngrese su respuesta: ";
    std::cin >> respuesta;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    switch (respuesta)
    {
    case 1:
        lista.ordenarQuickSort();
        break;
    case 2:
        lista.ordenarMergeSort();
        
        break;
    case 3:
        lista.ordenarBubbleSort();
        break;
    
    default:
        break;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    // Presenta la lista ordenada
    std::cout << "\nLista ordenada:" << std::endl;
    lista.listar();

    std::cout << "\nTiempo que tardó el algoritmo: " << elapsed_seconds.count() << " segundos." << std::endl;

    return 0;
}