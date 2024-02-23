// Lista.cpp
#include "Lista.h"

void Lista::dividirLista(Nodo* cabeza, Nodo** lista1, Nodo** lista2) {
    Nodo* puntoA;
    Nodo* puntoB;

    int size= 0;
    for(Nodo* x = cabeza; x != nullptr; x=x->siguiente){
        ++size;
    }
    int mitad = size/2;

    std::cout << "en dividirLista.. (Tamaño: "<< std::to_string(size) <<") : (Mitad: "<< std::to_string(mitad) <<")" << std::endl;

    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        *lista1 = cabeza;
        *lista2 = nullptr;
    } else {
        puntoB = cabeza;
        puntoA = cabeza->siguiente;

        // Avanzar 'puntoA' dos nodos y 'puntoB' un nodo
        while (puntoA != nullptr) {
            puntoA = puntoA->siguiente;
            if (puntoA != nullptr) {
                puntoB = puntoB->siguiente;
                puntoA = puntoA->siguiente;
            }
        }
        // 'puntoB' ahora está en el nodo medio, dividir la lista en dos en este punto
        *lista1 = cabeza;
        *lista2 = puntoB->siguiente;
        puntoB->siguiente = nullptr;
    }
    std::cout << "Terminó DividirLista" << std::endl;
    //std::cout << "Lista 1" << std::endln;

}

Lista::Lista() : cabeza(nullptr) {}

Lista::~Lista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Lista::agregarElemento(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::listar() const {
    Nodo* actual = cabeza;
    int i=1;
    while (actual != nullptr) {
        std::cout << "["<< std::to_string(i) <<"]::"<< actual << " -> "<< actual->siguiente << " : "<< actual->Data << " " << std::endl;
        actual = actual->siguiente;
        ++i;
    }
    std::cout << std::endl;
}

void Lista::borrar(const Persona& persona) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && !(actual->Data == persona)) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        std::cout << "La persona no está en la lista." << std::endl;
        return;
    }

    if (anterior == nullptr) {
        // El nodo a borrar es el primero
        cabeza = actual->siguiente;
    } else {
        // El nodo a borrar no es el primero
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
}

int Lista::longitud() const {
    int count = 0;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        count++;
        actual = actual->siguiente;
    }

    return count;
}

Nodo* Lista::getCabeza() const {
    return cabeza;
}

void Lista::setCabeza(Nodo* cabeza){
    this->cabeza = cabeza;
}

void Lista::ordenarQuickSort(){
    this->setCabeza(quickSort(this->getCabeza()));
}

Nodo* Lista::quickSort(Nodo* cabeza){
    // Caso base
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return cabeza;
    }

    Nodo* cabezaMayor = nullptr; // Lista para los menores al pivote
    Nodo* cabezaMenor = nullptr; // Lista para los mayores al pivote
    Nodo* pivote = cabeza; // El pivote es el primer elemento de la lista original
    Nodo* actual = cabeza->siguiente; // Se empieza a comparar a partir del segundo elemento

    // Ciclo para recorrer toda la lista
    while (actual != nullptr){

        Nodo* siguiente = actual->siguiente;
        // Se guarda el proximo nodo porque el actual->siguiente hay que desligarlo de la lista principal

        // Verificar si actual es menor al pivote
        if (actual->Data < pivote->Data){
            actual->siguiente = cabezaMenor; // Se pone el actual de primero en la lista de menores, desligandolo a la vez de la lista ppal
            cabezaMenor = actual; // Se mueve el puntero de la cabeza de menores al nodo actual
        }
        // Lógica para los mayores
        else{
            actual->siguiente = cabezaMayor;
            cabezaMayor = actual;
        }
        // Se cambia el actual para seguir el ciclo while
        actual = siguiente;
    }

    // Se debe hacer recursión sobre la lista de menores y mayores
    cabezaMenor = quickSort(cabezaMenor);
    cabezaMayor = quickSort(cabezaMayor);

    // Se debe ligar el final de los menores con el pivote y este a su vez se debe ligar con la cabeza de mayores
    return unionListas(cabezaMenor, pivote, cabezaMayor);
}

Nodo* Lista::unionListas(Nodo* cabezaMenor, Nodo* pivote, Nodo* cabezaMayor){

    pivote->siguiente = cabezaMayor; // Se le pega al final de pivote los mayores

    Nodo* actualMenor = cabezaMenor; // Se debe recorrer los menores para unir el final con el pivote

    if (actualMenor == nullptr){
        return pivote; // En caso de que no haya elementos menores, la lista empieza en la cabeza de pivote
    }

    while (actualMenor->siguiente != nullptr){
        actualMenor = actualMenor->siguiente;
    }
    actualMenor->siguiente = pivote; // Al final de los menores se pega el pivote
    return cabezaMenor; // Se retorna la cabeza menor porque es el inicio de la lista
}

void Lista::ordenarMergeSort(){
    this->setCabeza(mergeSort(this->getCabeza()));
}

Nodo* Lista::mergeSort(Nodo* cabeza){
    if (cabeza == nullptr || cabeza->siguiente == nullptr){
        return cabeza; // Caso base
    }

    Nodo* actual = cabeza;
    Nodo* lista1 = cabeza; // Primera mitad
    Nodo* lista2; // Segunda mitad

    int mitad = calcularMitad(cabeza);

    for (int i = 0; i < (mitad-1); i++){
        actual = actual->siguiente; // Se busca llegar al nodo de la mitad
    }

    lista2 = actual->siguiente; // lista2 apunta al nodo de la mitad
    actual->siguiente = nullptr; // se corta la lista, para que lista1 no quede completa sino solo hasta la mitad


    lista1 = mergeSort(lista1); // Recursión
    lista2 = mergeSort(lista2);

    Nodo* final = nullptr; // Se crea nodo donde se va a guardar la cabeza de la lista completamente organizada

    final = combinar(lista1, lista2); // Se combinan las listas

    return final;
}

int Lista::calcularMitad(Nodo* cabeza){
    Nodo* actual = cabeza;
    int count = 0;
    while(actual != nullptr){
        count ++;
        actual = actual->siguiente;
    }
    int mitad = count/2;
    return mitad;
}

Nodo* Lista::combinar(Nodo* cabeza1, Nodo* cabeza2){
    if(cabeza1 == nullptr){
        return cabeza2; // En caso de que una lista este vacía
    }
    else if(cabeza2 == nullptr){
        return cabeza1; // En caso de que una lista este vacía
    }
    else{
        if(cabeza1->Data < cabeza2->Data){
            Nodo* resultado = nullptr;
            resultado = cabeza1; // Cabeza1 tiene que ser el primero por ser menor
            resultado->siguiente = combinar(cabeza1->siguiente, cabeza2); // Se hace recursión para agregar el elemento que sigue
            return resultado;
        }
        else{
            Nodo* resultado = nullptr;
            resultado = cabeza2;
            resultado->siguiente = combinar(cabeza1, cabeza2->siguiente);
            return resultado;
        }
    }
}


Nodo* Lista::bubbleSort(Nodo* cabeza){
    int len = longitud();
    Nodo* head = nullptr;

    for (int i = 0; i < len - 1; i++){
        head = cabeza;
        Nodo* previo = nullptr;
        bool cambiado = false;

        for(int j = 0; j < (len - i - 1); j++){
            if (head->Data > head->siguiente->Data){
                if (head == cabeza){
                    head = swap(head, head->siguiente);
                    cabeza = head;
                }
                else{
                    head = swap(head, head->siguiente);
                    previo->siguiente = head;
                }
                cambiado = true;
            }
            previo = head;
            head = head->siguiente;
        }
        if(!cambiado){
            break;
        }
    }
    return cabeza;
}

Nodo* Lista::swap(Nodo* mayor, Nodo* menor){
    Nodo* temp = nullptr;
    temp = menor->siguiente;
    menor->siguiente = mayor;
    mayor->siguiente = temp;
    return menor;
}

void Lista::ordenarBubbleSort(){
    this->setCabeza(bubbleSort(this->getCabeza()));
}