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

    // Método para insertar un valor al final de la cola (tail)
    void push(T valor) {
        nodo<T>* nuevo = new nodo<T>();
        nuevo->valor = valor;
        
        if (tail != nullptr) {
            tail->next = nuevo;
        }
        tail = nuevo;

        if (head == nullptr) {
            head = tail;
        }
    }

    // Método para extraer un valor desde el frente de la cola (head)
    bool pop(T& valor) {
        if (head == nullptr) {
            return false;  // Cola vacía
        }

        valor = head->valor;
        nodo<T>* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;  
        }

        delete temp;
        return true;
    }

    // Método para imprimir la cola desde head hasta tail
    void print() {
        nodo<T>* actual = head;
        while (actual != nullptr) {
            std::cout << actual->valor << " ";
            actual = actual->next;
        }
        std::cout << std::endl;
    }

    // Destructor para liberar la memoria de la cola
    ~Cola() {
        T temp;
        while (pop(temp));  // Vaciar la cola liberando memoria
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
    std::cout << "Valor extraido: " << valor << std::endl;

    miCola.print();  

    return 0;
}
