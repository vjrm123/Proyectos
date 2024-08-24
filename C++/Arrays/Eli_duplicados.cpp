#include <iostream>

int* eliminarDuplicados(int* inicio, int* fin) {
    int* destino = inicio;

    for (int* ptr = inicio; ptr != fin; ++ptr) {
        bool duplicado = false;
        // Verificamos si el elemento actual ya existe en el rango procesado
        for (int* comparador = inicio; comparador < destino; ++comparador) {
            if (*ptr == *comparador) {
                duplicado = true;
                break;
            }
        }
        // Si no es un duplicado, lo copiamos al nuevo rango
        if (!duplicado) {
            *destino++ = *ptr;
        }
    }
    return destino; // Devolvemos el nuevo final del array
}

void imprimirArray(int* inicio, int* fin) {
    while (inicio < fin) {
        std::cout << *inicio << " ";
        inicio++;
    }
    std::cout << std::endl;
}

int main() {
    int array[] = { 1, 7, 11, 13, 4, 8, 12, 20, 1, 7, 11 };
    int size = sizeof(array) / sizeof(array[0]);

    int* nuevoFin = eliminarDuplicados(array, array + size);
    int nuevoSize = nuevoFin - array;
    imprimirArray(array, array + nuevoSize);

    return 0;
}