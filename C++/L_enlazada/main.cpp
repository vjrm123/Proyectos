#include <iostream>

template<class T>
struct Nodo {
    T valor;
    T valor[5];
    T *top;
    Nodo<T>* next;
    Nodo(T v, Nodo<T>* N = nullptr) : valor(v), next(N) {}
};

template<class T, class O>
struct LE {
    Nodo<T>* Head = nullptr;

    void ADD(T v);
    void Del(T v);
    bool Find(T v, Nodo<T>*& pos);
    void Print();
    ~LE(); 
};

template<class T>
class Asc {
public:
    inline bool operator()(T a, T b) { return a < b; }
};

template<class T>
class Dsc {
public:
    inline bool operator()(T a, T b) { return a > b; }
};

template<class T, class O>
void LE<T, O>::ADD(T v) {
    Nodo<T>* nuevo = new Nodo<T>(v);
    Nodo<T>* pos = nullptr;

    if (!Find(v, pos)) {
        if (!pos) {
            nuevo->next = Head;
            Head = nuevo;
        }
        else {
            nuevo->next = pos->next;
            pos->next = nuevo;
        }
    }
}

template<class T, class O>
bool LE<T, O>::Find(T v, Nodo<T>*& pos) {
    Nodo<T>* actual = Head;
    Nodo<T>* previo = nullptr;
    O comparar;

    while (actual && comparar(actual->valor, v)) {
        previo = actual;
        actual = actual->next;
    }
    pos = previo;
    return actual && actual->valor == v;
}

template<class T, class O>
void LE<T, O>::Del(T v) {
    Nodo<T>* pos = nullptr;
    if (Find(v, pos)) {
        Nodo<T>* toDelete = nullptr;
        if (!pos) {
            toDelete = Head;
            Head = Head->next;
        }
        else {
            toDelete = pos->next;
            pos->next = toDelete->next;
        }
        delete toDelete;
    }
}

template<class T, class O>
void LE<T, O>::Print() {
    Nodo<T>* actual = Head;
    std::cout << "Head -> ";
    while (actual) {
        std::cout << actual->valor << " -> ";
        actual = actual->next;
    }
    std::cout << "Null\n";
}

template<class T, class O>
LE<T, O>::~LE() {
    while (Head) {
        Nodo<T>* temp = Head;
        Head = Head->next;
        delete temp;
    }
}

int main() {
    LE<int, Asc<int>> listaAsc;
    listaAsc.ADD(0);
    listaAsc.ADD(3);
    listaAsc.ADD(1);
    listaAsc.ADD(2);
    listaAsc.ADD(2);
    
    listaAsc.Print();

    LE<int, Dsc<int>> listaDsc;
    listaDsc.ADD(3);
    listaDsc.ADD(1);
    listaDsc.ADD(7);
    listaDsc.ADD(2);

    listaDsc.Print();

    return 0;
}
