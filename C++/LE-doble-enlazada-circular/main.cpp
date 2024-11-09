
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
    nodo* head;
    nodo* tail;

public:
    ListaDobleCircular() : head(NULL), tail(NULL) {}

    // Añadir un nodo al final
    void add(int value) {
        nodo* nuevo = new nodo(value);
        if (!head) {
            head = tail = nuevo;
            head->next = head;
            head->prev = head;
        }
        else {
            tail->next = nuevo;
            nuevo->prev = tail;
            nuevo->next = head;
            head->prev = nuevo;
            tail = nuevo;
        }
    }

    // Eliminar un nodo con un valor dado
    void del(int value) {
        if (!head) return;
        nodo* temp = head;

        // Buscar el nodo a eliminar
        do {
            if (temp->data == value) break;
            temp = temp->next;
        } while (temp != head);

        // Si no se encontró el valor, salir
        if (temp->data != value) return;

        // Si es el único nodo en la lista
        if (temp == head && temp == tail) {
            delete temp;
            head = tail = nullptr;
            return;
        }

        // Ajustar los punteros
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        // Actualizar head o tail si es necesario
        if (temp == head) head = head->next;
        if (temp == tail) tail = tail->prev;

        delete temp;
    }


    // Imprimir la lista de izquierda a derecha (hacia adelante)
    void printForward() {
        if (!head) {
            cout << "Lista vacía.\n";
            return;
        }
        nodo* temp = head;
        cout << "Lista hacia adelante: cabeza -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "cabeza\n";  // Para indicar que la lista es circular
    }

    // Imprimir la lista de derecha a izquierda (hacia atrás)
    void printBackward() {
        if (!tail) {
            cout << "Lista vacía.\n";
            return;
        }
        nodo* temp = tail;
        cout << "Lista hacia atrás: cola -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != tail);
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
