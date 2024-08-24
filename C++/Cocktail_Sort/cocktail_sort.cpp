#include <iostream>

void Intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Cocktail_Sort(int* inicio, int* fin) {
    bool hubo_intercambio = true;

    while (hubo_intercambio) {
        hubo_intercambio = false;

        int* i = inicio;
        while (i != fin) {
            if (*i > *(i + 1)) {
                Intercambiar(i, i + 1);
                hubo_intercambio = true;
            }
            i++;
        }

        if (!hubo_intercambio) {
            break;
        }

        hubo_intercambio = false;
        fin--;

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




