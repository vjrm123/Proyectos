/*en el siguiente programa la funcion char cipher(char ent, int key) es una funcion
funcion que cifra o desifra una letra segun la clave key que se le envie (para el ejemplo
con 21 encripta y con 61 desencripta) la funcion voi imprimir(char (*matcad)[200], int matTam)
imprime las cadenas de la matris matCad cuyo tamaño es enviado MatTam. implemente la funcion void procesa(char(*matCad)[200], int mattam, char(*oper)(char, int), int key)
que recibe las cadenas en matCad cuyo tamaño es enviado en matcad esta funcion debera encriptar cada cadena 
usando la funcion cpher y la calve correspondiente. debe tener cuidado de no encriptar el caracter nulo (\0) que sirve para indicar el final de la cadena 
. use el espacio en blanco dejado para colocar su respuesta
*/

#include <iostream>
using namespace std;

char cipher(char ent, int key) {
    return ent * key % 256;
}

void procesa(char (*matCad)[200], int matTam, char (*oper)(char, int), int key) {
    char (*Puntero)[200] = matCad;
    char (*finMatriz)[200] = matCad + matTam;

    while (Puntero != finMatriz) {
        char *caracter = *Puntero;
        char *finCadena = caracter;

        while (*finCadena != '\0') {
            *finCadena = oper(*finCadena, key);
            finCadena++;
        }

        Puntero++;
    }
}

void Imprimir(char (*matCad)[200], int matTam) {
    for (char (*p)[200] = matCad; p < matCad + matTam; p++) {
        cout << (p - matCad) + 1 << "-" << *p << "\n";
    }
}

int main() {
    char C[][200] = {"no hay caminos para la paz; la paz es el camino"};
    int k[2] = {21, 61};
    cout << "frases sin encriptar\n";
    Imprimir(C, 1);

    procesa(C, 1, cipher, *k);
    cout << endl << "frases encriptadas" << "\n";
    Imprimir(C, 1);

    procesa(C, 1, cipher, *(k + 1));
    cout << endl << "frases desencriptadas\n";
    Imprimir(C, 1);
    return 0;
}