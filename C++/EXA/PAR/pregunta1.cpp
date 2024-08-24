/*QUE RALISA EL SIGUIENTE CODIGO SUPONIENDO QUE EL ARRAY COMIENSA EN LA DIRECION DE MEMORIA 200*/

#include <iostream>
using namespace std;

int main(){
    int A [2][3] = {{1,2,3}, {4,5,6}};
    for(int *i = *A; i < *A +6; i++){
        cout << i << " ";
    }
    return 0;
}

/*IMPRIME 200 204 208 2012 2016 2020*/