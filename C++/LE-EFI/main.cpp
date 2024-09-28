#include <iostream>

struct Node{
    int valor;
    Node* next;

    Node(int valor, Node* next = nullptr) : valor(valor), next(next){}
};

struct LE{
    Node* head = nullptr;

    bool Find(int valor, Node**& pos);
    bool Insertar(int valor);
    bool borrar(int valor);
    void Print();
};

bool LE::Find(int valor, Node**& pos){
    pos = &head;
    while(*pos && (*pos)->valor < valor){
        pos = &((*pos)->next);
    }
    return *pos && (*pos)->valor == valor;
}

bool LE::Insertar(int valor){
    Node** pos;
    if(Find(valor, pos)) return 0;
    Node* nuevo = new Node(valor);
    nuevo->next = *pos;
    *pos = nuevo;
    return 1;
}

bool LE::borrar(int valor){
    Node** pos;
    if(!Find(valor, pos)) return 0;
    Node* toDelete = *pos;
    *pos = toDelete->next;
    delete toDelete;
    return 1;
}

void LE::Print(){
    Node* actual = head;
    std::cout<<"HEAD->";
    while(actual){
        std::cout<<actual->valor<<"->";
        actual = actual->next;
    }
    std::cout<<"NUll\n";
}

int main() {
    LE lista;

    // Insertar algunos valores
    lista.Insertar(5);
    lista.Insertar(3);
    lista.Insertar(8);
    lista.Insertar(1);

    std::cout << "Lista después de insertar: ";
    lista.Print();

    // Borrar un valor
    lista.borrar(3);

    std::cout << "Lista después de borrar 3: ";
    lista.Print();

    // Intentar borrar un valor que no existe
    if (!lista.borrar(10)) {
        std::cout << "No se encontró el valor 10 para borrar.\n";
    }

    return 0;
}


