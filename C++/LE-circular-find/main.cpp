#include <iostream>
using namespace std;


class node {
public:
    int data;
    node* next;
};

class CircularLinkedList {
    node* head = NULL;
public:
    void add(int value) {
        node* nuevo = new node();
        nuevo->data = value;
        node* temp = head;
        if (!head) {
            head = nuevo;
            nuevo->next = head;
        }
        else {
            while (temp->next != head) temp = temp->next;
            temp->next = nuevo;
            nuevo->next = head;
        }
    }

    void del(int value) {
        if (!head) return;
        node* temp = head, * prev = nullptr;
        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            }
            else {
                while (temp->next != head) temp = temp->next;
                node* toDelete = head;
                head = head->next;
                temp->next = head;
                delete toDelete;
            }
        }
        else {
            do
            {
                prev = temp;
                temp = temp->next;
            } while (temp->next != head && temp->data != value);
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
            }
        }
    }

    // Método find que retorna un bool y recibe un nodo por referencia
    bool find(int value, node*& pos) {
        if (!head) {
            pos = nullptr;
            return false;
        }

        node* temp = head;
        do {
            if (temp->data == value) {
                pos = temp;  // Valor encontrado
                return true;
            }
            temp = temp->next;
        } while (temp != head);  // Continuar hasta volver al nodo inicial.

        pos = nullptr;  // Si no se encuentra el valor
        return false;
    }

    void print() {
        if (!head) {
            cout << "Lista vacía.\n";
            return;
        }

        node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "head\n";
    }
};
