#ifndef GENEROS_H_INCLUDED
#define GENEROS_H_INCLUDED

#include <iostream>
using namespace std;

class Generos{
protected:
   int idGenero;
char nombre[30];
int pais;
int anioOrigen;// Número entre 1500 y el año actual
bool estado;

public:
///////////////////////////gets////////////////////////////////
    int getId(){return idGenero;}
    const char* getNombre(){return nombre;}
    int getPais(){return pais;}
    int getAnioOrigen(){return anioOrigen;}
    bool getEstado(){return estado;}

//////////////////////////////sets////////////////////////////////

   int setId(int id){idGenero=id;}
    const char* setNombre(const char *n){strcpy(nombre,n);}
    int setPais(int p){ pais=p;}
    int setAnioOrigen(int a){anioOrigen=a;}
    void setEstado(bool e){estado=e;}


 /////////////////metodos/////////////////////
    bool Cargar(int id);
    void Mostrar();
};

bool Generos::Cargar(int id){
    Fecha obj;
bool validado=false;
    setId(id);
    cout<<"NOMBRE: ";
    scanf("%s", nombre);
    cout<<"PAIS DE ORIGEN(NúMERO ENTRE 1 Y 100): ";
    /////////////////////////TIENE QUE BUSCAR EN LOS ID DE PAISES EXISTENTES EN EL PROGRAMA/////////
        cin>>pais;
    validado= validarPais(pais);

        if(validado==false){
            return false;
        }



    cout<<"AÑO DE ORIGEN(AÑO ENTRE 1500 Y EL AñO ACTUAL): ";
    cin>>anioOrigen;

     while((anioOrigen<1500) || (anioOrigen>obj.getAnio())){
              cout<<"****INGRESE UN AÑO VALIDO (AÑO ENTRE 1500 Y EL AñO ACTUAL):"<<endl;
               cin>>anioOrigen;
        }
    estado=true;

return true;
}

 void Generos:: Mostrar(){

    cout<<"ID: ";
    cout<<idGenero<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"PAIS DE ORIGEN: ";
    cout<<pais<<endl;
    cout<<"AÑO DE ORIGEN:(NúMERO ENTRE 1500 Y EL AñO ACTUAL): ";
    cout<<anioOrigen<<endl;
    cout<<"*************************"<<endl;
 }
#endif // GENEROS_H_INCLUDED
