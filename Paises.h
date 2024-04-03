#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

#include <iostream>
using namespace std;

class Paises{
private:
    int idPais;
    char nombre[30];
    char continente [30];
    bool estado=true;



public:
///////////////////////////gets////////////////////////////////
    int getId(){return idPais;}
    const char* getNombre(){return nombre;}
    const char* getContinente(){return continente;}
    bool getEstado(){return estado;}

//////////////////////////////sets////////////////////////////////

   int setId(int id){idPais=id;}
    const char* setNombre(const char *n){strcpy(nombre,n);}
    const char* setContinente(const char *n){strcpy(continente,n);}
       void setEstado(bool e){estado=e;}


 /////////////////metodos/////////////////////
    bool Cargar(int id);
    void Mostrar();
};

bool Paises::Cargar(int id){
    Paises obj;

    setId(id);//AUTONUMERICO

    cout<<"NOMBRE: ";
   cargarCadena(nombre,30);

    cout<<"CONTINENTE: ";
  cargarCadena(continente,30);
    estado=true;

return true;
}

 void Paises:: Mostrar(){

    cout<<"ID: ";
    cout<<idPais<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"CONTINENTE: ";
    cout<<continente<<endl;
    cout<<"*************************"<<endl;
 }

#endif // PAISES_H_INCLUDED
