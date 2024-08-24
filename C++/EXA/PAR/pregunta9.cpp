/*escriba la funcion void merge(long *ArrImpar, long *ArrPar),
los parametros ArrImpar y ArrPar son punteros al mismo array. El Array
esta constituido por un numero par de elemntos. La primera mitad
del array esta poblado por numeros impares mayores a 0 ordenados 
ascendentemente, la segunda mitad del array esta poblado por numeros
pares mayores a 0, ordenados ascendemente.- Utilizando unicamente
aritmetica de punteros, reacomode los numeros en el array de tal forma
que sea un solo array ordenado. Vease las ilustraciones de referencia
[1,7,13...puede tener mas elementos...2,4,24] respresentacion del array despues de la ejecucion
[1,2,4,7,13,24....puede tener mas elemntos.]*/

#include <iostream>


void merge(long* ArrImpar, long* ArrPar) {
    long *ptrImpar = ArrImpar;
    long *ptrPar = ArrPar;
    long *finImpar = ArrPar;

    while(ptrImpar < finImpar && ptrPar < ArrPar + (ArrPar - ArrImpar)) {
        if(*ptrImpar < *ptrPar){
            ptrImpar++;
        } else {
            long temp = *ptrPar;
            for(long *ptr = ptrPar; ptr > ptrImpar; --ptr){
                *ptr = *(ptr-1);
            }
            *ptrImpar++ = temp;
            ptrPar++;
            finImpar++;
        }
    }
}

void Imprimir(long* inicio, long* final) {
    while (inicio < final) {
        std::cout << *inicio << " ";
        inicio++;
    }
    std::cout << std::endl;
}

int main() {
    long arr[] = { 1, 3, 5, 7, 9,13,17,23,27,29, 2, 4, 6,8 , 10, 24,28,30,36,38}; 

    long* ArrImpar = arr;
    long* ArrPar = arr + 10;

    merge(ArrImpar, ArrPar);

    Imprimir(arr, arr + 20);

    return 0;
}