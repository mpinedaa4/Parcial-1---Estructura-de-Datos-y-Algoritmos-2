// Lista.h
#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
private:
    Nodo* cabeza;

public:
    Lista();
    ~Lista();

    void agregarElemento(const Persona& persona);
    void listar() const;
    void borrar(const Persona& persona);
    int longitud() const;
    Nodo* getCabeza() const;
    void setCabeza(Nodo* cabeza);

    // Elimina el modificador const en la declaración de dividirLista
    void dividirLista(Nodo* cabeza, Nodo** lista1, Nodo** lista2);

    // Quick Sort
    void ordenarQuickSort();
    Nodo* quickSort(Nodo* cabeza);
    Nodo* unionListas(Nodo* cabezaMenor, Nodo* pivote, Nodo* cabezaMayor);

    // Merge Sort
    void ordenarMergeSort();
    Nodo* mergeSort(Nodo* cabeza);
    int calcularMitad(Nodo* cabeza);
    Nodo* combinar(Nodo* cabeza1, Nodo* cabeza2);

    // Bubble Sort
    void ordenarBubbleSort();
    Nodo* bubbleSort(Nodo* cabeza);
    Nodo* swap(Nodo* mayor, Nodo* menor);
};

#endif
