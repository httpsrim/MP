/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: Usuario
 * 
 * Created on 7 de febrero de 2022, 12:01
 */

#include "MatrizEnteros.h"
#include <iostream>
using namespace std;

int MatrizEnteros::numfilas(){   
    return filas;
}

int MatrizEnteros::numcolumnas(){   
    return columnas;
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
MatrizEnteros::MatrizEnteros(int fil, int col, int def) 
{ 
    filas = fil;
    columnas = col;
    defecto = def;
   for(int i = 0; i < filas; i++) 
	{     
        for(int j = 0; j < columnas; j++)     
            {         
                m[i][j] = defecto;     
            } 
	}
}
void MatrizEnteros::inicializarMatriz()
{
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
  
MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {}

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
    
    
    if(filas > newf && columnas > newc)
    {
        filas = newf;
        columnas = newc;
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
    else
    {
        filas = newf;
        columnas = newc;
   for(int i = 0; i < newf ; i++)
   {
        for(int j = 0; j < newc ; j++)
	      {
          m[i][j] = defecto;
          cout << m[i][j] << " ";
	      }       
        cout << endl;
	}
    }

}