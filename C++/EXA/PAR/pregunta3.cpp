/*QUE REALISA EL SIGUIENTE CODIGO SUPONIENDO QUE "A" SE ENCUENTRA EN LA DIRECCIONDE MEMORIA 100 Y B EN LA 200*/

#include <iostream>
using namespace std;

int main(){
    int a = 3;
    int b = 6;
    int *p = &a;
    int *q = &b;
    (*p)++;
    (*q)++;
    *p = *q;
    (*p)++;
    (*q)++;
    p = q;
    (*p)++;
    (*q)++;
    cout << a << " " << b;

    return 0;
}
/*IMPRIME 8 10*/