#include <iostream>

template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;

    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class Vector {
private:
    Nodo<T>* cabeza;  // Puntero al primer nodo
    Nodo<T>* cola;    // Puntero al último nodo

public:

    Vector() : cabeza(nullptr), cola(nullptr) {}

    ~Vector() {
        while (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void push_back(const T& valor) {
        Nodo<T>* nuevo_nodo = new Nodo<T>(valor);
        if (cola) {
            cola->siguiente = nuevo_nodo;
        }
        else {
            cabeza = nuevo_nodo;
        }
        cola = nuevo_nodo;
    }

    void pop_back() {
        if (cabeza == nullptr) return;

        if (cabeza == cola) {
            delete cabeza;
            cabeza = cola = nullptr;
        }
        else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != cola) {
                actual = actual->siguiente;
            }
            delete cola;
            cola = actual;
            cola->siguiente = nullptr;
        }
    }

    void push_front(const T& valor) {
        Nodo<T>* nuevo_nodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = cola = nuevo_nodo;
        }
        else {
            nuevo_nodo->siguiente = cabeza;
            cabeza = nuevo_nodo;
        }
    }

    void pop_front() {
        if (cabeza == nullptr) return;
        Nodo<T>* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        if (cabeza == nullptr) {
            cola = nullptr;
        }
    }

  
    void imprimir() const {
        Nodo<T>* actual = cabeza;
        std::cout << "Vector: ";
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_front(5);
    vec.push_back(208);
    vec.push_back(2);
    vec.push_back(28);
    vec.push_back(21);

    vec.imprimir();

    vec.pop_back();
    vec.pop_front();

    vec.imprimir();

    return 0;
}
