#include "MatrizEnteros.h"
#include <iostream>
using namespace std;

MatrizEnteros & MatrizEnteros::operator=(const MatrizEnteros & orig){
    filas = orig.filas;
    columnas = orig.columnas;
            m = new int*[orig.filas];
            for (int i = 0; i < orig.filas; i++) {  
            m[orig.filas] = new int[orig.columnas];
            }
}

int MatrizEnteros::numfilas(){   
    return filas;
}

int MatrizEnteros::numcolumnas(){   
    return columnas;
}

 void MatrizEnteros::aniadeColumna(){
     columnas++;
 }
 void MatrizEnteros::aniadeFila(){
     filas++;
 }
 
 void MatrizEnteros::reservarMemoria(int f, int c){
    filas = f;
    columnas = c;
    m = new int*[f];
    for (int i = 0; i < f; i++) {
        m[i] = new int[c];
    } 
 }
 
 void MatrizEnteros::liberarMemoria(){
      for (int i = 0; i < filas; i++) {
            delete [] m[i];
        }
        delete [] m;
 }
 
void MatrizEnteros::modificarValorporDefecto(int nuevodef)
{  
   for(int i = 0; i < filas; i++) 
	{     
        for(int j = 0; j < columnas; j++)     
            {  
            if(m[i][j] == defecto)
                m[i][j] = nuevodef;
            } 
	}
   defecto = nuevodef;
}

int & MatrizEnteros::putValue(int fil, int col)
{   
    
    return m[fil][col];
}

int MatrizEnteros::getValue(int fil, int col)
{
   return m[fil][col];
}
MatrizEnteros::MatrizEnteros(int fil, int col) 
{ 
    filas = fil;
    columnas = col;
    defecto = 0;
    reservarMemoria(filas,columnas);
    for(int i = 0; i < filas ; i++){
        for(int j = 0; j < columnas ; j++){
            m[i][j] = defecto;
        }
    }
}
void MatrizEnteros::inicializarMatriz()
{ 
    reservarMemoria(filas,columnas);
	for(int i = 0 ; i < filas ; i++)    
            {
	    for(int j = 0; j < columnas; j++)          
		{    
                m[i][j] = defecto;         
                cout << m[i][j] << " ";         
                }       
        cout << endl;   
        }
        
  }
  
MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {
    columnas = orig.columnas;
    filas = orig.filas;
    defecto = orig.defecto;
    m = orig.m;
}

MatrizEnteros::~MatrizEnteros() {}

string MatrizEnteros::matriztostring()
{
    string Matriz;
    for(int i = 0 ; i < filas; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            Matriz = Matriz + std::to_string(m[i][j]);
        }
        Matriz = Matriz + '\n';
    }
    return Matriz;
}

int MatrizEnteros::valordefecto()
{
   for(int i = 0; i < filas ; i++)
   {
        for(int j = 0; j < columnas ; j++)
	      {
          m[i][j] = defecto;
          cout << m[i][j] << " ";
	      }       
        cout << endl;
	}
}
void MatrizEnteros::resize(int newf, int newc)
{
     MatrizEnteros copy;
    copy.filas = newf;
    copy.columnas = newc;
      for(int i = 0; i < newf ; i++)
   {
        for(int j = 0; j < newc ; j++)
	      {
            if(newc <= columnas && newf <= filas)
            {
                copy.m[i][j] = m[i][j];
            }
            
            if(newc > columnas && newf > filas)
            {
                copy.m[i][j] = defecto;
            }
	      }       
	} 
   liberarMemoria();
   reservarMemoria(filas,columnas);

    for(int i = 0; i < newf ; i++)
   {
        for(int j = 0; j < newc ; j++)
	      {
          m[i][j] = copy.m[i][j];
          cout << m[i][j] << " ";
	      }       
        cout << endl;
	} 
}
    
