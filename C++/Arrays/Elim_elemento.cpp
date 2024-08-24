#include <iostream>

int *eliminarElemento(int *inicio, int *final, int valor) {
    int *destino = inicio;
    while(inicio < final) {
        if(*inicio != valor) {
            *destino = *inicio;
            destino++;
        }
        inicio++;
    }
    return destino;
}
void Imprimir(int *inicio, int *final) {
    while(inicio < final) {
        std::cout<< *inicio++ << " ";
    }
}

int main(){
    int array[] = {1,1,2,2,3,1,1,1,1,1,1,1,1,1};
    int size = sizeof(array) / sizeof(int);
    int valor = 1;
    int *nuevoarray = eliminarElemento(array, array + size, valor);
    int nuevosize = nuevoarray - array;
    Imprimir(array, array + nuevosize);
    return 0;
}