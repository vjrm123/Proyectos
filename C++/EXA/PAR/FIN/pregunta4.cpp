/*Escriba el codigo de la funcion void Split(Node *&a, Node *&b, bool(*decide)(int)). El
puntero a, apunta al nodo inicial de una lista enlazada, se desconoce si los elementos estan ordenados o
no. El puntero b es un puntero a nodo que llega ala funcion en null. La funcion debe separar la lista en dos,
de acuerdo con lo indicado por la funcion apuntada por decide, ala cual se le enviara el valor del nodo (el 
valor esta en el atributo info). Si decide devuelve verdadero, el nodo permanecera en la lista apuntada
por el puntero a; y si devuelve falso, el nodo sera movido al final de la lista apuntada por el puntero b. Se 
desconoce el tamaño de la lista, sin embargo se sabe que el ultimo nodo apunta a null en su atributo next.
Culminada la ejecucion de la funcion, los punteros a y b apuntan al inicio de sus respectivas listas. La clase
nodo es la descrita a continuacion.*/

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

void Split(Nodo*& a, Nodo*& b, bool (*decide)(int)) {
    Nodo* actual = a;
    Nodo* ultimoA = nullptr;
    Nodo* ultimoB = nullptr;

    // Reinicializar a para empezar con una lista vacía
    a = nullptr;

    while (actual != nullptr) {
        Nodo* siguiente = actual->Next;

        if (decide(actual->info)) {
            // Mantener el nodo en la lista a
            if (ultimoA == nullptr) {
                a = actual;
                ultimoA = actual;
            }
            else {
                ultimoA->Next = actual;
                ultimoA = actual;
            }
        }
        else {
            // Mover el nodo a la lista b
            if (ultimoB == nullptr) {
                b = actual;
                ultimoB = actual;
            }
            else {
                ultimoB->Next = actual;
                ultimoB = actual;
            }
        }

        actual = siguiente;
    }

    // Asegurarse de que los últimos nodos de ambas listas no apunten a nada
    if (ultimoA != nullptr) ultimoA->Next = nullptr;
    if (ultimoB != nullptr) ultimoB->Next = nullptr;
}

// Función para imprimir una lista enlazada
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

    std::cout << "Lista original: ";
    imprimirLista(lista);

    // Inicializar las listas a y b como vacías
    Nodo* a = lista; // Inicializar a con la lista original
    Nodo* b = nullptr;

    // Llamar a la función Split
    Split(a, b, decide);

    std::cout << "Lista a (números pares): ";
    imprimirLista(a);

    std::cout << "Lista b (números impares): ";
    imprimirLista(b);

    return 0;
}