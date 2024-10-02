#include <iostream>

using namespace std;

class nodo {
public:
    int data;
    nodo* next;
    nodo* prev;

    nodo(int value) : data(value), next(NULL), prev(NULL) {}
};

class ListaDobleCircular {
    nodo* cabeza;
    nodo* cola;

public:
    ListaDobleCircular() : cabeza(NULL), cola(NULL) {}

    // Añadir un nodo al final
    void add(int value) {
        nodo* nuevoNodo = new nodo(value);
        if (!cabeza) {  // Si la lista está vacía
            cabeza = cola = nuevoNodo;
            cabeza->next = cabeza;  // Conectar el primer nodo consigo mismo
            cabeza->prev = cabeza;  // Conectar el primer nodo consigo mismo
        } else {
            cola->next = nuevoNodo;  // Conectar el último nodo con el nuevo nodo
            nuevoNodo->prev = cola;  // El nuevo nodo apunta al nodo anterior
            nuevoNodo->next = cabeza;  // El nuevo nodo apunta al primero (circularidad)
            cabeza->prev = nuevoNodo;  // El primer nodo apunta al nuevo nodo
            cola = nuevoNodo;  // Actualizar la cola
        }
    }

    // Eliminar un nodo con un valor dado
    void del(int value) {
        if (!cabeza) {
            cout << "Lista vacía, no se puede eliminar.\n";
            return;
        }

        nodo* actual = cabeza;

        // Buscar el nodo que contiene el valor
        do {
            if (actual->data == value) break;
            actual = actual->next;
        } while (actual != cabeza);

        if (actual->data != value) {
            cout << "Valor no encontrado en la lista.\n";
            return;
        }

        // Si la lista tiene un solo nodo
        if (actual == cabeza && actual == cola) {
            delete actual;
            cabeza = cola = NULL;
            return;
        }

        // Si el nodo a eliminar es la cabeza
        if (actual == cabeza) {
            cabeza = cabeza->next;  // La cabeza apunta al siguiente nodo
            cabeza->prev = cola;  // La nueva cabeza apunta a la cola
            cola->next = cabeza;  // La cola apunta a la nueva cabeza
        }
        // Si el nodo a eliminar es la cola
        else if (actual == cola) {
            cola = cola->prev;  // Mover la cola al nodo anterior
            cola->next = cabeza;  // La nueva cola apunta a la cabeza
            cabeza->prev = cola;  // La cabeza apunta a la nueva cola
        }
        // Si el nodo está en el medio
        else {
            actual->prev->next = actual->next;  // Saltar el nodo en la cadena
            actual->next->prev = actual->prev;  // Ajustar el puntero prev del siguiente nodo
        }

        delete actual;  // Liberar el nodo eliminado
    }

    // Imprimir la lista de izquierda a derecha (hacia adelante)
    void printForward() {
        if (!cabeza) {
            cout << "Lista vacía.\n";
            return;
        }
        nodo* temp = cabeza;
        cout << "Lista hacia adelante: cabeza -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != cabeza);
        cout << "cabeza\n";  // Para indicar que la lista es circular
    }

    // Imprimir la lista de derecha a izquierda (hacia atrás)
    void printBackward() {
        if (!cola) {
            cout << "Lista vacía.\n";
            return;
        }
        nodo* temp = cola;
        cout << "Lista hacia atrás: cola -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != cola);
        cout << "cola\n";  // Para indicar que la lista es circular
    }
};

int main() {
    int ADD[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    int DEL[10] = { 9, 7, 5, 3, 1, 10, 8, 6, 4, 2 };
    
    ListaDobleCircular LDC;

    // Agregar elementos a la lista
    for (int i = 0; i < 10; i++) {
        cout << "ADD " << ADD[i] << endl;
        LDC.add(ADD[i]);
        LDC.printForward();  // Imprimir lista en dirección hacia adelante
    }

    // Eliminar elementos de la lista
    for (int i = 0; i < 10; i++) {
        cout << "DEL " << DEL[i] << endl;
        LDC.del(DEL[i]);
        LDC.printForward();  // Imprimir lista en dirección hacia adelante
    }

    return 0;
}
