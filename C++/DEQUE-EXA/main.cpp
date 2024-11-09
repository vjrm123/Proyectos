#include <iostream>

class XVector {
public:
    XVector(int size_map, int size_vec);
    ~XVector();

    void push_back(int val);
    void push_front(int val);
    int& operator[](int index);

    int** map;
    int size_map, size_vec;
    int size;  // Total de elementos
    int front, back;     // Índices de inserción en front y back
    int current_map_size; // Número actual de bloques en uso

private:
    void expand_map(); 
};

// Constructor
XVector::XVector(int sm, int sv) {
    size_map = sm;
    size_vec = sv;
    map = new int* [size_map];
    for (int i = 0; i < size_map; i++) {
        map[i] = new int[size_vec];
    }

    size = 0;
    front = size_map * size_vec / 2;  // Iniciamos en el centro
    back = front;                      // Inicializamos back en el mismo lugar
    current_map_size = 1;             // Solo hay un bloque usado inicialmente
}

// Destructor
XVector::~XVector() {
    for (int i = 0; i < size_map; i++) {
        delete[] map[i];
    }
    delete[] map;
}

// Método para expandir el mapa cuando esté lleno
void XVector::expand_map() {
    int new_size_map = size_map * 2; // Duplicar el tamaño del mapa
    int** new_map = new int* [new_size_map]; // Crear un nuevo mapa

    // Copiar punteros de bloques antiguos al nuevo mapa
    for (int i = 0; i < size_map; i++) {
        new_map[i] = map[i]; // Copiar bloques antiguos
    }

    // Inicializar nuevos bloques en el nuevo mapa
    for (int i = size_map; i < new_size_map; i++) {
        new_map[i] = new int[size_vec]; // Crear nuevos bloques
    }

    delete[] map; // Liberar el antiguo mapa
    map = new_map; // Asignar el nuevo mapa
    size_map = new_size_map; // Actualizar el tamaño del mapa
}

// push_back: Inserta elementos al final
void XVector::push_back(int val) {
    if (back >= size_map * size_vec) {
        expand_map(); // Duplicar el tamaño si es necesario
    }
    map[back / size_vec][back % size_vec] = val;
    back++;
    size++;
}

// push_front: Inserta elementos al inicio
void XVector::push_front(int val) {
    if (front == 0) {
        expand_map(); // Duplicar el tamaño si es necesario
        front += size_vec; // Aumentar el índice front al nuevo bloque
    }
    front--;
    map[front / size_vec][front % size_vec] = val;
    size++;
}

// Operador [] para acceder a los elementos
int& XVector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    int real_index = front + index;
    return map[real_index / size_vec][real_index % size_vec];
}

// Función print (sin modificar)
void print(XVector* p) {
    for (int i = 0; i < p->size; i++)
        std::cout << (*p)[i] << " ";
    std::cout << "\n";
}

// Función main (sin modificar)
int main() {
    XVector v(4, 3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);
}
