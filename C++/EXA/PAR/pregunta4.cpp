/*QUE IMPRIME EL SIGUIENTE CODIGO*/
#include <iostream>
using namespace std;

int main(){
    char arr[3][5] = {"hugo", "paco", "luis"};
    for(char *p = (char*)arr; p <= &arr[2][4]; p++){
        cout<<p<<" ";
    }
    return 0;
}

/*IMPRIME hugo ugo go o  paco aco co o  luis uis is s */