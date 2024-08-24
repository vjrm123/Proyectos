#include <iostream> 

int ContadorOcurrencias(int *inicio, int *final, int valor) {
    int contador = 0;
    while(inicio < final) {
        if(*inicio++ == valor) {
            contador++;
        }
    }
    return contador;
}

int main(){
    int array[] = {1,1,1,2,2,3,2};
    int valor = 2;
    int size = sizeof(array) / sizeof(int);
    int contador = ContadorOcurrencias(array, array + size, valor);
    std::cout<< "el numero " << valor << " se repite " << contador << " veces en el array ";
    return 0;
}