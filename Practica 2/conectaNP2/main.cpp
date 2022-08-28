/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 18 de febrero de 2022, 7:46
 */

#include <cstdlib>
#include "Tablero.h"
#include "MatrizEnteros.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Pruebas para la clase MatrizEnteros

    MatrizEnteros a(3,4,-1);
    cout << a.matriztostring();
    cout << endl;

    a.resize(7,7);
    cout << a.matriztostring();
    cout << endl;
    a.putValue(3,3) = 4;
     
    a.modificarValorporDefecto(8);
    
    cout << a.matriztostring();
    cout << endl;
    
    a.resize(2,2);
      cout << a.matriztostring();
    cout << endl;
  
    //Prueba para la clase Tablero
    Tablero conecta(5,4);
    cout << conecta.tablerotostring() << endl;
    conecta.introducirFicha(2,1);
    conecta.introducirFicha(3,2);
    conecta.introducirFicha(1,1);
    conecta.introducirFicha(0,2);
    conecta.introducirFicha(0,1);
    conecta.introducirFicha(0,2);
    conecta.introducirFicha(0,1);
    conecta.introducirFicha(1,2);
    conecta.introducirFicha(1,1);
    conecta.introducirFicha(4,2);
    conecta.introducirFicha(4,1);
    conecta.introducirFicha(4,2);
    conecta.introducirFicha(4,1);
    cout << conecta.tablerotostring() << endl;
    cout << conecta.turno() << endl;
    conecta.save("partida.txt");
    Tablero conectacarga(3,3);
    conectacarga.load("partida.txt");
    cout << conectacarga.tablerotostring() << endl;

    return 0;

}

