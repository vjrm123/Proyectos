#include <iostream>

template<class T>
struct nodo {
    T valor;
    nodo* siguiente = nullptr;
};

template<class T>
class Pila {
public:
    nodo<T>* top = nullptr;

    void push(T valor) {
        nodo<T>* nuevo = new nodo<T>();
        nuevo->valor = valor;
        nuevo->siguiente = top;
        top = nuevo;
    }

    bool pop() {
        if (top == nullptr) {
            return false;  
        }
        
        nodo<T>* temp = top;
        top = top->siguiente;
        delete temp;
        return true;
    }

    void print() {
        nodo<T>* actual = top;
        while (actual != nullptr) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
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
