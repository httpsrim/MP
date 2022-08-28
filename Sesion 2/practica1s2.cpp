#include <iostream>
using namespace std;
/*
programa que calcula el tiempo pasado entre dos instantes
Entradas: Minutos, segundos y horas
Salidas:tiempo pasado
*/

int Hi,Mi,Si, Hf,Mf,Sf,Horas, Minutos, Segundos,seg; //Horas, minutos y segundos iniciales y finales

int main()
{
   cout<<"indique la hora inicial ";
   cin>>Hi;
   cout<<"indique los minutos iniciales ";
   cin>> Mi;
   cout<<"indique los segundos iniciales ";
   cin>>Si;
   cout<<"indique la hora final ";
   cin>>Hf;
   cout<<"indique los minutos finales ";
   cin>> Mf;
   cout<<"indique los segundos finales ";
   cin>>Sf;
   Horas = (Hf-Hi)*3600;
   Minutos = (Mf-Mi)*60;
   Segundos = (Sf-Si);
   seg = Horas+Minutos+Segundos;
   cout<<"el tiempo pasado entre esos dos instantes es de: "<<seg;
   return 0;
}
