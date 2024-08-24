#include <iostream>
#include <vector>

class Poligono{
    protected:
        int Lados;
    public:
        Poligono(int Lados) : Lados(Lados){}

        virtual int Area()=0;
};


class Triangulo : public Poligono{
    int Base, Altura;
    public:
        Triangulo(int Lados, int Base, int Altura): Base(Base), Altura(Altura), Poligono(Lados){}

        int Area()override{
            return (Base * Altura) /2;
            
        }
};

class Rectangulo : public Poligono{
    int Base, Altura;
    public:
    Rectangulo(int Base, int Altura): Base(Base), Altura(Altura), Poligono(Lados){}

    int Area()override { return (Base * Altura); }
};

void MostraDatos(Poligono* poli){
    std::cout<<"los datos  son: \n";
    std::cout<< poli->Area()<<"\n";
}
int main(){
    std::vector<Poligono*>poligonos;
    poligonos.push_back(new Rectangulo(2,3));
    poligonos.push_back(new Triangulo(3,3,4));
    for(auto po : poligonos){
        MostraDatos(po);
    }
    return 0;
}
