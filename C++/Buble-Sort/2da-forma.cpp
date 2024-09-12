#include<iostream>

template<class T>
void Swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
class Descendente {
public:
	inline bool operator()(T a, T b) { return a < b;  }
};

template<class T>
class Ascendente {
public:
	inline bool operator()(T a, T b) { return a > b;  }
};


template<class T>
void Print(T* inicio, T* final) {
	while (inicio <= final) {
		std::cout << *inicio++ << " ";
	}
	std::cout << "\n";
}

template<class T, class O>
struct Bubble {
public:
	void operator()(T* inicio, T* final) {
		bool Intercambio = true;
		while (Intercambio) {
			Intercambio = false;
			for (T* P = inicio; P < final; P++) {
				if (O()(*P, *(P + 1))) {
					Swap(P, P + 1);
					Intercambio = true;
				}
			}
			final--;
		}
	}
};

int main() {
	int arr[] = { 45, 12, 89, 7, 32, 18, 67, 5, 23, 76, 4, 34 };
	int sizeint = sizeof(arr) / sizeof(int);

	char caracter[] = { 'x', 'b', 'k', 'z', 'a', 'p', 'm', 'q', 't', 'w', 'o', 'l' };
	int sizechar = sizeof(caracter) / sizeof(char);

	std::cout << "array de enteros original: ";
	Print(arr, arr + sizeint - 1);

	std::cout << "Elementos ordenados de forma ascendente: ";
	Bubble<int, Ascendente<int>> Asc;
	Asc(arr, arr + sizeint - 1);
	Print(arr, arr + sizeint - 1);

	std::cout << "Elementos ordenados de forma descendente: ";
	Bubble<int, Descendente<int>> Desc;
	Desc(arr, arr+ sizeint - 1);
	Print(arr, arr + sizeint - 1);

	std::cout << "\narray de caracteres original: ";
	Print(caracter, caracter + sizechar - 1);
	
	std::cout << "Elementos ordenados de forma Ascendente: ";
	Bubble<char, Ascendente<char>> Asce;
	Asce(caracter, caracter + sizechar - 1);
	Print(caracter, caracter + sizechar - 1);

	std::cout << "Elementos ordenados de forma descendente: ";
	Bubble<char, Descendente<char>> Desce;
	Desce(caracter, caracter + sizechar - 1);
	Print(caracter, caracter + sizechar - 1);

	return 0;
}