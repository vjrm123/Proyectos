#include <iostream>


using namespace std;


int suma(int a, int b)
{ 
  return a+b;
}


void operar(int *p, int(*pr)(int,int))
{
    int temp;
    temp = pr(*p, *(p+1));
    *p = *(p+1);
    *(p+1) = temp;
}


int main() {


  int a[2] = {0,1};


  for(int i = 1;i<10;i++)
  {
    cout<<*a<<" ";
    operar(a,suma);
  }


}