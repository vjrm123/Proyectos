#include <iostream>

int *BuscarElemento(int *inicio, int *final, int valor) {
    while(inicio < final){
        if(*inicio++ == valor){
            return inicio;
        }
    }
    return nullptr;
}

int main(){
    int array[] = {1,2,3,4,5};
    int valor = 3;
    int size = sizeof(array) / sizeof(int);
    int *Encontrado = BuscarElemento(array, array + size, valor);
    int  posicion = Encontrado - array;
    std::cout<< "el numero " << valor << " fue encontrado en la posicion " << posicion ;
    return 0;
}