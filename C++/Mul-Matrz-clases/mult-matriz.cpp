#include <iostream>
using namespace std;

class Matriz {
private:
    int** datos;
    int filas;
    int columnas;

    void asignarArreglo(int**& A, int filas, int columnas);
    void liberarArreglo(int** A, int filas);
    void inicializarMatriz(int** A, int filas, int columnas);

public:
    Matriz(int f, int c);
    ~Matriz();

    void imprimirMatriz() const;
    Matriz* transponerMatriz() const;
    Matriz* multiplicarMatrices(const Matriz* B) const;
};

// Definiciones de las funciones privadas
void Matriz::asignarArreglo(int**& A, int filas, int columnas) {
    A = new int* [filas];
    for (int** P = A; P < A + filas; ++P) {
        *P = new int[columnas];
    }
}

void Matriz::liberarArreglo(int** A, int filas) {
    for (int** P = A; P < A + filas; ++P) {
        delete[] * P;
    }
    delete[] A;
}

void Matriz::inicializarMatriz(int** A, int filas, int columnas) {
    int valor = 1;
    for (int** P = A; P < A + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            *Q = valor++;
        }
    }
}

// Definiciones de las funciones públicas
Matriz::Matriz(int f, int c) : filas(f), columnas(c) {
    asignarArreglo(datos, filas, columnas);
    inicializarMatriz(datos, filas, columnas);
}

Matriz::~Matriz() {
    liberarArreglo(datos, filas);
}

void Matriz::imprimirMatriz() const {
    for (int** P = datos; P < datos + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            cout << *Q << " ";
        }
        cout << "\n";
    }
}

Matriz* Matriz::transponerMatriz() const {
    Matriz* transpuesta = new Matriz(columnas, filas);
    for (int** P = datos; P < datos + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            *(transpuesta->datos[Q - *P] + (P - datos)) = *Q;
        }
    }
    return transpuesta;
}

Matriz* Matriz::multiplicarMatrices(const Matriz* B) const {
    Matriz* resultado = new Matriz(filas, B->columnas);
    for (int** filaA = datos, **filaRes = resultado->datos;  filaA < datos + filas;  ++filaA, ++filaRes) {
        for (int* elemRes = *filaRes;  elemRes < *filaRes + B->columnas;  ++elemRes) {
            *elemRes = 0;
            for (int** filaB = B->datos; filaB < B->datos + B->filas; ++filaB) {
                *elemRes += *(*filaA + (filaB - B->datos)) * *(*filaB + (elemRes - *filaRes));
            }
        }
    }
    return resultado;
}

int main() {
    int filas, columnas;
    cout << "Introduce el numero de filas: ";
    cin >> filas;
    cout << "Introduce el numero de columnas: ";
    cin >> columnas;

    Matriz A(filas, columnas);

    // Calcular la transpuesta del arreglo 2D
    Matriz* matrizTranspuesta = A.transponerMatriz();

    // Multiplicar A por su transpuesta
    Matriz* matrizResultado = A.multiplicarMatrices(matrizTranspuesta);

    // Imprimir el contenido de los arreglos 2D originales, transpuestos y resultado
    cout << "Matriz original:\n";
    A.imprimirMatriz();
    cout << "Matriz transpuesta:\n";
    matrizTranspuesta->imprimirMatriz();
    cout << "Matriz resultado (A * A^T):\n";
    matrizResultado->imprimirMatriz();

    // Liberar memoria
    delete matrizTranspuesta;
    delete matrizResultado;

    return 0;
}
