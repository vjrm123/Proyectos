#include<iostream>

template<class T>
struct Nodo {
    T valor;
    Nodo<T>* Next;

    Nodo(T valor, Nodo<T>* Next = nullptr) : valor(valor), Next(Next) {}
};

template<class T, class O>
struct LE {
    Nodo<T>* Head = nullptr;

    void ADD(T valor);
    void DEL(T valor);
    bool Find(T valor, Nodo<T>*& pos);
    void Print();
   
};

template<class T>
class ASC {
public:
    bool operator()(T a, T b) { return a < b; }
};

template<class T>
class DSC {
public:
    bool operator()(T a, T b) { return a > b; }
};

template<class T, class O>
void LE<T, O>::Print() {
    Nodo<T>* current = Head;  // Usamos un puntero auxiliar
    std::cout << "Head-> ";
    while (current) {
        std::cout << current->valor << "-> ";
        current = current->Next;
    }
    std::cout << "NULL\n";
}

template<class T, class O>
void LE<T, O>::ADD(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    Nodo<T>* pos = nullptr;

    if (!Find(valor, pos)) {
        if (!pos) {
            nuevo->Next = Head;
            Head = nuevo;
        } else {
            nuevo->Next = pos->Next;
            pos->Next = nuevo;
        }
    }
}

template<class T, class O>
bool LE<T, O>::Find(T v, Nodo<T>*& pos) {
    Nodo<T>* prev = nullptr;
    Nodo<T>* current = Head;
    O order;  // El objeto comparador

    while (current && order(current->valor, v)) {
        prev = current;
        current = current->Next;
    }

    pos = prev;
    return current && current->valor == v;
}

int main() {
    LE<int, ASC<int>> listaAsc;
    listaAsc.ADD(0);
    listaAsc.ADD(3);
    listaAsc.ADD(1);
    listaAsc.ADD(2);
    listaAsc.ADD(2);  // Este valor ya está, por lo que no se inserta.

    listaAsc.Print();  
    // Debería imprimir: Head-> 0-> 1-> 2-> 3-> NULL

    LE<int, DSC<int>> listaDsc;
    listaAsc.ADD(0);
    listaAsc.ADD(3);
    listaAsc.ADD(1);
    listaAsc.ADD(2);
    listaAsc.ADD(2);  // Este valor ya está, por lo que no se inserta.

    listaAsc.Print(); 
}
