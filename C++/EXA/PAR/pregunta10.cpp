#include <iostream>

bool esPalindromo(const char* str) {
    // Obtener la longitud de la cadena
    int longitud = 0;
    const char* ptr = str;
    while (*ptr != '\0') {
        longitud++;
        ptr++;
    }

    // Comparar los caracteres de inicio y fin de la cadena
    ptr = str;
    const char* fin = str + longitud - 1;
    while (str < fin) {
        if (*ptr != *fin) {
            return false;
        }
        ptr++;
        fin--;
    }

    return true;
}

int main() {
    const char* palabra = "reconoce";
    if (esPalindromo(palabra)) {
        std::cout << "La palabra es un palíndromo." << std::endl;
    } else {
        std::cout << "La palabra no es un palíndromo." << std::endl;
    }

    return 0;
}