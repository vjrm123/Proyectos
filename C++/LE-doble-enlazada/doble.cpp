#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int value) : data(value), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
    node* head;
    node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // Añadir un nodo al final
    void add(int value) {
        node* newNode = new node(value);
        if (!head) {  // Si la lista está vacía
            head = tail = newNode;
        } else {
            tail->next = newNode;  // Conectar el último nodo con el nuevo nodo
            newNode->prev = tail;  // El nuevo nodo apunta al nodo anterior
            tail = newNode;        // Actualizar el puntero tail
        }
    }

    // Eliminar un nodo con un valor dado
    void del(int value) {
        if (!head) {
            cout << "Lista vacía, no se puede eliminar.\n";
            return;
        }

        node* current = head;
        // Buscar el nodo que contiene el valor
        while (current && current->data != value) {
            current = current->next;
        }

        if (!current) {
            cout << "Valor no encontrado en la lista.\n";
            return;
        }

        // Si el nodo a eliminar es la cabeza
        if (current == head) {
            head = head->next;  // La cabeza apunta al siguiente nodo
            if (head) head->prev = NULL;  // Si no está vacía, ajustar el puntero prev
            else tail = NULL;  // Si la lista queda vacía, tail también debe ser NULL
        }
        // Si el nodo a eliminar es la cola
        else if (current == tail) {
            tail = tail->prev;  // Mover la cola al nodo anterior
            if (tail) tail->next = NULL;  // Desconectar el último nodo
        }
        // Si el nodo está en el medio
        else {
            current->prev->next = current->next;  // Saltar el nodo en la cadena
            current->next->prev = current->prev;  // Ajustar el puntero prev del siguiente nodo
        }

        delete current;  // Liberar el nodo eliminado
    }

    // Imprimir la lista de izquierda a derecha (hacia adelante)
    void printForward() {
        node* temp = head;
        cout << "Lista hacia adelante: head -> ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Imprimir la lista de derecha a izquierda (hacia atrás)
    void printBackward() {
        node* temp = tail;
        cout << "Lista hacia atrás: tail -> ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    int ADD[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    int DEL[10] = { 9, 7, 5, 3, 1, 10, 8, 6, 4, 2 };
    
    DoublyLinkedList DLL;

    // Agregar elementos a la lista
    for (int i = 0; i < 10; i++) {
        cout << "ADD " << ADD[i] << endl;
        DLL.add(ADD[i]);
        DLL.printForward();  // Imprimir lista en dirección hacia adelante
    }

    // Eliminar elementos de la lista
    for (int i = 0; i < 10; i++) {
        cout << "DEL " << DEL[i] << endl;
        DLL.del(DEL[i]);
        DLL.printForward();  // Imprimir lista en dirección hacia adelante
    }

    return 0;
}
