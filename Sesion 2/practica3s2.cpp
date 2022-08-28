#include <iostream>
using namespace std;
/*
programa que pasa de mayuscula a minuscula
Entrada: mayuscula
Salida: minuscula
*/
char a,b; //65-90 mayusculas   97-122 minusculas
int main()
{
   cout<<"introduzca una letra";
   cin>>a;
   b = a+32;
   cout<<"el caracter "<<a<<" en minuscula es "<<b;
   return 0;
}
