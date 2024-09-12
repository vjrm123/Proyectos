#include<iostream>

template<class T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T v, Nodo<T>* N = nullptr) : (valor)v, next(N){}
};

template<class T, class O>
struct Lista_E{
    Nodo<T>* Head = nullptr;

    void ADD(T v);
    void DEL(T v);
    bool Find(T v, Nodo<T>*& pos);
    void Print();
    ~Lista_E();
};

template<class T>
class ASC{
    public:
        inline bool operator()(T a, T b) { return a > b; }
};

template<class T>
class DES{
    public:
        inline bool operator()(T a, T b) { return a < b; }
};

template<class T, class O>
void Lista_E<T, O>::Print(){
    std::cout<<"Head-> ";
    while(Head){
        std::cout<<Head->valor<<" ";
        Head = Head->next;
    }
    std::cout<<"Null\n";
}

template<class T, class O>
void Lista_E<T, O>::ADD(T valor){
    
}