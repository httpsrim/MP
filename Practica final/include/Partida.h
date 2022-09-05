#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
#include "MatrizEnteros.h"
#include "Tablero.h"
#include "ConjuntoJugadores.h"

using namespace std;

class Partida{
public:
   
    /**
     * @brief Crea un nuevo objeto partida a partir de un objeto Tablero y un 
     * objeto ConjuntoJugadores ya existente.
     * @param newtab
     * @param newjug
     */
    Partida(Tablero & newtab, ConjuntoJugadores & newjug);
    /**
     * @brief Constructor de copia de la clase Partida.
     * @param orig
     */
    Partida(const Partida & orig);
    /**
     * @brief no es necesario implementarlo.
     */
    ~Partida();
    /**
     * @brief Ejecuta las acciones relativas al turno de un jugador. Primero, 
     * imprime el estado actual del tablero por pantalla.
     */
    void turno();
    /**
     * @brief Inicializa las variables jug1, jug2 y turnoactual del objeto Partida.
     * @param newjug1
     * @param newjug2
     */
    void inicializaPartida(int newjug1, int newjug2);
   /**
    * @brief Imprime por pantalla la matriz competición y el ranking de jugadores
    * . Este método es opcional pero es útil para analizar si los resultados de
    *  las partidas se están anotando adecuadamente.
    */
    void ResultadosCompeticion();
   /**
    * @brief Esta función inicializa un nuevo campeonato entre jugadores y,
    * posteriormente, inicia una partida entre los jugadores cuyas id sean jug1 y jug2.
    * @param savefile
    * @param numjugadores
    * @param nombres
    * @param apellidos
    * @param jug1
    * @param jug2
    * @param N
    * @param Ntowin
    */
    void NuevaPartida(string savefile, int numjug,string * nombres, string * apellidos, int jg1, int jg2, int N, int Ntowin);
    /**
     * @brief Almacena los resultados de la competición en un fichero en memoria
     * @param file
     */
    void save(string file);
    /**
    * @briefRellena las variables del objeto ConjuntoJugadores de partida con los
     *  datos de un fichero de competición.
    * @param file
    */
    void load(string file);
    /**
     * @brief Llama reiteradamente al método turno hasta que uno de los jugadores
     *  finalmente gana la partida.
     */
    void realizaPartida();
    /**
     * @brief Muestra el ranking actual entre jugadores.
     */
    void muestraResultadosCompeticion();
    /**
     * @brief carga un campeonato entre jugadores ya existentes e inicializa una
     *  nueva partida entre los jugadores con id jug1 y jug2
     * @param savefile
     * @param jug1
     * @param jug2
     * @param N
     * @param Ntowin
     */
    void CargaPartida(string savefile,int jg1,int jg2,int N,int Ntowin);
    /**
     * @brief Lee todos los datos del fichero de configuración de la partida, crea 
     * variables con toda las información recuperada y, dependiendo del caso,
     * llama a Nuevapartida o a CargaPartida.
     * @param conffile
     */
    void LeeFicheroConfiguracion(string conffile);

    /**
     * @brief calcula ganador
     * @param jug
     * @return 
     */
    int ganador();
    /**
     * @brief busca en las filas para ver si hay ganador
     * @param i
     * @param j
     * @param jug
     * @return 
     */
    int filas(int i,int j,int jug);
    /**
     * @brief busca en las columnas a ver si hay ganador
     * @param i
     * @param j
     * @param jug
     * @return 
     */
    int columnas(int i, int j, int jug);
private:
    int jug1, jug2 , turnoactual , fila, columna;
    int ntowin;
    Tablero tab;
    ConjuntoJugadores jugs;
};


#endif /* PARTIDA_H */


