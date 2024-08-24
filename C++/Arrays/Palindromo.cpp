#include <iostream>
#include <cstring>
bool Palindromo(char *inicio, char *final) {
    while(inicio < final) {
        if(*inicio != *final) {
            return false;
        }
        inicio++;
        final--;
    }
    return true;
}

int main(){
    char cadena[] = "oso";
    char* fin = cadena + std::strlen(cadena)-1;
    if(Palindromo(cadena, fin)) {
        std::cout<< "es palindromo\n";
    }else {
        std::cout<< "no es palindromo\n";
    }
    
    return 0;
}