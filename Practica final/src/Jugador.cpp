#include "Jugador.h"
#include <iostream>
using namespace std;
Jugador::Jugador() {
}

Jugador::Jugador(const Jugador& orig) {
   id = orig.id;
   nombre = orig.nombre;
   apellidos = orig.apellidos;
}

Jugador::~Jugador() {
}

string Jugador::getApellidos(){
    return this->apellidos;
}
string Jugador::getNombre(){
    return nombre;
}
int Jugador::getPartidasGanadas() const{
    return partidasganadas;
}
int Jugador::getId(){
    return id;
}
string & Jugador::putNombre(){
   return nombre;
}
string & Jugador::putApellidos(){
    return apellidos;
}
int Jugador::partidaGanada(){
    partidasjugadas++;
    partidasganadas++;
    return partidasganadas;
}

int Jugador::partidaJugada(){
    partidasjugadas++;
    return partidasjugadas;
}

Jugador::Jugador(int newid, string newnombre, string newapellidos){
    nombre = newnombre;
    id = newid;
    apellidos = newapellidos;
}

int & Jugador::setId(){
    id=id+1;
    return id;
}
int Jugador::getPartidasJugadas()const{
    return partidasjugadas;
}
Jugador & Jugador::operator=(const Jugador & orig){
    apellidos = orig.apellidos;
    nombre = orig.nombre;
    id = orig.id;
    partidasganadas = orig.partidasganadas;
    partidasjugadas = orig.partidasjugadas;
}

 bool operator==( const Jugador & izq, const Jugador & dch){
     bool correcto = false;
     if(izq.getPartidasGanadas() == dch.getPartidasGanadas())
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return correcto;
     }
 }
 bool operator!=( const Jugador & izq, const  Jugador & dch){
     bool correcto = false;
     if(izq.getPartidasGanadas() != dch.getPartidasGanadas())
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return correcto;
     }
 }
 bool operator<( const Jugador &izq, const Jugador & dch){
     bool correcto = false;
     if(izq.getPartidasGanadas() < dch.getPartidasGanadas())
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return correcto;
     }
 }
 bool operator>( const Jugador &izq, const Jugador & dch){
     bool correcto = false;
     if(izq.getPartidasGanadas()>dch.getPartidasGanadas())         
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return correcto;
     }
 }
 bool operator<=( const Jugador &izq,  const Jugador & dch){
     bool correcto = false;    
     if(izq.getPartidasGanadas()<=dch.getPartidasGanadas())                   
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return correcto;
     }
 }
 bool operator>=( const Jugador &izq, const Jugador & dch){
     bool correcto = false;
     if(izq.getPartidasGanadas()>=dch.getPartidasGanadas())
     {
         correcto = true;
         return correcto;
     }
     else
     {
         return false;
     }
 }
 
 std::ostream & operator << (std::ostream & flujo, const  Jugador & jug){
     flujo << jug.id << " ";
     flujo << jug.nombre << " ";
     flujo << jug.apellidos << " ";
     flujo << jug.partidasganadas << " ";
     
     return flujo; 
 }