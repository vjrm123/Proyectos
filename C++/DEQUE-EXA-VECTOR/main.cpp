#include <iostream>
using namespace std;
template <class T>
class cdeque{
private:
	int tam_map = 7;
	int tam_vec = 5;
	T** map =NULL;
	T**ini_map = NULL;
	T**fin_map = NULL;
	T*ini_vec = NULL;
	T*fin_vec = NULL;
public:
	void push_back(T v);
	void push_front(T v);
	T& operator[](int id);
	void pop_front();
	void pop_back();
	void incremento();
	void print();
	cdeque(){
		map = new T*[tam_map];
		ini_map = map +(tam_map-1)/2;
		fin_map = ini_map;
	}
	
};

template <class T>
void cdeque<T> ::incremento(){
	int n_tam = tam_map *2 -1;
	int ind = (n_tam - tam_map) / 2;
	T**n_map = new T*[n_tam];
	for(int i = 0; i < tam_map; i++){
		n_map[i+ind] = map[i];
	}
	int des_ini= ini_map - map;
	int des_fin = fin_map - map;
	
	ini_map = n_map + des_ini + ind;
	fin_map = n_map + des_fin + ind;
	
	delete[] map;
	map = n_map;
	tam_map = n_tam;
}

template <class T>
void cdeque<T>::push_back(T v){
	if (!fin_vec){
		*fin_map = new T[tam_vec];
		ini_vec = *fin_map + (tam_vec-1)/2;
		fin_vec = ini_vec;
		*ini_vec = v;
	}
	
	else if (fin_vec == *fin_map + (tam_vec -1)){
		if(fin_map == map +(tam_map-1)){
			incremento();
		}
		fin_map++;
		*fin_map = new T[tam_vec];
		fin_vec = *fin_map;
		*fin_vec = v;
	}
	else{
		fin_vec++;
		*fin_vec= v;
	}
}

template <class T>
void cdeque<T>::push_front(T v){
	if (!ini_vec){
		*ini_map = new T[tam_vec];
		ini_vec = *ini_map + (tam_vec-1)/2;
		fin_vec = ini_vec;
		*ini_vec = v;
	}
	else if(ini_vec== *ini_map){
		if (ini_map == map){
			incremento();
		}
		ini_map --;
		*ini_map = new T[tam_vec];
		ini_vec = *ini_map + (tam_vec-1);
		*ini_vec = v;
	}
	else{
		ini_vec--;
		*ini_vec = v;
	}
}
template <class T>
void cdeque<T>::pop_back(){
	if (!fin_vec){
		cout << "deque vacio"<< endl;
		return;
	}
	else if(ini_vec == fin_vec){
		ini_vec = NULL;
		fin_vec =NULL;
		delete []*fin_map;
	}
	else if(fin_vec == *fin_map){
		delete[]*fin_map;
		fin_map--;
		fin_vec = *fin_map + (tam_vec -1);
	}
	else{
		fin_vec--;
	}
}

template <class T>
void cdeque<T>::pop_front(){
	if(!ini_vec){
		cout<< "deque vacio"<<endl;
		return;
	}
	else if(ini_vec ==fin_vec){
		ini_vec = NULL;
		fin_vec =NULL;
		delete []*ini_map;
	}
	else if(ini_vec == *ini_map + (tam_map-1)){
		delete []*ini_map;
		ini_map++;
		ini_vec = *ini_map;
	}
	else{
		ini_vec++;
	}
}
template<class T>
T& cdeque<T>::operator[](int id){
	if (!ini_vec){
		return *ini_vec;
	}
	int aux = id + (ini_vec - *ini_map);
	return *(*(ini_map + (aux / tam_map))+ aux % tam_vec);
}

template <class T>
void cdeque<T>::print() {
	// Verifica si el deque est� vac�o
	if (!ini_vec) {
		cout << "Deque vac�o" << endl;
		return;
	}
	
	T** current_map = ini_map; // Comienza desde el mapa inicial
	T* current_vec = ini_vec;  // Comienza desde el vector inicial
	
	while (true) {
		cout << *current_vec << " "; // Imprime el valor actual
		
		// Si el vector actual es el mismo que el final, hemos terminado
		if (current_map == fin_map && current_vec == fin_vec) {
			break;
		}
		
		// Avanza al siguiente elemento en el vector
		if (current_vec == (*current_map + tam_vec - 1)) {
			// Si llegamos al final del vector actual, pasa al siguiente vector en el mapa
			current_map++;
			current_vec = *current_map;
		} else {
			// Avanza al siguiente elemento en el vector actual
			current_vec++;
		}
	}
	cout << endl;
}
int main(int argc, char *argv[]) {
	cdeque<int> g;
	g.push_back(12);
	g.push_back(1);
	g.push_back(11);
	g.push_back(23);
	g.print();
	g.push_front(13);
	g.push_front(25);
	g.push_front(45);
	g.print();
	cout<< g[5];
	
	return 0;
}

