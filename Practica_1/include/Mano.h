/**
 * @File Mano.h
 */

#ifndef MANO_H
#define MANO_H

/**
 * @class Mano
 * @brief crea un nuevo conjunto de cartas, la cual es la "mano" del jugador
 * @param cartas[] vector que almacena los valores de las cartas
 * @param numCartas número de cartas de una mano.
 * @param MAX es el numero máximo de cartas que se puede tener
 */


class Mano{
    private:
    static const int MAX = 10;
    Carta cartas[MAX];
    int numCartas=0;
    
public:
    void anaideCarta(Carta & nuevacarta);
    void descartaCarta(int pos);
    void cambiaCarta(Carta & nuevacarta, int pos);
    string to_string();
    int numeroCartas();
    Carta & carta(int i);
};

#endif /* MANO_H */

