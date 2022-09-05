/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: Usuario
 *
 * Created on 8 de febrero de 2022, 7:23
 */

#ifndef TABLERO_H
#define TABLERO_H
#include "MatrizEnteros.h"
#include <string>

using namespace std;

class Tablero {
    /**
     * @class
     * - Esta clase utiliza un objeto de MatrizEnteros para 
     * implementar un tablero de conectaN.
     * - El valor por defecto es 0 y la matriz utilizada es cuadrada. Su tamaño viene determinado por tam. 
     * - Si en una casilla del tablero hay una ficha, está tendrá el id del jugador. 
     * - Si en una casilla del tablero no hay una ficha, entonces ésta tendrá valor 0
     *   que será el valor por defecto. 
     * - En el futuro implementaremos un conjunto de jugadores y cada uno tendrá su id. 
     */
public:
    /**
     * @brief constructor
     */
    Tablero();
    /**
     * @brief  Operador de asignación sobre objetos Tablero.
     */
    Tablero & operator= (const Tablero & tab);
    /**
     * @brief : Imprime el tablero.
     */
    friend ostream & operator<<(ofstream & flujo, const Tablero & tab);
     /**
     * @brief constructor de la clase. El valor por defecto de la matriz es 0.  
     * @param newtam tamaño de la matriz (la matriz es cuadrada)
     * @param newNtowin cantidad de fichas en línea para ganar
     */
    Tablero(int newtam,int newNtowin);
    /**
     * @brief dejar vacío. 
     */
    Tablero(const Tablero& orig);
    /**
     * @brief quita todas las fichas del tablero. Se considera que el tablero
     * no tiene fichas si todas las casillas tienen el valor por defecto.  
     */
    void resetTablero();
    
    /**
     * @brief Cada ficha está identificada con el id del jugador. El jugador 
     * introduce la ficha en la columna y ésta baja hasta la posición
     * más baja del tablero en esa columna que no contenga ya una ficha. 
     * @param col Columna en la que se introduce la ficha. 
     * @param jug id del jugador que la introduce.
     * @return true si la inserción ha sido posible (la columna no está llena 
     * de fichas) o false en otro caso
     */
   bool introducirFicha(int col, int jug);
    /**
     * @return Devuelve true si el tablero está lleno de fichas
     * y no se puede introducir ni una más. 
     */
    bool tableroLleno();
    /**
     * dejar vacío
     */
    virtual ~Tablero();
    /**
     * @brief Imprime la matriz asociada al tablero.
     * @return un string con la matriz con la misma estructura
     * que la de la clase MatrizEnteros. 
     */
    string tablerotostring();
    /**
     * @brief Almacena la información del tablero con el formato descrito en el
     * guión de prácticas
     * @param file nombre del fichero. El fichero se guarda siempre en la carpeta
     * ./data (Importante: hay que crearlo a mano dentro de la carpeta de proyecto). 
     */
    void save(string file);
    /**
     * Carga los datos del Tablero de conecta N en la clase. 
     * @param file nombre del fichero dentro del directorio ./data/ de la carpeta
     * del proyecto. 
     */
    void load(string file);

    /**
     * @brief analiza el tablero y devuelve 0 si ningún jugador ha ganado o el 
     * id del jugador ganador en caso de que haya un vencedor.
     * @return ganador de la partida 
     */
    int ganador(int turnoactual);
/**
 * @brief fichas para ganar
 * @param ntowin
 * @return 
 */
    int win(int ntowin);
        /**
     * @brief Nº de fichas en linea para ganar
     * @return Ntowin
     */
    int ntowin();
    /**
     * @brief el tamaño de la matriz
     * @return tam
     */
    int tamanio(int newtam);
    int ganador();
private:
     /**
     * @brief Modifica el tamaño de filas y columnas del tablero. 
     * @param newtam nuevo tamaño de filas y columnas del tablero.
     */
    void inicializarTablero(int newtam);
    
    MatrizEnteros t;
    int tam;
    int Ntowin;
    int jug1,jug2;
  
};

#endif /* TABLERO_H */

