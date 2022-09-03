/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 24 de febrero de 2022, 7:37
 */

#include <cstdlib>
#include "Jugador.h"
#include "ConjuntoJugadores.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Pruebas jugador
    Jugador jug1(1,"Juan","López");
    Jugador jug2(2,"Pedro","Martínez");
    Jugador jug3(3,"Lucas","Fernández");
    Jugador jug4(7,"Mercedes", "López");
    Jugador jug5(6,"Roberto", "Jiménez");
    Jugador jug6(5,"Mercedes", "López");
    Jugador jug7(4,"Daniel", "López");
    jug1.partidaGanada();
    jug1.partidaGanada();
    jug1.partidaJugada();
    jug1.partidaJugada();
    jug2.partidaGanada();
    jug2.partidaJugada();
    jug3.partidaJugada();
    jug3.partidaJugada();
    if(jug1 > jug2) cout << "Ok1" << endl;
    if(jug2 == jug3) cout << "Ok2" << endl;
    if(jug1 <= jug2) cout << "not ok 1" << endl;
    if(jug1 >=jug2) cout << "ok 3" << endl;
    if(jug3 >= jug1) cout << "not ok 2" << endl;
    
    //Pruebas conjuntoJugadores
    ConjuntoJugadores conj;
    ConjuntoJugadores conj2;
    ConjuntoJugadores conj4;
    conj+=jug1;
    conj+=jug2;
    conj+=jug3;
    conj2+=jug4;
    conj4+=jug5;
    conj4+=jug6;
    conj2+=jug7; 
    conj.eliminaJugador(2);
   Jugador pruebaasignacion = conj[1];
    cout << conj[0];
    cout << endl;
    

    
  ConjuntoJugadores conj3 = conj+conj2+conj4;
  cout << conj3 ;        
   cout << conj3.buscaJugador(2) << endl;
    cout << conj3.buscaJugador("Pepe") << endl;
  
    conj3.optimizar();

    cout << conj3;
    conj3.eliminaJugador(2);
   cout << conj3;
   cout << conj3.rankingJugadores() << endl; 
    return 0;
}

