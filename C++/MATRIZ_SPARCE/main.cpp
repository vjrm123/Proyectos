#include <iostream>

using namespace std;

class Nodo {
public:
    int fil;
    int col;
    int dato;
    Nodo* next;

    Nodo(int f, int c, int d) : fil(f), col(c), dato(d), next(nullptr) {}
};

class SparseMatrix {
public:
    Nodo* Mat = nullptr;
    void set(int fil, int col, int dato);
    void print();
};

void SparseMatrix::set(int fil, int col, int dato) {
    if (dato == 0) return; // No se almacenan ceros

    Nodo* nuevoNodo = new Nodo(fil, col, dato);

    // Si la lista está vacía o el nuevo nodo debe ir al principio
    if (Mat == nullptr || (fil < Mat->fil) || (fil == Mat->fil && col < Mat->col)) {
        nuevoNodo->next = Mat;
        Mat = nuevoNodo;
        return;
    }

    Nodo* actual = Mat;
    Nodo* anterior = nullptr;

    while (actual != nullptr && (actual->fil < fil || (actual->fil == fil && actual->col < col))) {
        anterior = actual;
        actual = actual->next;
    }

    // Si encontramos un nodo con la misma posición
    if (actual != nullptr && actual->fil == fil && actual->col == col) {
        actual->dato = dato; // Actualizamos el dato
        delete nuevoNodo; // No necesitamos el nuevo nodo
        return;
    }

    // Insertar el nuevo nodo en la posición correcta
    nuevoNodo->next = actual;
    if (anterior != nullptr) {
        anterior->next = nuevoNodo;
    }
}

void SparseMatrix::print() {
    cout << "------Mat-----" << endl;
    for (Nodo* p = Mat; p; p = p->next)
        cout << "[" << p->fil << "][" << p->col << "] = " << p->dato << endl;
    cout << "------FIN Mat-----" << endl;
}

int main() {
    SparseMatrix SM;

    int a[10][10] = { {0,10,20,30,40,50,60,70,80,90},
                      {10,20,30,40,50,60,70,0,80,90},
                      {10,20,30,0,50,60,70,80,90,0},
                      {20,10,90,0,10,20,60,70,80,0},
                      {30,20,90,10,20,30,70,0,80,10},
                      {30,20,0,10,20,30,70,80,90,10},
                      {80,20,20,20,0,60,0,90,90,0},
                      {70,10,30,30,0,70,70,80,80,0},
                      {0,20,30,20,10,70,0,80,80,10},
                      {80,20,90,30,10,0,80,90,90,10},
    };

    int b[10][10] = { {10,0,0,0,0,0,0,0,0,0},
                      {0,20,0,0,0,0,0,0,0,0},
                      {0,0,30,0,0,0,0,0,0,0},
                      {0,0,0,40,0,0,0,0,0,0},
                      {0,0,0,0,50,0,0,0,0,0},
                      {0,0,0,0,0,60,0,0,0,0},
                      {0,0,0,0,0,0,70,0,0,0},
                      {0,0,0,0,0,0,0,80,0,0},
                      {0,0,0,0,0,0,0,0,90,0},
                      {0,0,0,0,0,0,0,0,0,100},
    };

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            SM.set(i, j, a[i][j]);

    SM.print();

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            SM.set(i, j, b[i][j]);

    SM.print();

    return 0;
}
