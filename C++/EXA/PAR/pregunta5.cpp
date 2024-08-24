/*QUE IMPRIME EL SIGUIENTE CODIGO*/
#include <iostream>
using namespace std;
void funcion(char A[][5]){
    cout<<sizeof(A);
}
int main(){
    char arr[][5] = {"hugo", "paco", "luis"};
    cout<< sizeof(arr) << " ";
    funcion(arr);
    return 0;
}

/*IMPRIME 15 8*/