#include <iostream>
using namespace std;

struct nodo{
    int valor;
    nodo* next;

    nodo(int valor, nodo* next = nullptr) : valor(valor), next(next){}
}