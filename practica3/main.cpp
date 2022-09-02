/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mp
 *
 * Created on 30 de marzo de 2022, 21:53
 */

#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief Ordena las palabras de forma ascendente y las guarda en el archivo de salida.
 * @param archivo son las palbras tomadas del main
 * @param n numero de palabras a ordenar
 * @param asc  se ordenan ascendentemente.
 * @temp variable temporar para el paso de archivos
 */
void ordena(string* archivo,int n, bool asc)
{
    ofstream Fichero;
    Fichero.open("./data/salida.txt");
  if(Fichero.is_open())
{     
      int sig = 0;
      string temp;
      if(asc == true)
      {
        for(int i = 0 ;i < n;i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(archivo[i] > archivo[j])
                {
                    temp = archivo[i];
                    archivo[i] = archivo[j];
                    archivo[j] = temp;
               }
            }
        }
        for(int i = 0; i < n; i++)
        {
            Fichero << archivo[i]<< "\n";
        }
      }
      
      else if(asc == false)
      {
            for(int i = 0 ;i < n;i++)
         {
             for(int j = i+1; j < n; j++)
             {
                 if(archivo[i] < archivo[j])
                 {
                     temp = archivo[i];
                     archivo[i] = archivo[j];
                     archivo[j] = temp;
                 }
             }
         }
         for(int i = 0; i < n; i++)
         {
             Fichero << archivo[i]<< "\n";
         }
      }
  }
 
  else
    {
        cout << "No se pudo abrir el archivo de salida" << endl;
        exit(1);
    }
     Fichero.close();
}
/**
 * @param argc
 * @param argv
 * @param archivo es el fichero de entrada, en el que están las palabras a ordenar
 * @param numoalabras es el numero de palabras a leer
 * @param TAM es el tamaño maximo
 * @brief Lee un archivo, hasta el numero que se especifica en el argv, de ahí se pasa a ordenarlos ascendentemente.
 * @return 
 */
int main(int argc, char** argv) {    
    bool ascendente = true;
    ifstream Fichero;
    string * archivo;
    int numpalabras = atoi(argv[5]);
    int TAM = 50;
    archivo = new string [TAM];
    
    Fichero.open("./data/entrada.txt");
    if(Fichero.is_open())
        for(int i = 0; i < numpalabras;i++)
        {
           Fichero >> archivo[i];
          
        }else

    {
        cout << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }
    Fichero.close(); 
    if(argv[3] == "asc")
    {
        ascendente = true;
        ordena(archivo,numpalabras,ascendente);
    }
    else
    {
        ascendente = false;
        ordena(archivo,numpalabras,ascendente);
    }
    
    
    delete [] archivo;
    return 0;
}
