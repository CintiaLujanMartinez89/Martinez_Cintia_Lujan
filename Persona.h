#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>


class Persona{
protected:
    int DNI;
    Fecha fechaDeInscripcion;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    bool estado;


public:

    Fecha getFechaInscripcion(){
        return fechaDeInscripcion;
    }
/////////////////////////GETS//////////////////////////////
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    bool getEstado(){return estado;}
////////////////////////SETS////////////////////////////////////
    void setDNI(const int d){DNI=d;}
    void setFechaDeInscripcion(  int  diaIngresada ,int mesIngresada, int aux){
        fechaDeInscripcion.setAnio(aux);
        fechaDeInscripcion.setMes(mesIngresada);
        fechaDeInscripcion.setDia(diaIngresada);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setEstado(bool e){estado=e;}
////////////////////DECLARACION DE METODOS//////////////////////////
    bool Cargar(int);
    void Mostrar();
};




bool Persona::Cargar(int dni){

setDNI(dni);


    cout<<"NOMBRE: ";
     scanf("%s", nombre);
    cout<<"APELLIDO: ";
    scanf("%s", apellido);
    cout<<"EMAIL: ";
    scanf("%s",email);
    cout<<"TELEFONO: ";
    cin>>telefono;
    cout<<"FECHA DE INSCRIPCION: "<<endl;
    fechaDeInscripcion.Cargar();
    estado=true;

return true;
}

void Persona::Mostrar(){

    cout<<"DNI: ";
    cout<<DNI<<endl;
   cout<<"FECHA DE INSCRIPCION: "<<endl;
    fechaDeInscripcion.Mostrar();
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;




}

#endif // PERSONA_H_INCLUDED
