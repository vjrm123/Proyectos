#include <iostream>

int SumaElementos(int* inicio, int *final) {
    int suma = 0;
    while(inicio < final){
        suma += *inicio++;
    }
    return suma;
}

int main(){
    int array[] = {1,2,3,4};
    int size = sizeof(array) / sizeof(int);
    int suma = SumaElementos(array, array + size);
    std::cout<< "la suma de los elemntos: " << suma << "\n";
    return 0;
}