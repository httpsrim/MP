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
#include "Tablero.h"
#include "Jugador.h"
#include "ConjuntoJugadores.h"
#include <cstdlib>
#include "Partida.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tablero tab(4,3);
    ConjuntoJugadores jugs;
    Partida partida(tab,jugs);
    partida.LeeFicheroConfiguracion("./data/conffile.txt");
    return 0;
}

