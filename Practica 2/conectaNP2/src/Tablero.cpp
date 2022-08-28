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
#include <string>
using namespace std;


Tablero::Tablero(const Tablero& orig) {}

Tablero::~Tablero() {}

Tablero::Tablero(int newtam, int newNtowin){
    tam = newtam;
    Ntowin = newNtowin;
    t.resize(tam, tam);
}

string Tablero::Jugador(){
    string jugador;
    jugador = "1,2";
    return jugador;
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

int Tablero::turno(){
    int valor1 = 0;
    int valor2 = 0;
    int jugador_1 = valor1;
    int jugador_2 = valor2;
    
    for(int i = 0 ; i < t.numfilas() ;  i ++)
    {
        for(int j = 0 ; j <t.numcolumnas() ; j++)
        {
                if (t.getValue(i,j) != 0)
                {
                    valor1 = t.getValue(i,j);
                }
                
                if(t.getValue(i,j) != 0 && valor1 != 0)
                {
                    valor2 = t.getValue(i,j);
                }
        }
    }
    
    
    for(int i = 0 ; i < t.numfilas() ;  i ++)
    {
        for(int j = 0 ; j < t.numcolumnas() ; j++)
        {
                if (t.getValue(i,j) == 1){
                jugador_1++;
                }
                
                if (t.getValue(i,j) == 2){
                jugador_2++;
                }
        }
    }
    
    if(jugador_1 > jugador_2)
    {
        return valor2;
    }
    
    else
    {
        return valor1;
    }
    
    
}

bool Tablero::introducirFicha(int col, int jug){
    bool introducido = false;
    bool meter = false;
    
   for(int i = t.numfilas() ; i > 0 && introducido == false ; i--)
    {
        if(t.getValue(i,col) == 0)
        {
            t.putValue(i,col) = jug;
            meter = true;
            introducido = true;
        }
    }  
}

bool Tablero:: tableroLleno(){
    bool lleno = true;
    for(int i = 0 ; i <=t.numfilas() ; i++)
    {
        for(int j = 0; j <= t.numcolumnas(); j++)
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
    
    //return t.matriztostring();
    string tablero="";
     for(int i = 0 ; i <t.numfilas() ; i++)
    {
        for(int j = 0; j < t.numcolumnas(); j++)
        {
            tablero += to_string(t.getValue(i,j));
        }
        
        tablero+= "\n";
    }
   // cout << tablero;
    
    return tablero;
}

void Tablero::inicializarTablero(int newtam){
    tam = newtam;
    t.resize(tam, tam);
}



void Tablero::save(string fichero){
    ofstream tablero;
    
    string titulo = "#Partida ConectaN: ";
    string jugadores = "#IDs jugadores: ";
    string datos = "#Tablero: ";
    string turno = "#Turno del jugador: ";
    string tamanio = "#Tamanio: ";
    string n = "#N: ";
    
    tablero.open(fichero);
  if(tablero.is_open())
  {
        tablero << titulo << '\n';
        tablero << jugadores << Jugador() << '\n' ;
        tablero << datos << '\n';
        tablero << turno << Tablero::turno() << '\n';
        tablero << tamanio << tam << '\n';
        tablero << n << Ntowin << '\n';
        tablero << Tablero::tablerotostring();
        tablero.close();
  }
}

void Tablero::load(string fichero){
    ifstream Tablero;
    
    string *archivo;
    int numlineas = 0;
    int TAM = 50;
    archivo = new string [TAM];
    
    Tablero.open("fichero");
    if(Tablero.is_open())
        while(getline(Tablero,archivo[numlineas]) && numlineas < TAM)
        {
            numlineas++;
        }
    Tablero.close();
    for(int i = 0 ; i < numlineas; i++)
    {
        cout << fichero[i] << endl;
    }
}