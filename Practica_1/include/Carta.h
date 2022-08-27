/**
 * @File Carta.h
 */


#ifndef CARTA_H
#define CARTA_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * @param copas Nombre de un tipo de carta.
 * @param bastos Nombre de un tipo de carta.
 * @param oros Nombre de un tipo de carta.
 * @param espadas Nombre de un tipo de carta.
 */

enum tipopalo{copas, bastos, oros, espadas};

/**
 *@class Carta
 *@brief crea nueva carta, numero y palo de ésta.
 */

class Carta{
private:
    tipopalo palo;
    int num;
public:
    Carta(tipopalo nuevopalo, int nuevonum);
    string to_string();
    void modificaCarta(tipopalo nuevopalo, int nuevonum);
    int numero();
    string paloCartastring();
    tipopalo paloCarta();
};

#endif /* CARTA_H */

