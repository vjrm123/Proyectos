#pragma once
class Calculadora {
private:
	int Modulo, PriOperando, SegOperando;
	int calcularMCD(int numero1, int numero2);
	void ImprimirMenu();
public:
	Calculadora(int Modulo, int PriOperando, int SegOperando);
	Calculadora();
	void ajuste();
	void informacion(char Signo, int Resultado);
	void Menu();
	
	int ajuste(int);
	int Sumar();
	int Restar();
	int Multiplicacion();
	int Inverso(int PriOperando,int Modulo);
};
