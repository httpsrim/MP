/**
 * @File Carta.cpp
 */

#include "Carta.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
@brief Constructor de la clase. No hay que hacer nada porque hemos inicializado los valores en el .h
*/

Carta::Carta(){}   
}

/**
 * @param nuevopalo elige entre las variables enumeradas una de ellas para que 
 * sea el tipo de carta
 * @param nuevonum genera un nuevo numero (del 1 al 9) para la carta
 * @post generación de un nuevo numero de carta y de un palo (uno entre los 
 * existentes)
 */

Crta::Carta(tipopalo nuevopalo, int nuevonum) {
    num = nuevonum;
    palo = nuevopalo;
}

/**
 * @param orig dirección de un parámetro, en este caso "Carta"
 */
Carta::Carta(const Carta& orig) {

}

Carta::string to_string(){
    string palocarta;
    palocarta = std::to_string(num) + " de " +  paloCartastring();
    return palocarta;
}

/**
 * @brief Cambia una carta,es igual que Carta(tipopalo nuevo palo, int nuevonum)
 * @pre el dato palo tiene que ser uno de los palos existentes
 * @post Se escogerse un nuevo numero y palo para la carta
 * @param nuevopalo genera un þalo diferente (es uno de los existentes en el num)
 * @param nuevonum genera un nuevo numero para la carta (1-9)
 */

void Carta::modificaCarta(tipopalo nuevopalo, int nuevonum){
    palo = nuevopalo;
    num = nuevonum;
}

/**
 * @param num generadro de un numero del 1 al 9
 * @return devuelve un numero
 */

int Carta::numero(){
    return num;
}

/**
 * @pre Generador de nombres para la carta, el nombre asignado es el que tiene 
 * las variables neumeradas.
 * @post Si el palo que estaba elegido coincide con alguno de éstos,se pasa a una
 * cadena)
 * @return devuelve el palo de la carta (Bastos,Espadas,Oros o Copas)
 */

string Carta::paloCartastring(){
    string palocarta;
    if(palo == bastos)  palocarta = "bastos";
    if(palo == espadas) palocarta = "espadas";
    if(palo == oros) palocarta = "oros";
    if(palo == copas) palocarta = "copas";
    return palocarta;
}

/**
 * @return devuelve el valor (nombre) del palo
 */

tipopalo Carta::paloCarta(){
    return palo;
}
};
