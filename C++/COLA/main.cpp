#include <iostream>

template<class T>
struct nodo {
    T valor;
    nodo* next = nullptr;
};

template<class T>
class Cola {
public:
    nodo<T>* head = nullptr;
    nodo<T>* tail = nullptr;

    void push(T valor) {
        nodo<T>* nuevo = new nodo<T>();
        nuevo->valor = valor;
        
        tail ? tail->next = nuevo : head = nuevo;
        tail = nuevo;
    }


    bool pop(T& valor) {
    if (!head) return false;

    valor = head->valor;
    nodo<T>* temp = head;
    head = head->next;
    
    tail = head ? tail : nullptr; 

    delete temp;
    return true;
}


    void print() {
        nodo<T>* actual = head;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->next;
        }
        std::cout << std::endl;
    }

    ~Cola() {
        T temp;
        while (pop(temp)); 
    }
};

int main() {
    Cola<int> miCola;
    
    miCola.push(1);
    miCola.push(2);
    miCola.push(3);

    miCola.print();  

    int valor;
    miCola.pop(valor);  
    std::cout << "pop Valor : " << valor << std::endl;

    miCola.print();  

    return 0;
}
