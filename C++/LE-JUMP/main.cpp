#include <iostream>
using namespace std;


template <class T>
class Node {
public:
    T value;
    Node* next;
    Node* jump;

    Node(T value, Node* next = nullptr, Node* jump = nullptr) {
        this->value = value;
        this->next = next;
        this->jump = jump;
    }
};

template <class T>
class CircularList {
private:

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:

    int size = 0;
    int k = 1;

    CircularList(int k) {
        this->k = k;
    }

    // Método para actualizar los punteros jump
    void updateJumps() {
        if (size == 0) return;

        Node<T>* current = head;
        do {
            Node<T>* target = current;
            for (int i = 0; i < k; ++i) {
                target = target->next;  // Avanza k posiciones
            }
            current->jump = target;  // Actualiza el puntero jump
            current = current->next;
        } while (current != head);
    }

    // Desafío adicional: Método para revertir los punteros jump
    void reverseJumps() {
        if (size == 0) return;

        Node<T>* current = head;
        do {
            Node<T>* target = current;
            for (int i = 0; i < k; ++i) {
                target = target->next;  // Avanza k posiciones (original jump)
            }

            Node<T>* reverse_target = current;
            for (int i = 0; i < k; ++i) {
                // Vamos hacia atrás para encontrar el nodo k-ésimo anterior
                Node<T>* temp = head;
                while (temp->next != reverse_target) {
                    temp = temp->next;
                }
                reverse_target = temp;
            }
            current->jump = reverse_target;  // Asigna el puntero jump invertido
            current = current->next;
        } while (current != head);
    }

    void push(T val) {

        ++size;

        if (!head) {
            head = new Node<T>(val);
            head->next = head;
            head->jump = head;

            tail = head;
        }
        else {
            tail->next = new Node<T>(val, head);
            tail = tail->next;

            updateJumps();
        }

    }

    void pop() {

        if (!head) return;

        --size;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            tail->next = head->next;
            delete head;
            head = tail->next;

            updateJumps();
        }

    }


    void print() {

        cout << "Circular List (" << size << "):";
        if (!head) {
            cout << "NULL\n" << endl;
            return;
        }

        cout << endl << "\tNode value " << head->value << " -> Jump value ";
        if (head->jump) cout << head->jump->value;
        else cout << "NULL";

        for (Node<T>* p = head->next; p != head; p = p->next) {
            cout << endl << "\tNode value " << p->value << " -> Jump value ";
            if (p->jump) cout << p->jump->value;
            else cout << "NULL";
        }

        cout << endl << endl;
    }
};

int main() {

    cout << "\n----- Test 1 -----\n";
    CircularList<int> circularList(4);

    // Test Case 1: Basic Push and Jump Updates
    cout << "Test Case 1: Basic Push\n";
    for (int i = 0; i < 5; ++i) {
        circularList.push(i);
        circularList.print();
    }

    // Test Case 2: Remove nodes and recheck jumps
    cout << "Test Case 2: Pop and Push\n";
    circularList.pop();  // Remove one node
    circularList.print();

    circularList.push(5);  // Add a new node
    circularList.print();

    // Test Case 3: More pushes and pops to check the integrity
    cout << "Test Case 3: Push More\n";
    circularList.push(6);
    circularList.push(7);
    circularList.push(8);
    circularList.print();

    cout << "Pop some elements and update\n";
    circularList.pop();
    circularList.pop();
    circularList.print();

    // Test Case 4: Full circularity after multiple operations
    cout << "Test Case 4: Circularity Check after multiple operations\n";
    for (int i = 9; i < 12; ++i) {
        circularList.push(i);
    }
    circularList.print();

    // Test Case 5: Empty list handling
    cout << "Test Case 5: Empty List\n";
    while (circularList.size > 0) {
        circularList.pop();
        circularList.print();
    }


    cout << "\n\n----- Test 2 -----\n";
    CircularList<int> circularList2(5);

    // Test Case 1: Basic Push and Jump Updates
    cout << "Test Case 1: Basic Push\n";
    for (int i = 0; i < 5; ++i) {
        circularList2.push(i);
        circularList2.print();
    }

    // Test Case 2: Remove nodes and recheck jumps
    cout << "Test Case 2: Pop and Push\n";
    circularList2.pop();  // Remove one node
    circularList2.print();

    circularList2.push(5);  // Add a new node
    circularList2.print();

    // Test Case 3: More pushes and pops to check the integrity
    cout << "Test Case 3: Push More\n";
    circularList2.push(6);
    circularList2.push(7);
    circularList2.push(8);
    circularList2.print();

    cout << "Pop some elements and update\n";
    circularList2.pop();
    circularList2.pop();
    circularList2.print();

    // Test Case 4: Full circularity after multiple operations
    cout << "Test Case 4: Circularity Check after multiple operations\n";
    for (int i = 9; i < 12; ++i) {
        circularList2.push(i);
    }
    circularList2.print();

    // Test Case 5: Empty list handling
    cout << "Test Case 5: Empty List\n";
    while (circularList2.size > 0) {
        circularList2.pop();
        circularList2.print();
    }

    // Desafío adicional: Revertir los punteros jump
    cout << "\n\n--- Desafío adicional: Invertir jumps ---\n";
    CircularList<int> circularList3(3);
    for (int i = 0; i < 7; ++i) {
        circularList3.push(i);
    }
    circularList3.print();

    // Invertir jumps y mostrar resultado
    circularList3.reverseJumps();
    cout << "Jumps invertidos:\n";
    circularList3.print();

    return 0;
}
