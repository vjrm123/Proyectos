#include <iostream>

template<class T>
void Swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
class Ascendente {
public:
    bool operator()(T a, T b) { return a > b; }
};

template<class T>
class Descendente {
public:
    bool operator()(T a, T b) { return a < b; }
};

template<class T, class O>
struct buble {
public:
    void operator()(T* inicio, T* final) {
        bool Intercambio = true;
        while (Intercambio) {
            Intercambio = false;
            for (T* i = inicio; i < final; i++) {
                if (O()(*i, *(i + 1))) {
                    Swap(i, i + 1);
                    Intercambio = true;
                }
            }
            final--;

            if (!Intercambio) break;

            Intercambio = false;
            for (T* i = final; i > inicio; i--) {
                if (O()(*(i - 1), *i)) {
                    Swap(i, i - 1);
                    Intercambio = true;
                }
            }
            inicio++;
        }
    }
};

template<class T>
void Print(T* inicio, T* final) {
    while (inicio <= final) {
        std::cout << *inicio++ << " ";
    }
    std::cout << "\n";
}

int main() {
    // Array de enteros
    int arrayInt[] = { 5, 3, 8, 6, 2 };
    int LongitudInt = sizeof(arrayInt) / sizeof(int);

    // Array de caracteres
    char arrayChar[] = { 'z', 'a', 'c', 'b', 'y' };
    int LongitudChar = sizeof(arrayChar) / sizeof(char);

    // Ordenar enteros en forma ascendente
    buble<int, Ascendente<int>> sorterIntAsc;
    sorterIntAsc(arrayInt, arrayInt + LongitudInt - 1);
    Print(arrayInt, arrayInt + LongitudInt - 1);

    // Ordenar enteros en forma descendente
    buble<int, Descendente<int>> sorterIntDesc;
    sorterIntDesc(arrayInt, arrayInt + LongitudInt - 1);
    Print(arrayInt, arrayInt + LongitudInt - 1);

    // Ordenar caracteres en forma ascendente
    buble<char, Ascendente<char>> sorterCharAsc;
    sorterCharAsc(arrayChar, arrayChar + LongitudChar - 1);
    Print(arrayChar, arrayChar + LongitudChar - 1);

    // Ordenar caracteres en forma descendente
    buble<char, Descendente<char>> sorterCharDesc;
    sorterCharDesc(arrayChar, arrayChar + LongitudChar - 1);
    Print(arrayChar, arrayChar + LongitudChar - 1);

    return 0;
}
