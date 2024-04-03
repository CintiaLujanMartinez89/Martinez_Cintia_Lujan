#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
using namespace std;
class Fecha{
    protected:
 int dia, mes, anio;
    public:

   Fecha(){
        time_t t = time(nullptr);
        tm* fS = localtime(&t);
        dia = fS->tm_mday;
        mes = fS->tm_mon + 1;
        anio = fS->tm_year + 1900;

        }
        void Cargar( );
        void Mostrar();
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

 void Fecha::Cargar( ){
int  diaIngresada ,mesIngresada,  aux;
    cout<<"DIA: ";
    cin>>diaIngresada;
    cout<<"MES: ";
    cin>>mesIngresada;
    cout<<"ANIO: ";
    cin>>aux;
    while(((aux==anio) && (mesIngresada<=mes) &&(diaIngresada>dia)) ||((aux==anio) && (mesIngresada>mes) || (aux>anio)) )
        {cout<<"INGRESE UNA FECHA VALIDA, IGUAL O MENOR A LA ACTUAL: "<<endl;
         cout<<"DIA: ";
         cin>>diaIngresada;
        cout<<"MES: ";
        cin>>mesIngresada;
        cout<<"ANIO: ";
        cin>>aux; }

    anio=aux;
    mes=mesIngresada;
    dia=diaIngresada;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
#endif // FECHA_H_INCLUDED
