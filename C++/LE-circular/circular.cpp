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
        node* newNode = new node();
        newNode->data = value;

        if (!head) {
            head = newNode;
            newNode->next = head;
        }  
        else {
            node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void del(int value) {
        if (!head) return;

        node* temp = head, * prev = NULL;

        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = NULL;
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
            do {
                prev = temp;
                temp = temp->next;
            } while (temp != head && temp->data != value);

            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
            }
        }
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

int main() {
    int ADD[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    int DEL[10] = { 9, 7, 5, 3, 1, 10, 8, 6, 4, 2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++) {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++) {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }

    return 0;
}
