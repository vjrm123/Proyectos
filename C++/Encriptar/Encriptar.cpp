#include <fstream>
#include <string>
#include "../Calculadora/Cal_modular.cpp"

void encriptarArchivo(std::string& nombreArchivo, int clave) {
    std::ifstream archivoEntrada(nombreArchivo);
    std::string nombreArchivoEncriptado = "encriptado_" + nombreArchivo;
    std::ofstream archivoEncriptado(nombreArchivoEncriptado);

    archivoEncriptado << clave << '\n';

    char caracter;
    while (archivoEntrada.get(caracter)) {
        caracter = (caracter * clave) % 256;
        archivoEncriptado << caracter;
    }
    archivoEntrada.close();
    archivoEncriptado.close();
}

void desencriptarArchivo(std::string& nombreArchivoEncriptado) {
    Calculadora calculadora;
    std::ifstream archivoEncriptado(nombreArchivoEncriptado);
    int claveEncriptacion;
    archivoEncriptado >> claveEncriptacion;  

    int claveDesencriptacion;
    std::cout << "Ingrese la clave de desencriptacion: ";
    std::cin >> claveDesencriptacion;

    if (claveDesencriptacion != calculadora.Inverso(claveEncriptacion, 256)) {
        std::cout << "ERROR NO ES LA CLAVE CON LO CUAL SE LLEGO HA ENCRIPTAR" << std::endl;
        return;
    }

    std::string nombreArchivoDesencriptado = "desencriptado_" + nombreArchivoEncriptado;
    std::ofstream archivoDesencriptado(nombreArchivoDesencriptado);

    char caracter;
    archivoEncriptado.get(caracter); 
    while (archivoEncriptado.get(caracter)) {
        caracter = (caracter * claveDesencriptacion) % 256;
        archivoDesencriptado << caracter;
    }
    archivoEncriptado.close();
    archivoDesencriptado.close();
    std::cout << "Archivo desencriptado exitosamente." << std::endl;
}

void ImprimirMenu() {
    std::cout << "+**********************************+\n";
    std::cout << "|        BIENVENIDO AL MENU        |\n";
    std::cout << "+**********************************+\n";
    std::cout << "|     1. Encriptar archivo         |\n";
    std::cout << "|     2. Desencriptar archivo      |\n";
    std::cout << "|     3. Calculadora modular       |\n";
    std::cout << "|     4. Salir                     |\n";
    std::cout << "+**********************************+\n";
    std::cout << "Ingrese una opcion: ";
}


int main() {
    Calculadora cal;
    std::string nombreArchivo = "hola.txt";
    int opcion, Resultado;
    
    do {
        ImprimirMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int clave;
                std::cout<< "Ingresa la clave: "; std::cin>>clave;
                Resultado = cal.Inverso(clave, 256);

                if(Resultado == -1) {
                    std::cout<< "ERROR!!! La clave no tiene inverso en el modulo " << 256 << "\n";
                } else {
                    std::cout<< "Su contraseña es: " << Resultado << "\n";
                    encriptarArchivo(nombreArchivo, clave);
                    std::cout << "Archivo encriptado exitosamente" << std::endl;
                }

                std::cout << "Presione Enter para continuar...\n";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 2: {
                std::string nombreArchivoEncriptado = "encriptado_" + nombreArchivo;
                desencriptarArchivo(nombreArchivoEncriptado);
                std::cout << "Presione Enter para continuar...\n";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 3:
                cal.Menu();
                std::cout << "Presione Enter para continuar...\n";
                std::cin.ignore();
                std::cin.get();
                break;
            case 4:
                std::cout<< "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida..." << std::endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

