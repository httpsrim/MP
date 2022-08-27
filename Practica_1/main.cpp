/**
 * @file main.cpp
 * @Brief Es el archivo principal del proyecto.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include "Mano.h"
#include "Carta.h"

using namespace std;

/**
 * @pre se pasan los valores de las manos 1 y 2 para ver cuales cartas son iguales
 * @param mano1
 * @param mano2
 * @post Las cartas que son iguales hacen que el contador de numrepetidas aumente
 * @return el numero de cartas repetidas
 */

int cartasComunes(Mano & mano1, Mano & mano2){
        int numrepetidas=0;
        for(int i = 0; i < numeroCartas();i++){
            for(int j = 0; j < mano2.numeroCartas();j++){             
                if(mano1.carta(i).numero() == mano2.carta(j).numero() &&
                        mano1.carta(i).paloCarta() == mano2.carta(j).paloCarta()){
                    numrepetidas++;
                }
            }
        }
        return numrepetidas;
    }

int main(int argc, char** argv) {
 //Prueba de la clase Carta

    tipopalo palo = bastos;
    Carta una(palo,3);
    cout << una.to_string() << endl;
    palo = oros;
    una.modificaCarta(palo,1);
    cout << una.to_string() << endl;
    cout << una.numero() << " de " << una.paloCartastring() << endl;
    cout << endl << endl;
    
    //Prueba de la clase Mano
     
    Mano jugador1;
    Mano jugador2;
    
    Carta orossota(oros,8);
    Carta bastos3(bastos,3);
    Carta espadas4(espadas,4);
    Carta oros2(oros,2);
    
    jugador1.anaideCarta(orossota);
    jugador1.anaideCarta(espadas4);
    jugador1.anaideCarta(oros2);
    
    jugador2.anaideCarta(bastos3);
    jugador2.anaideCarta(oros2);
    jugador2.anaideCarta(espadas4);

    cout << "Baraja jugador 1: " << endl << jugador1.to_string() << endl;
    cout << "Baraja jugador 2: " << endl << jugador2.to_string() << endl;
    cout << "Cartas en común: " << cartasComunes(jugador1,jugador2) << endl << endl << endl;
    
    jugador2.descartaCarta(0);
    cout << "Baraja jugador 2: " << endl << jugador2.to_string() << endl;
    
    jugador1.cambiaCarta(bastos3,1);
    cout << "Baraja jugador 1: " << endl << jugador1.to_string() << endl;
    cout << "Cartas en común: " << cartasComunes(jugador1,jugador2) << endl;
    return 0;   
}



