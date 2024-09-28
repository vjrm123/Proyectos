
#include <iostream>

template<typename T>
struct nodo {
    T* arr;
    int tamanio = 5;
    nodo* next;
    nodo(T v = 0, nodo* n = nullptr) {
        arr = new T[tamanio];
        *arr = v;
        next = n;
    };
    ~nodo() {
        delete[] arr;
    }
};

template<typename T>
class LE {
private:
    nodo<T>* inicio = nullptr;
    nodo<T>* fin = nullptr;
    T* dato_inicio = nullptr;
    T* dato_fin = nullptr;
public:
    LE() : inicio(nullptr), fin(nullptr), dato_inicio(nullptr), dato_fin(nullptr) {}
    bool find(T v, nodo<T>*& p, nodo<T>*& p_ant, T*& q);
    bool add(T v);
    bool del(T v);
    void print();
    ~LE();
};

template<typename T>
bool LE<T>::find(T v, nodo<T>*& p, nodo<T>*& p_ant, T*& q) {
    if (!inicio) { return false; }
    p = inicio;
    p_ant = inicio;

    while (p->next && (*p->next->arr <= v || v > *(p->arr + p->tamanio - 1) && v < *(p->next->arr))) {
        p_ant = p;
        p = p->next;
    }

    if (p == fin && dato_fin == fin->arr + fin->tamanio - 1 && *dato_fin < v) {
        p_ant = p;
        p = p->next;
        return false;
    }

    for (q = p->arr; *q < v && (p != fin || (p == fin && q <= dato_fin)); q++);
    return (q <= dato_fin) && (*q == v);
}

template<typename T>
bool LE<T>::add(T v) {
    T* dato;
    nodo<T>* p;
    nodo<T>* p_ant;
    if (find(v, p, p_ant, dato)) return false;
    if (!inicio) {
        nodo<T>* nuevo = new nodo<T>(v);
        inicio = fin = nuevo;
        dato_inicio = dato_fin = inicio->arr;
        return true;
    };
    if (dato_fin == fin->arr + fin->tamanio - 1) {
        nodo<T>* nuevo = new nodo<T>();
        fin->next = nuevo;
        fin = nuevo;
        dato_fin = fin->arr;
    }
    else { dato_fin++; }
    if (!p) { p = fin; dato = p->arr; }
    T temp = 0;
    while (dato != dato_fin) {
        temp = *dato;
        *dato = v;
        v = temp;
        if (dato == p->arr + p->tamanio - 1) {
            p = p->next;
            dato = p->arr;
        }
        else { dato++; }
    }
    *dato_fin = v;
    return true;
}

template<typename T>
bool LE<T>::del(T v) {
    T* dato;
    nodo<T>* p;
    nodo<T>* p_ant;
    if (!find(v, p, p_ant, dato)) return false;
    if (dato_fin == dato_inicio) {
        delete p;
        inicio = fin = nullptr;
        dato_inicio = dato_fin = nullptr;
        return true;
    }
    while (dato != dato_fin) {
        if (dato == p->arr + p->tamanio - 1) {
            *dato = *(p->next->arr);
            dato = p->next->arr;
            p_ant = p;
            p = p->next;
        }
        else { *dato = *(dato + 1); dato++; }
    }
    if (dato_fin == fin->arr) {
        delete fin;
        fin = p_ant;
        fin->next = nullptr;
        dato_fin = fin->arr + fin->tamanio - 1;
    }
    else { dato_fin--; }
    return true;
}

template<typename T>
void LE<T>::print() {
    if (!inicio) {
        std::cout << "[]";
        return;
    }
    nodo<T>* p = inicio;
    T* end = inicio->arr + inicio->tamanio - 1;
    for (T* p_data = dato_inicio; p;) {
        if (p_data == p->arr) {
            std::cout << "[";
        }
        if (p == fin && p_data > dato_fin) {
            std::cout << "-";
        }
        else {
            std::cout << *p_data;
        }
        if (p_data == end) {
            std::cout << "]";
            p = p->next;
            if (p) {
                end = p->arr + p->tamanio - 1;
                p_data = p->arr;
                std::cout << " -> ";
            }
            continue;
        }
        else {
            std::cout << ", ";
        }
        p_data++;
    }
}

template<typename T>
LE<T>::~LE() {
    nodo<T>* p = inicio;
    while (inicio) {
        inicio = inicio->next;
        delete p;
        p = inicio;
    }
}

int main() {
    LE<int> lista;  

    lista.add(24);
    lista.add(50);
    lista.add(46);
    lista.add(12);
    lista.add(23);
    lista.add(123);
    lista.add(235);

    lista.print();
    std::cout << "\n";

    lista.del(23);
    lista.del(12);

    std::cout << "Despues de borrar:\n";
    lista.print();
    std::cout << "\n";
}
