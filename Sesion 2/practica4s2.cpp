#include <iostream>
using namespace std;

int anio;
int edad,es_minus;
char vocal, letra;
bool comprobaranio, comprobaredad, comprobarletra,comprobarvocal;

int main()

{
cout<<"letra ";
cin>>letra;
cout<<"anio ";
cin>>anio;
cout<<"vocal en minuscula ";
cin>>vocal;

	comprobarletra = (letra>=97);
	cout<<"letra: "<<comprobarletra<<"si es 1 es minuscula, 0 mayuscula"<<endl;
	comprobaranio = (anio % 4 == 0 && anio % 100 != 0); 
	cout<<"anio: "<<comprobaranio<<"si es 1 es bisiesto, 0 no bisiesto"<<endl;
	comprobarvocal = (vocal == 'a'||'e'||'i'||'o'||'u');
	cout<<"vocal: "<<comprobarvocal<<"si es 1 es vocal, 0 no vocal"<<endl;
}
