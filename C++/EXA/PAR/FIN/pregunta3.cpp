/*considere el siguiente segmento de codigo main.
escriba el codigo del functor increment y la funcion transform de tal forma que se obtenga la salida al momento
de ejecutar el programa*/

#include <iostream>


class increment {
public:
    increment(int to_add) : to_add(to_add) {}

    int operator()(int x) const {
        return x + to_add;
    }

private:
    int to_add;
};

void transform(int* start, int* end, increment func) {
    for (int* p = start; p != end; ++p) {
        *p = func(*p);
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(int);
    int to_add = 5;

    transform(arr, arr + n, increment(to_add));
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}