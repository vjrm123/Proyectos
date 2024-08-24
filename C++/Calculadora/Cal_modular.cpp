#include "Cal_modular.h"
#include <iostream>

Calculadora::Calculadora() : PriOperando(0), SegOperando(0), Modulo(0){}
Calculadora::Calculadora(int mod, int op1, int op2) : Modulo(mod), PriOperando(op1), SegOperando(op2)
{
    if (this->PriOperando < 0 || this->SegOperando < 0) {
        ajuste();
    }
}

void Calculadora::ajuste() {
	while ( PriOperando < 0) {
		this->PriOperando += Modulo;
	}
	while (SegOperando < 0) {
		this->SegOperando += Modulo;
	}
}

int Calculadora::ajuste(int Numero) {
	while (Numero < 0) {
		Numero += Modulo;
	}
	return Numero;
}

void Calculadora::informacion(char Signo, int Resultado) {
    std::cout << "+----------------------------------+\n";
    std::cout << "|         Informacion              |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "| Operacion: (" << PriOperando << " % " << Modulo << ") " << Signo << " (" << SegOperando << " % " << Modulo << ")\n";
    std::cout << "| Resultado: " << Resultado << " % " << Modulo << "\n";
    std::cout << "+----------------------------------+\n";
}

int Calculadora::Sumar() {
	return ((PriOperando + SegOperando) % Modulo);
}

int Calculadora::Restar() {
	return ajuste((PriOperando - SegOperando) % Modulo);
}

int Calculadora::Multiplicacion() {
	return ((PriOperando * SegOperando) % Modulo);
}

int Calculadora::calcularMCD(int a, int b) {
    while (b != 0) {
        int temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}


int Calculadora::Inverso(int numero, int modulo) {
	if (calcularMCD(numero, modulo) != 1) {
		return -1; 
	}
	int moduloInicial = modulo;
	int coeficiente1 = 0, coeficiente2 = 1;
	while (numero > 1) {
		int cociente = numero / modulo;
		int temporal = modulo;
		modulo = numero % modulo;
		numero = temporal;
		temporal = coeficiente1;
		coeficiente1 = coeficiente2 - cociente * coeficiente1;
		coeficiente2 = temporal;
	}
	if (coeficiente2 < 0) {
		coeficiente2 += moduloInicial;
	}
	return coeficiente2;
}

void Calculadora::ImprimirMenu() {
    std::cout << "+**********************************+\n";
    std::cout << "|     BIENVENIDO A LA CALCULADORA   |\n";
    std::cout << "+**********************************+\n";
    std::cout << "|    1. Sumar                       |\n";
    std::cout << "|    2. Restar                      |\n";
    std::cout << "|    3. Multiplicar                 |\n";
    std::cout << "|    4. Calcular Inverso            |\n";
    std::cout << "|    5. Salir                       |\n";
    std::cout << "+**********************************+\n";
    std::cout << "Ingrese una opcion: ";
}

void Calculadora::Menu() {
        int Opcion, PriOperando, SegOperando, Modulo, Resultado;

        do {
            ImprimirMenu();
            std::cin>>Opcion;
            switch(Opcion) {
                case 1:
                    std::cout<< "Ingrese el primer operando: "; std::cin>>PriOperando;
                    std::cout<< "Ingrese el modulo: "; std::cin>>Modulo;
                    std::cout<< "Ingrese el segundo operando: "; std::cin>>SegOperando;
                    *this = Calculadora(Modulo, PriOperando, SegOperando);
                    Resultado = Sumar();
                    informacion('+', Resultado);


                    std::cout << "Presione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                case 2:
                    std::cout<< "Ingrese el primer operando: "; std::cin>>PriOperando;
                    std::cout<< "Ingrese el modulo: "; std::cin>>Modulo;
                    std::cout<< "Ingrese el segundo operando: "; std::cin>>SegOperando;  
                    *this = Calculadora(Modulo, PriOperando, SegOperando);
                    Resultado = Restar();
                    informacion('-', Resultado);

                    std::cout << "Presione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                case 3:
                    std::cout<< "Ingrese el primer operando: "; std::cin>>PriOperando;
                    std::cout<< "Ingrese el modulo: "; std::cin>>Modulo;
                    std::cout<< "Ingrese el segundo operando: "; std::cin>>SegOperando;  
                    *this = Calculadora(Modulo, PriOperando, SegOperando);
                    Resultado = Multiplicacion();
                    informacion('*', Resultado);

                    std::cout << "Presione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                case 4:
                    std::cout<< "Ingrese el numero: "; std::cin>>PriOperando;
                    std::cout<< "Ingrese el modulo: "; std::cin>>Modulo;
                    Resultado = Inverso(PriOperando, Modulo);
                    std::cout<< Resultado << "\n";

                    std::cout << "Presione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                case 5:
                    std::cout<< "Saliendo...\n";
                    break;
                default:
                    std::cout<<"Opcion invalida!!!";
                    break;
            }
        }while(Opcion != 5);
    }

