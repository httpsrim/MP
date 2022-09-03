/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conjuntoJugadores.cpp
 * Author: Usuario
 * 
 * Created on 8 de febrero de 2022, 12:07
 */

#include "ConjuntoJugadores.h"
#include "Jugador.h"
#include <iostream>
#include <map>
using namespace std;
ConjuntoJugadores::ConjuntoJugadores(int k) {
    tamreservado = k;
    vectorJugadores = new Jugador[k];
    numjugadores=0;
}

ConjuntoJugadores & ConjuntoJugadores::operator=(const ConjuntoJugadores & orig){
    numjugadores = orig.numjugadores;
    tamreservado = orig.tamreservado;
    vectorJugadores =  new Jugador [orig.tamreservado];
    for(int i = 0; i < orig.numjugadores ; i++)
        vectorJugadores[i] = orig.vectorJugadores[i];
    return * this;
    }

ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig) {
   numjugadores = orig.numjugadores;
   tamreservado= orig.tamreservado;
   vectorJugadores = orig.vectorJugadores;
}

ConjuntoJugadores::~ConjuntoJugadores() {
    delete [] vectorJugadores;
}

ConjuntoJugadores::ConjuntoJugadores(int n, string *nombres, string * apellidos){
    for(int i = 0;i < tamreservado ; i++)
    {
       nombres[i]=vectorJugadores[i].getNombre(); 
       apellidos[i]=vectorJugadores[i].getApellidos();
       n = vectorJugadores[i].getId();
    }
}

string ConjuntoJugadores::rankingJugadores(){   
    int vector[tamreservado];
    int posicion[tamreservado];
    
    int aux;
    string ranking = " ";
    for (int i = 0; i < numjugadores; i++){
        vector[i] = (float(vectorJugadores[i].getPartidasGanadas()) / vectorJugadores[i].getPartidasJugadas());
        posicion[i] = i;
    }
   
    for(int i = 0; i < numjugadores; i++){    
        for(int j = i + 1; j <= numjugadores; j++){
            if(vector[i] < vector[j]){
                aux = posicion[i];
                posicion[i] = posicion[j];
                posicion[j] = aux;
            }
        }
    }
   
    for(int i = 0; i< numjugadores; i++){
        ranking = ranking +to_string(vectorJugadores[posicion[i]].getId()) + " ";
        ranking = ranking + vectorJugadores[posicion[i]].getNombre() + " ";
        ranking = ranking + vectorJugadores[posicion[i]].getApellidos() + " ";
        ranking = ranking + "\n";
    }
return ranking;
}

  std::ostream & operator<< (std::ostream & flujo, const ConjuntoJugadores & conjug){ 
      for(int i = 0; i < conjug.numjugadores ; i++)
        flujo <<conjug.vectorJugadores[i] << '\n';
  }
  
 int ConjuntoJugadores::numerojugadores(){
      return numjugadores;
  }
    ConjuntoJugadores & ConjuntoJugadores::operator+=(const Jugador& newjug){
        if(numjugadores < tamreservado)
        {
         
         vectorJugadores[numjugadores++] = newjug;
         numjugadores++;
        }
        
        else{
           resize(tamreservado++);
           vectorJugadores[numjugadores++] = newjug;
            numjugadores++;
        }
        
    }
    
void ConjuntoJugadores::eliminaJugador(int jugid){
        ConjuntoJugadores copy(tamreservado--);                                 
        for(int i = 0; i< tamreservado;i++)
        {
           if(i != jugid)
            {
               copy[i]=vectorJugadores[i];
            }
        }
        tamreservado--;
        numjugadores--;
    }
    
int ConjuntoJugadores::buscaJugador(int jugid){
        for(int i = 0 ; i < numjugadores ; i++)
        {
            if(i == jugid)
            {
                return i;                                                       //se devuelve i porque es == que la id
            }
        }
    }

int ConjuntoJugadores::buscaJugador(string nombre){
        for(int i = 0 ; i < numjugadores ; i++)
        {
            if(vectorJugadores[i].getNombre() == nombre)
            {
                return vectorJugadores[i].getId();                                      //devolver i como si fuera la id
            }
        }
    }

void ConjuntoJugadores::optimizar(){     
        tamreservado = numjugadores;
    }
    Jugador & ConjuntoJugadores::operator[](int i) const{
        return this->vectorJugadores[i];
    }
    void ConjuntoJugadores::ordenaporId(){
       ConjuntoJugadores copy(numjugadores);                                   
        for(int i = 0 ; i < tamreservado ; i++)
        {
            for(int j = 1; i <= numjugadores ; j++)
            if(vectorJugadores[j].getId() == j)                              
            {
                copy[i] = vectorJugadores[j];
            }
        }
    }

void ConjuntoJugadores::resize(int newtam){
        ConjuntoJugadores copy(newtam);                                        
        for(int i = 0; i < tamreservado; i++)
        {
            copy[i]=vectorJugadores[i];
        }
       
        for(int i = 0 ; i < newtam; i++)
        {
            vectorJugadores[i] = copy[i];
        }
        tamreservado = newtam;
    }
  
ConjuntoJugadores operator+( const ConjuntoJugadores & left, const ConjuntoJugadores & right){
    ConjuntoJugadores copy (left.numjugadores + right.numjugadores);
    copy.tamreservado = (left.tamreservado + right.tamreservado);
    copy.numjugadores = (left.numjugadores + right.numjugadores);
        int i=0;
        for(i = 0 ; i < left.numjugadores; i++)
        {
                copy[i]=left[i];
        }
        for(int j = 0;j < right.numjugadores;j++)
        {
            copy[i]=right[j];
            i++;
        }
        return copy;
    }