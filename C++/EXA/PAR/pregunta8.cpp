/*La f uncion void dividir(int *ini, int *fin, bool(*pf)(int)) separa el array de numeros ordenados segun el criterio que se le envie. Al finalizar la ejecucuon de la funcion, el array quedara ordenado
poniendo primero los numeros que no cumplen con el criterio y luego los que cumplen con el
criterio. Escriba en el espacio en blanco su respuesta. Se presenta una muestra de la ejecucion para que sirva de guia*/

#include <iostream>
using namespace std;

bool par(int val) {
    return val % 2 == 0;
}

bool impar(int val) {
    return val % 2 != 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*puedes probarlo en el main*/
void echo_en_clase(int *ini, int *fin, bool (*cumple)(int)) {
    while(ini < fin){
        int *ptr = ini;
        if(cumple(*ptr)){
            ini++;
        } else {
            swap(ptr, fin -1);
            fin--;
        }
    }
}


void dividir(int* ini, int* fin, bool (*pf)(int)) {
    int *finp = fin;
    for(int *p = ini; p <= finp; ++p) {
        if(pf(*p)) {
            for(int *q = p; q < fin; ++q){
                swap(*q, *(q+1));
            }
            p--;
            finp--;
        }
    }
}


int main() {
    int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int B[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << "ordenado sin separar\n";
    for (int* p = A; p < A + 10; p++) {
        cout << *p << " ";
    }
    cout << "\n";
    dividir(A, A + 9, par);

    cout << "Ordenado separado impar_par\n";
    for (int* p = A; p < A + 10; p++) {
        cout << *p << " ";
    }
    cout << "\n";
    dividir(B, B + 9, impar);
    cout << "Ordenado Separado Par-impar\n";
    for (int* p = B; p < B + 10; p++) {
        cout << *p << " ";
    }
    return 0;
}