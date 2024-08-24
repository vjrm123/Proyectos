#include <iostream>
using namespace std;

void asignarMemoria(int**& A, int filas, int columnas) {
    A = new int* [filas];
    for (int** P = A; P < A + filas; ++P) {
        *P = new int[columnas];
    }
}

void liberarMemoria(int** A, int filas) {
    for (int** P = A; P < A + filas; ++P) {
        delete[] * P;
    }
    delete[] A;
}

int** transpuestaMatriz(int** A, int filas, int columnas) {
    int** matrizTranspuesta = nullptr;
    asignarMemoria(matrizTranspuesta, columnas, filas);

    for (int** P = A; P < A + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            *(matrizTranspuesta[Q - *P] + (P - A)) = *Q;
        }
    }
    return matrizTranspuesta;
}

void inicializarMatriz(int** A, int filas, int columnas) {
    int valor = 1;
    for (int** P = A; P < A + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            *Q = valor++;
        }
    }
}

void imprimirMatriz(int** A, int filas, int columnas) {
    for (int** P = A; P < A + filas; ++P) {
        for (int* Q = *P; Q < *P + columnas; ++Q) {
            cout << *Q << " ";
        }
        cout << "\n";
    }
}

int** multiplicarMatrices(int** A, int filasA, int columnasA, int** B, int filasB, int columnasB) {
    int** Resultado = nullptr;
    asignarMemoria(Resultado, filasA, columnasB);

    for (int** filaA = A, **filaRes = Resultado; filaA < A + filasA; ++filaA, ++filaRes) {
        for (int* ptr = *filaRes; ptr < *filaRes + columnasB; ++ptr) {
            *ptr = 0;
            for (int** filaB = B; filaB < B + filasB; ++filaB) {
                *ptr += *(*filaA + (filaB - B)) * *(*filaB + (ptr - *filaRes));
            }
        }
    }
    return Resultado;
}

void imprimirMenu() {
    std::cout << "+***********************************+\n";
    std::cout << "|            MENU                   |\n";
    std::cout << "+***********************************+\n";
    std::cout << "| 1. Calcular transpuesta           |\n";
    std::cout << "| 2. Multiplicar por transpuesta    |\n";
    std::cout << "| 3. Salir                          |\n";
    std::cout << "+***********************************+\n";
    std::cout << "Ingresa una de las opciones: ";
}


int main() {

    int Opcion, Columna, Fila;
    int** Matriz = nullptr;
    int** matrizResultado = nullptr;
    int** matrizTranspuesta = nullptr;

    do {
        imprimirMenu();
        std::cin >> Opcion;
        switch (Opcion) {

        case 1:
            std::cout << "Ingrese la columna: "; std::cin >> Columna;
            std::cout << "Ingrese la fila: "; std::cin >> Fila;
            asignarMemoria(Matriz, Fila, Columna);
            inicializarMatriz(Matriz, Fila, Columna);
            matrizTranspuesta = transpuestaMatriz(Matriz, Fila, Columna);
            cout << "Matriz original:\n";
            imprimirMatriz(Matriz, Fila, Columna);
            cout << "Matriz transpuesta:\n";
            imprimirMatriz(matrizTranspuesta, Columna, Fila);

            liberarMemoria(Matriz, Fila);
            liberarMemoria(matrizTranspuesta, Columna);

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            break;
        case 2:
            std::cout << "Ingrese la columna: "; std::cin >> Columna;
            std::cout << "Ingrese la fila: "; std::cin >> Fila;

            asignarMemoria(Matriz, Fila, Columna);
            inicializarMatriz(Matriz, Fila, Columna);
            matrizTranspuesta = transpuestaMatriz(Matriz, Fila, Columna);
            matrizResultado = multiplicarMatrices(Matriz, Fila, Columna, matrizTranspuesta, Columna, Fila);

            cout << "Matriz original:\n";
            imprimirMatriz(Matriz, Fila, Columna);
            cout << "\nMatriz transpuesta:\n";
            imprimirMatriz(matrizTranspuesta, Columna, Fila);
            cout << "\nMatriz resultado (Matriz * MatrizTranspuesta):\n";
            imprimirMatriz(matrizResultado, Fila, Fila);

            liberarMemoria(Matriz, Fila);
            liberarMemoria(matrizTranspuesta, Columna);
            liberarMemoria(matrizResultado, Fila);

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            break;

        default:
            break;
        }
    } while (Opcion != 3);


    return 0;
}