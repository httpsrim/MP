/**
 * @File Mano.cpp
 */

#include "Mano.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**
* @brief Constructor de la clase. No hay que hacer nada porque hemos inicializado los valores en el .h
*/


Mano::Mano() {}
 
   /**
  * @param orig dirección de un parámetro, en este caso "Mano"
  */  
 
   Mano(const Mano& orig) {}

~Mano() {}

/**
 * @pre Se añade una nueva carta al vector cartas[]
 * @post se crea un vector con todos los numeroos de cartas que se introduzcan
 * (hasta que llega al MAX)
 * @param nuevacarta nueva carta escogida
 */

void Carta::anaideCarta(Carta & nuevacarta){
     cartas[numCartas] = nuevacarta;
     numCartas++;
 }
 
 /**
  * @pre Introduce el valor y el palo de una carta, y su siguiente.
  * @post Si la carta introducida y la siguiente son iguales, se descarta la carta
  * @param pos es la posición de la carta, es decir, el numero de cartas que
  * lleva leidas
  */
   
 void descartaCarta(int pos){
        for(int i = pos; i < numCartas;i++){
            cartas[i] = cartas[i+1];
        }
         numCartas--;
    }
    
    /**
     * @pre Se introduce el valor y el palo de una carta
     * @post Toma el valor y el palo de una carta y la cambia por una carta nueva
     * @param nuevacarta nueva carta escogifa
     * @param pos la posicion de la carta, es decir, el numero de cartas que 
     * lleva leidas. 
     */
  
    void cambiaCarta(Carta & nuevacarta, int pos){
        cartas[pos] = nuevacarta;
    }
  
    /**
     * @retval cadcartas devuelve el valor de la carta obtenida
     * @return devuelve los valores de la cadena de cartas 
     */
    
    string to_string(){
        string cadcartas="";
        for(int i = 0; i < numCartas;i++){
            cadcartas = cadcartas + std::to_string(cartas[i].numero())+ " de "+
                    cartas[i].paloCartastring() + "\n";
        }
        return cadcartas; 
    }
    
    /**
     * @return numero de cartas obtenidas
     */
    
    int  numeroCartas(){
        return numCartas;
    }
    
    /**
     * @param i parametro que tiene que ir del valor 0 hasta el vamor máximo
     * @return devuelve el valor de la carga en la posición "i"
     */
    
    Carta & carta(int i){
        return cartas[i];
    } 
};
