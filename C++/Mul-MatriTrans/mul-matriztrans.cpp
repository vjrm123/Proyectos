#include <iostream>

class Matriz {
private:
    int** matriz = nullptr;
    int filas;
    int columnas;

    void reservar();
    void liberar();

public:
    Matriz(int filas, int columnas);
    ~Matriz();

    void llenar();
    void imprimir() const;
    Matriz Transpuesta() const;
    Matriz multiplicar(const Matriz& otra) const;
};


Matriz::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    reservar();
}

Matriz::~Matriz() {
    liberar();
}

void Matriz::reservar() {
    matriz = new int* [filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }
}

void Matriz::liberar() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            //std::cout << "Liberando elemento en fila " << i << ", columna " << j << ": " << matriz[i][j] << "\n";
        }
        delete[] matriz[i];
        //std::cout << "Fila " << i << " liberada.\n";
    }
    delete[] matriz;
    //std::cout << "Matriz liberada.\n";
}

void Matriz::llenar() {
    int valor = 1;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valor++;
        }
    }
}

void Matriz::imprimir() const {
    for (int i = 0; i < filas; ++i) {
        std::cout << "| ";
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << " |\n";
    }
}

Matriz Matriz::Transpuesta() const {
    Matriz transpuesta(columnas, filas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            transpuesta.matriz[j][i] = matriz[i][j];
        }
    }
    return transpuesta;
}

Matriz Matriz::multiplicar(const Matriz& otra) const {
    Matriz resultado(filas, otra.columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < otra.columnas; ++j) {
            resultado.matriz[i][j] = 0;
            for (int k = 0; k < columnas; ++k) {
                resultado.matriz[i][j] += matriz[i][k] * otra.matriz[k][j];
            }
        }
    }
    return resultado;
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
    int filas, columnas, opcion;

    do {
        imprimirMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::cout << "Ingresa la cantidad de columnas de tu matriz: ";
            std::cin >> columnas;
            std::cout << "Ingresa la cantidad de filas de tu matriz: ";
            std::cin >> filas;

            Matriz matriz(filas, columnas);
            matriz.llenar();

            std::cout << "Matriz original:\n";
            matriz.imprimir();

            Matriz transpuesta = matriz.Transpuesta();
            std::cout << "\nMatriz transpuesta:\n";
            transpuesta.imprimir();

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            break;
        }
        case 2: {

            std::cout << "Ingresa la cantidad de columnas de tu matriz: ";
            std::cin >> columnas;
            std::cout << "Ingresa la cantidad de filas de tu matriz: ";
            std::cin >> filas;

            Matriz matriz(filas, columnas);
            matriz.llenar();

            std::cout << "Matriz original:\n";
            matriz.imprimir();

            Matriz transpuesta = matriz.Transpuesta();
            std::cout << "\nMatriz transpuesta:\n";
            transpuesta.imprimir();

            Matriz resultado = matriz.multiplicar(transpuesta);
            std::cout << "\nMatriz resultante de la multiplicación:\n";
            resultado.imprimir();

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            break;
        }
        case 3:
            std::cout << "Saliendo!!\n";
            break;
        default:
            std::cout << "Opcion no valida\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}