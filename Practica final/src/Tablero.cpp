/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: Usuario
 * 
 * Created on 8 de febrero de 2022, 7:23
 */

#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <valarray>
using namespace std;

Tablero & Tablero::operator =(const Tablero & orig){
    Ntowin = orig.Ntowin;
    tam = orig.tam;
}

Tablero::Tablero(const Tablero& orig) {}

Tablero::~Tablero() {}

Tablero::Tablero(){}

Tablero::Tablero(int newtam, int newNtowin){
    tam = newtam;
    Ntowin = newNtowin;
    t.resize(tam, tam);
}

void Tablero::resetTablero(){
   int defecto = 0;
   int m[tam][tam];
   
      for(int i = 0; i < tam ; i++)
     {
         for(int j = 0; j < tam; j++)
         {
             if(m[i][j] != defecto)
             {
                 m[i][j] = defecto;
             }
         }
     }
}

bool Tablero::introducirFicha(int col, int jug){
    bool introducido = false;
    bool meter = false;
    
   for(int i = t.numfilas()-1 ; i >= 0 && introducido == false ; i--)
    {
        if(t.getValue(i,col) == 0)
        {
            t.putValue(i,col) = jug;
            meter = true;
            introducido = true;
        }
    }  
    return meter;
}

bool Tablero:: tableroLleno(){
    bool lleno = true;
    for(int i = 0 ; i <t.numfilas() ; i++)
    {
        for(int j = 0; j < t.numcolumnas(); j++)
        {
            if(t.getValue(i,j) == 0)
            {
                lleno = false;
            }
        }
    }
    return lleno;
}

string Tablero::tablerotostring(){
    string tablero = t.matriztostring();
    return tablero;
}

void Tablero::inicializarTablero(int newtam){
    tam = newtam;
    t.resize(tam, tam);
}


   std::ostream & operator<<(std::ofstream & flujo, Tablero & tab){
        flujo << tab.tablerotostring();
    }
  
int Tablero::win(int newntowin){
    Ntowin = newntowin;
    return Ntowin;
}
int Tablero::ntowin(){
    return Ntowin;
}

int Tablero::tamanio(int newtam){
    tam = newtam;
    return tam;
}
  int Tablero::ganador(){
        int i = 0;
        int j = 0;
        int k = 0;
        int ganador = 0;
        int ganar = 0;
    for(i = 0 ;i < tam ; i++){
        for(j = tam-1; j >= 0; j--){
            
            if(t.getValue(i,j) != 0)
            {
                ganar = 0;
                ganador = t.getValue(i,j);
                for(k = 0; k < Ntowin || k < tam;k++){
                    if(t.getValue(i,k) == ganador)
                    {
                       ganar = ganar+1;
                    if(ganar == 4){
                        return ganador;
                        }
                    }
                    else if(t.getValue(k,j) == ganador){
                       ganar = ganar+1;
                    if(ganar == 4){
                        return ganador;
                        }
                    }
                }

            }
        }
    }
        return 0;
}