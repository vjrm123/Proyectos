#include <iostream>
#include <iomanip>

void ImprimirMatriz(int(*matriz)[3]) {
    int* puntero = (int*)matriz;

    for (int* fin = puntero + 9; puntero != fin; ++puntero) {
        if ((puntero - (int*)matriz) % 3 == 0) {
            std::cout << "|";
        }
        std::cout << std::setw(3) << *puntero;
        if ((puntero - (int*)matriz + 1) % 3 == 0) {
            std::cout << " |\n";
        }
    }
}




void Multiplicar_matriz(int(*M)[3][3]) {
    int* ptrM1 = &(*M)[0][0];
    int* ptrM2 = &(*(M + 1))[0][0];
    int* ptrResultado = &(*(M + 2))[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            int* ptrTemp1 = ptrM1;
            int* ptrTemp2 = ptrM2;

            for (int k = 0; k < 3; k++) {
                sum += *ptrTemp1 * *ptrTemp2;
                ptrTemp1++;
                ptrTemp2 += 3;
            }

            *ptrResultado = sum;
            ptrResultado++;
        }

        ptrM1 += 3;
        ptrM2++;
    }
}

void ImprimirMenu() {
    std::cout << "+***********************************+\n";
    std::cout << "|            MENU                   |\n";
    std::cout << "+***********************************+\n";
    std::cout << "| 1.Multiplicacion de matrices      |\n";
    std::cout << "| 2. Salir                          |\n";
    std::cout << "+***********************************+\n";
    std::cout << "ingresa una de las opciones: ";

}

int main() {
    int matriz[3][3][3] = {};
    int Opcion;

    do {
        ImprimirMenu();
        std::cin >> Opcion;

        switch (Opcion) {
        case 1:
            std::cout << "Ingrese los elementos de las dos primeras matrices:\n";

            for (int i = 0; i < 2; i++) {
                std::cout << "Matriz " << i << " : \n";
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        std::cout << "Elemento [" << i << "][" << j << "][" << k << "]: ";
                        std::cin >> matriz[i][j][k];
                    }
                }
            }
            system("cls");

            Multiplicar_matriz(matriz);
            std::cout << "La matriz resultante es:\n";
            ImprimirMatriz(matriz[2]);

            std::cout << "Pulse enter para continuar.\n";
            std::cin.ignore();
            std::cin.get();

            break;
        case 2:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion Invalida!!!\n";
            break;
        }

    } while (Opcion != 2);


    return 0;
}
