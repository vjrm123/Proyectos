#include <iostream>
#include <cstring>

bool esPalindromo(const char* cadena) {
    int longitud = strlen(cadena);
    const char* inicio = cadena;
    const char* fin = cadena + longitud - 1;

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
    const char* palabra1 = "hola";
    const char* palabra2 = "reconocer";

    if (esPalindromo(palabra1)) {
        std::cout << palabra1 << " es un palindromo" << std::endl;
    } else {
        std::cout << palabra1 << " no es un palindromo" << std::endl;
    }

    if (esPalindromo(palabra2)) {
        std::cout << palabra2 << " es un palindromo" << std::endl;
    } else {
        std::cout << palabra2 << " no es un palindromo" << std::endl;
    }

    return 0;
}