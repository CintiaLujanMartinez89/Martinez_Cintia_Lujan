#ifndef ARCHIVOSPAISES_H_INCLUDED
#define ARCHIVOSPAISES_H_INCLUDED

#include <iostream>
using namespace std;

class ArchivoPaises:public Paises{
   protected:
        char nombre[30];

    public:

     ArchivoPaises(const char *n){
            strcpy(nombre, n);}
bool bajaLogica();
int asignarId();
void agregarPaises();
void mostrarPorId();
Paises leerPaises(int id);
bool modificarPaises(Paises obj, int pos);
bool modificarNombre();
int buscarPaises(int id);
void mostrarRegistros();
};


int ArchivoPaises::asignarId(){//busca el ultimo id y le suma 1
    Paises obj;
    int idNuevo=1;
    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
     cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    }
    while(fread(&obj, sizeof obj, 1, pPais)==1){

     idNuevo=obj.getId()+1;}

   fclose(pPais);

    return idNuevo;
}
bool ArchivoPaises::modificarNombre(){//pido id a borrar,lo busco, si lo encuentro
                                    //pido ingresar el nombre nuevo y lo modifico
 Paises obj;
    int ID;
    cout<<"INGRESE EL ID DEL PAIS A MODIFICAR: ";
    cin>>ID;

    int pos = buscarPaises(ID);//BUSCO LA POSICION DEL OBJETO SI EXISTE O NO

    if(pos==-1){
        cout<<"NO EXISTE PAIS CON ESE ID"<<endl;
        return false ;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerPaises(pos);
    if(obj.getEstado()==false){
        cout<<"EL PAIS INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }

    char nom[30];

    cout<<"INGRESE EL NUEVO NOMBRE: ";
      scanf(" %s",nom);
    obj.setNombre(nom);

    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarPaises(obj, pos);

      return aux;
}


int ArchivoPaises::buscarPaises(int id){//recibo el id, abro archivo, busco el id q recibi y lo devuelvo
                                        //la posicion si lo encuentro
  Paises obj;
    int pos=0;

    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){return -2;}

    while(fread(&obj, sizeof obj, 1, pPais)==1){
        if(obj.getId() == id){ ;
            fclose(pPais);
            return pos;
        }
      pos++;
    }
	fclose(pPais);

	return -1;
}
bool ArchivoPaises::modificarPaises(Paises obj, int pos){//recibo en obj paises, y la posicion donde
                                                        //lo tengo que grabar, posiciono con el fseek
                                                        //y grabo con fwrite
    FILE *pPais;
    pPais = fopen(nombre, "rb+");
    fseek(pPais, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pPais);
    fclose(pPais);
    return aux;
}


void ArchivoPaises::agregarPaises(){
    cout<<"*******AGREGAR PAISES*******"<<endl;
    Paises obj;
    int id;
    FILE *pPais;

    pPais=fopen(nombre, "ab");  //ab escribe al final
       if(pPais==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;    }

    id=asignarId();
    obj.Cargar(id);  //cargo obj
	fwrite(&obj, sizeof (Paises), 1, pPais);//escribo obj
	fclose(pPais);
}
void ArchivoPaises::mostrarPorId(){
Paises obj;
    int id;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>id;
    int pos=buscarPaises(id);

    obj=leerPaises(pos);

    if(obj.getId()==id){
        obj.Mostrar();
   }else{cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;}
}
Paises ArchivoPaises::leerPaises(int id){
  Paises obj;

    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
     cout<<"NO SE PUDO LEER POR GENERO"<<endl;
        return obj;}

    fseek(pPais, sizeof obj * id, 0);
    int aux=fread(&obj, sizeof obj, 1, pPais);

    fclose(pPais);
    if(aux==0){obj.setId(-1);}

    return obj;
}


void ArchivoPaises::mostrarRegistros(){
    cout<<"*******PAISES********"<<endl;
Paises obj;
    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pPais)==1){
        if(obj.getEstado()){
            obj.Mostrar();}
             cout<<endl;}

	fclose(pPais);
}
bool ArchivoPaises::bajaLogica(){
   cout<<"*******ELIMINAR PAIS*******"<<endl;
   Paises obj;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    //BUSCAMOS EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarPaises(id);
    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerPaises(pos);
   if(obj.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
   bool aux = modificarPaises(obj, pos);
    return aux;
}

#endif // ARCHIVOSPAISES_H_INCLUDED
