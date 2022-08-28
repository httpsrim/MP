#include <iostream>
using namespace std;
/*
programa que intercambia el valor de dos variables
Entrada:caja1,caja2 y c
Salidas: cja1 y caja2
*/
double cajaderecha,cajaizquierda,c;
int main()
{
      cout<<"indique el valor de la caja derecha";
      cin>>cajaderecha;
      cout<<"indique el valor de la caja izquierda";
      cin>>cajaizquierda;
      c = cajaizquierda;
      cajaizquierda = cajaderecha;
      cajaderecha = c;
      cout<<"el valor de la caja izquierda es: "<<cajaizquierda<<" y el valor de la caja derecha es: "<<cajaderecha;
      return 0;
}
