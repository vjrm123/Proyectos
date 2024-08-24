#include <iostream>
#include <iomanip>
#include "Calendario.h"

Calendario::Calendario(int Mes, int Anio) : Mes((Mes > 1 && Mes <= 12) ? Mes : 1), Anio((Anio > 0) ? Anio : 1) {}

bool Calendario::EsBisiesto() {
    if( Anio % 4 == 0 && (Anio % 100 != 0 || Anio % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int Calendario::ObtenerDiasDelMes(){
    if( Mes == 2) {
        return EsBisiesto() ? 29 : 28;
    }
    else if (Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

std::string Calendario::ImprimirMes(int Numero) {
    std::string Arrays[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    return Arrays[Numero - 1];
}

int Calendario::ObtenerPrimerDiaDeSemana() {
    int ajusteM = (14 - Mes) / 12;
    int ajusteA = Anio - ajusteM;
    int mesAjustado = Mes + 12 * ajusteM - 2;
    int primerDiaSemana = (1 + ajusteA + ajusteA / 4 - ajusteA / 100 + ajusteA / 400 + (31 * mesAjustado) / 12) % 7;
    return primerDiaSemana;
}

void Calendario::ImprimirCalendario() {
    int NumDias = ObtenerDiasDelMes();
    int PrimerDiaSemana = ObtenerPrimerDiaDeSemana();
    
    std::cout << "========================================\n";
    std::cout << "  MES/AÑO ELEGIDO: " << ImprimirMes(Mes) << " / " << this->Anio << "\n";
    std::cout << "========================================\n";
    std::cout << "  D   L   M   M   J   V   S  \n";

    for (int i = 0; i < PrimerDiaSemana; i++) {
        std::cout << "    ";
    }

    for (int dia = 1; dia <= NumDias; dia++) {
        std::cout << std::setw(3) << dia << " ";
        if ((PrimerDiaSemana + dia) % 7 == 0) {
            std::cout << "\n";
        }
    }

    std::cout << "\n" << "========================================\n";
}

void ImprimirMenu(){
    std::cout<< "*************************+\n";
    std::cout<< "****   BIENVENIDO   ****\n";
    std::cout<< "*************************+\n";
    std::cout<< "Selecciona una opcion...\n";
    std::cout<< "1. Mostrar Calendario\n";
    std::cout<< "2. Salir\n";
    std::cout<< "*************************\n";
}

int main() {
    int Opcion, Mes, Anio;
    Calendario calendario;

    do {
        ImprimirMenu();
        std::cin >> Opcion;

        switch(Opcion) {
            case 1:
                std::cout << "Ingrese el mes: ";
                std::cin >> Mes;
                std::cout << "Ingrese el anio: ";
                std::cin >> Anio;
                calendario = Calendario(Mes, Anio);
                calendario.ImprimirCalendario();

                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                break;
            case 2:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while (Opcion != 2);

    return 0;
}