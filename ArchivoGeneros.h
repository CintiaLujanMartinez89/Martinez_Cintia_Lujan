#ifndef ARCHIVOGENEROS_H_INCLUDED
#define ARCHIVOGENEROS_H_INCLUDED

#include <iostream>
using namespace std;

class ArchivoGeneros: public Generos{
protected:
 char nombre[30];

public:
  ArchivoGeneros(const char *n){
            strcpy(nombre, n);}

        void agregarRegistro();
        int buscarGenero(int i);
        Generos leerGenero(int g);
        bool bajaLogica();
        bool modificarAnioOrigen();
        void buscarPorId();
        bool modificarRegistro(Generos obj, int p);
        void mostrarRegistros();
        int asignarId();

};

void ArchivoGeneros::agregarRegistro(){
    cout<<"*******AGREGAR REGISTROS*******"<<endl;
    Generos obj;
    int id;
    FILE *pGen;

    pGen=fopen(nombre, "ab");
       if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;    }

    id=asignarId();
    obj.Cargar(id);
	fwrite(&obj, sizeof (Generos), 1, pGen);
	fclose(pGen);
}





bool ArchivoGeneros::bajaLogica(){
   cout<<"*******ELIMINAR REGISTRO*******"<<endl;
    Generos obj;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    //BUSCAMOS EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarGenero(id);
    if(pos==-1){
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerGenero(pos);
   if(obj.getEstado()==false){
        cout<<"EL GENERO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
   bool aux = modificarRegistro(obj, pos);
    return aux;
}

Generos ArchivoGeneros::leerGenero(int id){
    Generos obj;

    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
     cout<<"NO SE PUDO LEER POR GENERO"<<endl;
        return obj;}

    fseek(pGen, sizeof obj * id, 0);
    int aux=fread(&obj, sizeof obj, 1, pGen);

    fclose(pGen);
    if(aux==0){obj.setId(-1);}

    return obj;
}

int ArchivoGeneros::buscarGenero(int id){
   Generos obj;
    int pos=0;

    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){return -2;}

    while(fread(&obj, sizeof obj, 1, pGen)==1){
        if(obj.getId() == id){ ;
            fclose(pGen);
            return pos;
        }
      pos++;
    }
	fclose(pGen);

	return -1;
}

void ArchivoGeneros::mostrarRegistros(){
    cout<<"*******GENEROS********"<<endl;
   Generos obj;
    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pGen)==1){
        if(obj.getEstado()){
            obj.Mostrar();}
             cout<<endl;}

	fclose(pGen);
}

bool ArchivoGeneros::modificarAnioOrigen(){
    //SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR
    Generos obj;
    int id;
    cout<<"INGRESE EL ID DEL GENERO A MODIFICAR: ";
    cin>>id;
    //BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarGenero(id);
    if(pos==-1){
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerGenero(pos);
    if(obj.getEstado()==false){
        cout<<"EL GENERO INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS EL CAMPO ANIO DE ORIGEN
   int nuevoAnio;
    cout<<"INGRESE EL NUEVO AÑO DE ORIGEN: ";
    cin>>nuevoAnio;
    obj.setAnioOrigen(nuevoAnio);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

bool ArchivoGeneros::modificarRegistro(Generos obj, int pos){
    FILE *pGen;
    pGen = fopen(nombre, "rb+");
    fseek(pGen, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pGen);
    fclose(pGen);
    return aux;
}

void ArchivoGeneros::buscarPorId(){
   Generos obj;
    int id;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>id;
    int pos=buscarGenero(id);

    obj=leerGenero(pos);

    if(obj.getId()==id){
        obj.Mostrar();
   }else{cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;}
}

int ArchivoGeneros::asignarId(){//busca el ultimo id y le suma 1
    Generos obj;
    int idNuevo=1;
    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
     cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    }
    obj=leerGenero(1);
    while(fread(&obj, sizeof obj, 1, pGen)==1){

     idNuevo=obj.getId()+1;}


   fclose(pGen);

    return idNuevo;
}

#endif // ARCHIVOGENEROS_H_INCLUDED
