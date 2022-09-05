#include "Partida.h"
#include "Tablero.h"
#include "MatrizEnteros.h"
#include "Jugador.h"
#include "ConjuntoJugadores.h"
#include <iostream>
#include <string> 
#include <fstream>
using namespace std;
    Partida::Partida(Tablero & newtab, ConjuntoJugadores & newjug){
        jugs = newjug;
        tab = newtab;
    }

    Partida::Partida(const Partida & orig){
        jug1 = orig.jug1;
        jug2 = orig.jug2;
        turnoactual = orig.turnoactual;
        fila = orig.fila;
        columna = orig.columna;
        ntowin = orig.ntowin;
    }
  


    void Partida::turno(){
        int tam = fila;
        while(tab.ganador() == 0){
            turnoactual = jug1;
            cout << "Es el turno del jugador " << turnoactual << "Introfuzca la columna" << endl;
            do{
                cin >> columna;
            }while(columna > tam);
            tab.introducirFicha(columna, turnoactual);
            cout << tab.tablerotostring() << endl;
            tab.ganador();
            turnoactual = jug2;
            cout << "Es el turno del jugador " << turnoactual << "Introfuzca la columna" << endl;
             do{
                cin >> columna;
            }while(columna > tam);
            tab.introducirFicha(columna, turnoactual);
            cout << tab.tablerotostring() << endl;
            tab.ganador();
        }
    }
    
    void Partida::inicializaPartida(int newjug1, int newjug2){
        jug1 = newjug1;
        jug2 = newjug2;
        realizaPartida();
    }
    void Partida::realizaPartida(){ 
        tab.win(ntowin);
        tab.tamanio(fila);  
        turno();  
        if(tab.ganador() == jug1){
            jugs.apuntaPartida(jug1,jug2);
        }
        else{
        jugs.apuntaPartida(jug2,jug1);
        }
        string savefile = "./data/competicion.txt";       
        save(savefile);
    }
    void Partida::NuevaPartida(string savefile, int numjugadores,string * nombres, string * apellidos, int jg1, int jg2, int N, int Ntowin){
        ConjuntoJugadores jug(numjugadores,nombres,apellidos);
        jugs = jug;
        fila = N;
        columna = N; 
        jug1 = jg1;
        jug2 = jg2;
        ntowin = Ntowin;
        Partida::inicializaPartida(jug1,jug2);
    }
    
    void Partida::save(string file){ 
       jugs.save(file);
    }
    void Partida::load(string file){ 
        jugs.load(file);
    }
    
    void Partida::ResultadosCompeticion(){
        jugs.rankingJugadores();
    }
    void Partida::CargaPartida(string savefile,int jg1,int jg2,int N,int Ntowin){
        fila = N;
        columna = N; 
        jug1 = jg1;
        jug2 = jg2;
        ntowin = Ntowin;
        Partida::inicializaPartida(jug1,jug2);
    }
    void Partida::LeeFicheroConfiguracion(string conffile){
        int jg1;
        int jg2;
        bool partidanueva = false;
        int tam = 0;
        int Ntowin = 0;
        int numjugadores=4;
        string nuevo;
        string * nombres = new string [numjugadores];
        string * apellidos = new string [numjugadores];
        string campeonato;
        string nosirve;
        ifstream fichero;
       
        fichero.open(conffile);
    if(fichero.is_open())
    {
        getline(fichero,conffile);
        for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
           fichero >> nuevo;

        for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
           fichero >> campeonato;
        for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
           fichero >> jg1;
           fichero >> jg2;
                for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
                fichero >> tam;
                
        for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
                fichero >> Ntowin;

        for(int i = 0; i < 2; i++)
        {
            fichero >> nosirve;
        }
                fichero >> numjugadores;
    }

        if(nuevo == "Si")
        {
            partidanueva = true;
        }
        if(partidanueva == true)
        {
            for(int i = 0; i < 4; i++)
            {
                
                fichero >> nombres[i];
                fichero >> apellidos[i];
            }
            Partida::NuevaPartida(campeonato,numjugadores,nombres,apellidos,jg1,jg2,tam,ntowin);
        }
        
        else{
           Partida::CargaPartida(campeonato,jg1,jg2,tam,ntowin);  
            }
        fichero.close();
}
        
 
    
    Partida::~Partida(){}