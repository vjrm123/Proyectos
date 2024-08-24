#include <iostream>

class CocktailSort {
    private:
        void Intercambiar(int* a, int* b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
    public:
        void cocktail_Sort(int* Inicio, int* Final) {
            bool hubo_intercambio = true;

            while (hubo_intercambio) {
                hubo_intercambio = false;

                int* Indicador = Inicio;
                while (Indicador != Final) {
                    if (*Indicador > *(Indicador + 1)) {
                        Intercambiar(Indicador, Indicador + 1);
                        hubo_intercambio = true;
                    }
                    Indicador++;
                }

                if (!hubo_intercambio) {
                    break;
                }

                hubo_intercambio = false;
                Final--;

                Indicador = Final;
                while (Indicador != Inicio) {
                    if (*Indicador < *(Indicador - 1)) {
                        Intercambiar(Indicador, Indicador - 1);
                        hubo_intercambio = true;
                    }
                    Indicador--;
                }

                Inicio++;
            }
        }
};