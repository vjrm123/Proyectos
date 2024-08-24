#include <iostream>

void Intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Ordenamiento_Cocktail(int* inicio, int* fin) {
    bool hubo_intercambio = true;

    while (hubo_intercambio) {
        hubo_intercambio = false;

        // Recorrido de izquierda a derecha
        int* i = inicio;
        while (i != fin) {
            if (*i > *(i + 1)) {
                Intercambiar(i, i + 1);
                hubo_intercambio = true;
            }
            i++;
        }

        // Si no hubo intercambios en el recorrido anterior, se termina
        if (!hubo_intercambio) {
            break;
        }

        hubo_intercambio = false;
        fin--;

        // Recorrido de derecha a izquierda
        i = fin;
        while (i != inicio) {
            if (*i < *(i - 1)) {
                Intercambiar(i, i - 1);
                hubo_intercambio = true;
            }
            i--;
        }

        inicio++;
    }
}

void imprimir_arreglo(int* inicio, int* final) {
    while (inicio <= final) {
        std::cout << *inicio << " ";
        inicio++;
    }
    std::cout << "\n";
}

int main() {
    int arr[] = { 5, 1, 4, 2, 8, 0, 9, 3, 7, 6,100, 34, 23,2,1,4,56,678,34,23,13,1,89,45,1000 };
    int n = sizeof(arr) / sizeof(int);

    int* inicio = arr;
    int* fin = arr + n - 1;

    std::cout << "Arreglo original: ";
    imprimir_arreglo(inicio, fin);

    Ordenamiento_Cocktail(inicio, fin);

    std::cout << "Arreglo ordenado: ";
    imprimir_arreglo(inicio, fin);

    return 0;
}