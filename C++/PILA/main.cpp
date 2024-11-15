#include <iostream>

template<class T>
struct node {
    T value;
    node* next;
    node(T value, node* next = nullptr) : value(value), next(next) {}
};

template<class T>
class Pila {
public:
    node<T>* top = nullptr;

    void push(T value) {
        top = new node<T>(value, top);  
    }

    bool pop() {
        if (!top) return false;
        node<T>* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    void print() {
        node<T>* current = top;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Pila() {
        while (pop());
    }
};

int main() {
    Pila<int> miPila;

    miPila.push(10);
    miPila.push(20);
    miPila.push(30);

    miPila.print(); 

    miPila.pop();  
    miPila.print(); 

    return 0;
}
