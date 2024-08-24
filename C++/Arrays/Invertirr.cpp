#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Invertir(int *inicio, int *final) {
    while(inicio < final) {
        swap(inicio++, final--);
    }
}

void Imprimir(int *inicio, int *final) {
    while(inicio < final) {
        std::cout<< *inicio++ << " ";
    }
    std::cout<< "\n";
}

int main(){
    int array[] = {1,2,3,4,5,6};
    int size = sizeof(array) / sizeof(int);
    Invertir(array, array + size-1);
    Imprimir(array, array + size);
    return 0;
}