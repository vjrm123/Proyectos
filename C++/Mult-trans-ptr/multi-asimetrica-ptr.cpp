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

    int Opcion, Columna1, Fila1, Columna2, Fila2;
    int** Matriz1 = nullptr;
    int** Matriz2 = nullptr;
    int** matrizResultado = nullptr;
    int** matrizTranspuesta = nullptr;

    do {
        imprimirMenu();
        std::cin >> Opcion;
        switch (Opcion) {

        case 1:
            std::cout << "Ingrese la columna: "; std::cin >> Columna1;
            std::cout << "Ingrese la fila: "; std::cin >> Fila1;
            asignarMemoria(Matriz1, Fila1, Columna1);
            inicializarMatriz(Matriz1, Fila1, Columna1);
            matrizTranspuesta = transpuestaMatriz(Matriz1, Fila1, Columna1);
            cout << "Matriz original:\n";
            imprimirMatriz(Matriz1, Fila1, Columna1);
            cout << "Matriz transpuesta:\n";
            imprimirMatriz(matrizTranspuesta, Columna1, Fila1);

            liberarMemoria(Matriz1, Fila1);
            liberarMemoria(matrizTranspuesta, Columna1);

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            system("cls");

            break;
        case 2:
            std::cout << "Ingrese la columna de la primera matriz: "; std::cin >> Columna1;
            std::cout << "Ingrese la fila de la primera matriz: "; std::cin >> Fila1;
            std::cout << "Ingrese la columna de la segunda matriz: "; std::cin >> Columna2;
            std::cout << "Ingrese la fila de la segunda matriz: "; std::cin >> Fila2;

            if (Columna1 != Fila2) {
                std::cout << "\nLas matrices no se pueden multiplicar ( LA COLUMNA DE LA PRIMERA MATRIZ DEBE SER IGUAL A LA FILA DE LA SEGUNDA MATRIZ)\n";
                break;
            }

            asignarMemoria(Matriz1, Fila1, Columna1);
            inicializarMatriz(Matriz1, Fila1, Columna1);
            asignarMemoria(Matriz2, Fila2, Columna2);
            inicializarMatriz(Matriz2, Fila2, Columna2);

            matrizResultado = multiplicarMatrices(Matriz1, Fila1, Columna1, Matriz2, Fila2, Columna2);

            cout << "Primera matriz:\n";
            imprimirMatriz(Matriz1, Fila1, Columna1);
            cout << "\nSegunda matriz:\n";
            imprimirMatriz(Matriz2, Fila2, Columna2);
            cout << "\nMatriz resultado Primera matriz * Segunda matriz:\n";
            imprimirMatriz(matrizResultado, Fila1, Columna2);

            liberarMemoria(Matriz1, Fila1);
            liberarMemoria(Matriz2, Fila2);
            liberarMemoria(matrizResultado, Fila1);

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            system("cls");

            break;

        default:
            break;
        }
    } while (Opcion != 3);

    return 0;
}