#include <iostream>

typedef bool (*Comparar)(int,int);

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Ascendente(int a, int b) { return a > b; }
bool Descendente(int a, int b) { return a < b; }

void Buble_Sort(int* inicio, int* final, Comparar com){
    bool Intercambio = true;
    while(Intercambio){
        Intercambio  = false;
        for(int* i = inicio; i < final; ++i){
            if(com(*i, *(i+1))){
                Swap(i, i+1);
                Intercambio = true;
            }
        }
        final--;

        if(!Intercambio) break;

        Intercambio = false;
        for(int* i = final; i > inicio; --i){
            if(com(*(i-1), *i)){
                Swap(i, i-1);
                Intercambio = true;
            }
        }
        inicio++;
    }
}

void Print(int* inicio, int* final){
    while(inicio <= final){
        std::cout<< *inicio++ << " ";
    }
    std::cout<< std::endl;
}

int main(){
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(int);

    std::cout<<"array original: ";
    Print(arr, arr + size - 1);
    
    std::cout<<"array ordenado de forma ascendente: ";
    Buble_Sort(arr, arr + size-1, Ascendente);
    Print(arr, arr + size -1);

    std::cout<<"array odenado de forma descendente: ";
    Buble_Sort(arr, arr + size -1, Descendente);
    Print(arr, arr + size -1);
    return 0;
}