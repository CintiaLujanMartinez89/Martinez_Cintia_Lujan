#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED
#include<stdio.h>
#include <iostream>
using namespace std;

class Instrumentos{
protected:

    int idInstrumento;
    char nombre[30];
   int clasificacion;
   bool estado=true;


public:
     //////////////////GETS////////////////////////////

   int  getId(){return idInstrumento;}
    const char* getNombre(){return nombre;}
   int getClasificacion(){return clasificacion;}
    bool getEstado(){return estado;}


    ///////////////////SETTERS/////////////////////////
    int setId(int id){idInstrumento=id;}
    const char* setNombre(const char *n){strcpy(nombre,n);}
    int setClasificaion(int a){clasificacion=a;}
    void setEstado(bool e){estado=e;}

    ////////////////////////////////////////
     bool Cargar(int id);
    void Mostrar();
};

bool Instrumentos::Cargar(int id){

    setId(id);//AUTONUMERICO
    cout<<"NOMBRE: ";
  cargarCadena(nombre,30);
     cout<<"CLASIFICION: ";
    cin>>clasificacion;
    estado=true;

return true;
}
void Instrumentos:: Mostrar(){

    cout<<"ID: ";
    Instrumentos obj;

    cout<<idInstrumento<<endl;
    cout<<"NOMBRE: ";
  puts(nombre);


    cout<<"CLASIFICACION: ";
    cout<<clasificacion<<endl;
    cout<<"*************************"<<endl;
 }

#endif // INSTRUMENTOS_H_INCLUDED
