#include <iostream>

bool esPalindromo(const int* array, int longitud) {
    const int* inicio = array;
    const int* fin = array + longitud - 1;

    while (inicio < fin) {
        if (*inicio != *fin) {
            return false;
        }
        inicio++;
        fin--;
    }

    return true;
}

int main() {
    int array1[] = {1, 2, 1};
    int array2[] = {1, 2, 3};

    if (esPalindromo(array1, 3)) {
        std::cout << "El array1 es un palindromo" << std::endl;
    } else {
        std::cout << "El array1 no es un palindromo" << std::endl;
    }

    if (esPalindromo(array2, 3)) {
        std::cout << "El array2 es un palindromo" << std::endl;
    } else {
        std::cout << "El array2 no es un palindromo" << std::endl;
    }

    return 0;
}