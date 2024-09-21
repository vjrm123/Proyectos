#include <iostream>

template<class T>
struct Nodo {
    T valor[5];
    T* top;
    int size;
    Nodo<T>* siguiente;

    Nodo(Nodo<T>* N = nullptr) : siguiente(N), size(0) {
        top = valor;
    }
};

template<class T, class O>
struct LE {
    Nodo<T>* head = nullptr;

    void ADD(T v);
    void Del(T v);
    bool Find(T v);
    void Print();
    ~LE();
};

template<class T>
class Asc {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};

template<class T>
class Dsc {
public:
    bool operator()(T a, T b) {
        return a > b;
    }
};

template<class T, class O>
void LE<T, O>::ADD(T v) {
    O comparar;
    Nodo<T>* actual = head;
    Nodo<T>* anterior = nullptr;

    if (!head) {
        head = new Nodo<T>();
        head->valor[0] = v;
        head->size = 1;
        head->top = &head->valor[0];
        return;
    }

    while (actual) {
        for (int i = 0; i < actual->size; ++i) {
            if (!comparar(actual->valor[i], v) && !comparar(v, actual->valor[i])) {
                return;
            }
        }
        if (actual->size < 5) {
            int pos = actual->size;
            for (int i = 0; i < actual->size; ++i) {
                if (comparar(v, actual->valor[i])) {
                    pos = i;
                    break;
                }
            }
            for (int j = actual->size; j > pos; --j) {
                actual->valor[j] = actual->valor[j - 1];
            }
            actual->valor[pos] = v;
            actual->size++;
            actual->top = &actual->valor[actual->size - 1];
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }
    Nodo<T>* nuevoNodo = new Nodo<T>();
    nuevoNodo->valor[0] = v;
    nuevoNodo->size = 1;
    nuevoNodo->top = &nuevoNodo->valor[0];
    anterior->siguiente = nuevoNodo;
}

template<class T, class O>
bool LE<T, O>::Find(T v) {
    Nodo<T>* actual = head;
    O comparar;

    while (actual) {
        for (int i = 0; i < actual->size; ++i) {
            if (!comparar(actual->valor[i], v) && !comparar(v, actual->valor[i])) {
                return true;
            }
        }
        actual = actual->siguiente;
    }
    return false;
}

template<class T, class O>
void LE<T, O>::Del(T v) {
    Nodo<T>* actual = head;
    Nodo<T>* previo = nullptr;
    O comparar;

    while (actual) {
        for (int i = 0; i < actual->size; ++i) {
            if (!comparar(actual->valor[i], v) && !comparar(v, actual->valor[i])) {
                for (int j = i; j < actual->size - 1; ++j) {
                    actual->valor[j] = actual->valor[j + 1];
                }
                actual->size--;

                if (actual->size == 0) {
                    if (!previo) {
                        head = actual->siguiente;
                    }
                    else {
                        previo->siguiente = actual->siguiente;
                    }
                    delete actual;
                }
                return;
            }
        }
        previo = actual;
        actual = actual->siguiente;
    }
}

template<class T, class O>
void LE<T, O>::Print() {
    Nodo<T>* actual = head;
    while (actual) {
        std::cout << "[";
        for (int i = 0; i < actual->size; ++i) {
            std::cout << actual->valor[i];
            if (i < actual->size - 1) std::cout << ",";
        }
        std::cout << "]";
        if (actual->siguiente) std::cout << "->";
        actual = actual->siguiente;
    }
    std::cout << "\n";
}

template<class T, class O>
LE<T, O>::~LE() {
    while (head) {
        Nodo<T>* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

int main() {
    LE<int, Asc<int>> listaAsc;
    listaAsc.ADD(10);
    listaAsc.ADD(2);
    listaAsc.ADD(3);
    listaAsc.ADD(4);
    listaAsc.ADD(5);
    listaAsc.Print();

    listaAsc.Del(5);
    listaAsc.Del(4);

    listaAsc.ADD(1);
    listaAsc.ADD(6);
    listaAsc.ADD(23);
    listaAsc.ADD(21);
    listaAsc.Print();

    LE<int, Dsc<int>> listaDsc;
    listaDsc.ADD(6);
    listaDsc.ADD(8);
    listaDsc.ADD(7);
    listaDsc.Print();

    return 0;
}


