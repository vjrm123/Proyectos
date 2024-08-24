#include <iostream>

class Nodo {
public:
    Nodo() {
        Next = nullptr;
    }

    Nodo(int i, Nodo* in = nullptr) {
        info = i;
        Next = in;
    }

    int info;
    Nodo* Next;
};

void insertarOrdenado(Nodo*& cabeza, Nodo* nuevoNodo) {
    if (cabeza == nullptr || cabeza->info > nuevoNodo->info) {
        nuevoNodo->Next = cabeza;
        cabeza = nuevoNodo;
    }
    else {
        Nodo* actual = cabeza;
        while (actual->Next != nullptr && actual->Next->info <= nuevoNodo->info) {
            actual = actual->Next;
        }
        nuevoNodo->Next = actual->Next;
        actual->Next = nuevoNodo;
    }
}

void Split(Nodo*& a, Nodo*& b, bool (*decide)(int)) {
    Nodo* actual = a;
    a = nullptr;
    b = nullptr;

    while (actual != nullptr) {
        Nodo* siguiente = actual->Next;
        actual->Next = nullptr; 

        if (decide(actual->info)) {
            insertarOrdenado(a, actual);
        }
        else {
            insertarOrdenado(b, actual);
        }

        actual = siguiente; 
    }
}

void imprimirLista(Nodo* nodo) {
    while (nodo != nullptr) {
        std::cout << nodo->info << " ";
        nodo = nodo->Next;
    }
    std::cout << std::endl;
}

// Función decide para la función Split (ejemplo: mantener los números pares en la lista a)
bool decide(int valor) {
    return valor % 2 == 0;
}

// Función principal
int main() {
    // Crear la lista enlazada de prueba
    Nodo* lista = new Nodo(1);
    lista->Next = new Nodo(2);
    lista->Next->Next = new Nodo(11);
    lista->Next->Next->Next = new Nodo(12);
    lista->Next->Next->Next->Next = new Nodo(3);
    lista->Next->Next->Next->Next->Next = new Nodo(4);
    lista->Next->Next->Next->Next->Next->Next = new Nodo(5);
    lista->Next->Next->Next->Next->Next->Next->Next = new Nodo(6);
    lista->Next->Next->Next->Next->Next->Next->Next->Next = new Nodo(7);
    lista->Next->Next->Next->Next->Next->Next->Next->Next->Next = new Nodo(8);
    lista->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next = new Nodo(9);
    lista->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next = new Nodo(10);

    std::cout << "Lista original: ";
    imprimirLista(lista);

    Nodo* a = lista;
    Nodo* b = nullptr;

    Split(a, b, decide);

    std::cout << "Lista a (números pares): ";
    imprimirLista(a);

    std::cout << "Lista b (números impares): ";
    imprimirLista(b);

    return 0;
}
