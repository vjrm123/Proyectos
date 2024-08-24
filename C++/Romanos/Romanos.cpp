#include <iostream>
#include <string>

std::string NumeroRomano(int Numero) {
    std::string NumeroRomano;
    int Valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string Simbolos[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for(int i=0; i < 13; i++) {
        while(Numero >= Valores[i]) {
            NumeroRomano += Simbolos[i];
            Numero -= Valores[i];
        }
    }
    return NumeroRomano;
}

void mostrarMenu() {
    std::cout << "********************************************\n";
    std::cout << " **              BIENVENIDO             **\n";
    std::cout << "********************************************\n";
    std::cout << "Seleccione una opcion...\n";
    std::cout << "1. Convertir un numero entero a romano\n";
    std::cout << "2. Salir\n";
    std::cout << "********************************************\n";
}

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        std::cin >> opcion;
        
        switch (opcion) {
            case 1: {
                int numero;
                std::cout << "Ingrese un numero entero: ";
                std::cin >> numero;
                
                std::string numeroRomano = NumeroRomano(numero);
                std::cout<< "*************************************************\n";
                std::cout << "El numero " << numero << " en numeros romanos es: " << numeroRomano << std::endl;
                std::cout<< "*************************************************\n";
                
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 2: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion invalida " << std::endl;
                break;
            }
        }
        
        std::cout << std::endl;
    } while (opcion != 2);
    
    return 0;
}